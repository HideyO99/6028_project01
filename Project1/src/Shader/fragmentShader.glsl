#version 420

in vec4 fColor;		// color;			
in vec4 fNormal;
in vec4 fVertWorldLocation;	// using only matModel
in vec2 fTextureUV;

#define MAX_LIGHT_SOURCE 5
out vec4 pixelOutputColor;


struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 

struct DirLight {
    vec4 direction;
    float ambient;
    vec4 diffuse;
    vec4 specular;
	int turnON;
};

struct PointLight {
    vec4 position;
    
    float constant;
    float linear;
    float quadratic;
	
    float ambient;
    vec4 diffuse;
    vec4 specular;
	int turnON;
};

struct SpotLight {
    vec4 position;
    vec4 direction;
    float innerAngle;
    float outerAngle;
  
    float constant;
    float linear;
    float quadratic;
  
    float ambient;
    vec4 diffuse;
    vec4 specular; 
	int turnON;	
};

uniform DirLight dirLight;
uniform PointLight pointLights[MAX_LIGHT_SOURCE];
uniform SpotLight spotLight[MAX_LIGHT_SOURCE];
uniform Material material;

uniform vec4 eyeLocation;
uniform vec4 RGBA_Color;
uniform bool bDoNotLight;
//uniform sLight Light[MAX_LIGHT_SOURCE];

//uniform vec4 specularColor;			// RGB object hightlight COLOUR
										// For most material, this is white (1,1,1)
										// For metals google "metal specular hightlight colour"
										// For plastic, it's the same colour as the diffuse
										// W value is the "specular power" or "Shininess" 
										// Starts at 1, and goes to 10,000s
										//	1 = not shiny 
										// 10 = "meh" shiny

vec3 calDirectionalLight(DirLight light,vec3 normal,vec3 viewDirection);
vec3 calPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDirection);

void main()
{
	vec3 finalObjectColour = vec3( 0.0f, 0.0f, 0.0f);
	
    vec3 materialColor = fColor.rgb;
    materialColor = RGBA_Color.rgb;
    
    //vec3 ambient = 0.6 * materialColor;
    if ( bDoNotLight )
	{
		// Set the output colour and exit early
		// (Don't apply the lighting to this)
		pixelOutputColor = vec4(materialColor.rgb, 1);
		return;
	}
    vec3 normal = normalize(fNormal.xyz);
	vec3 eyeVector = normalize(eyeLocation.xyz - fVertWorldLocation.xyz);
	//Directional Light
	finalObjectColour = calDirectionalLight(dirLight, normal, eyeVector);
	//Point Light
	for(int i = 0; i < MAX_LIGHT_SOURCE; i++)
	{
		finalObjectColour += calPointLight(pointLights[i], normal, fVertWorldLocation.xyz, eyeVector);
	
		//Spot Light
		finalObjectColour += calSpotLight(spotLight[i],normal,fVertWorldLocation.xyz, eyeVector);
	}
	pixelOutputColor = vec4(finalObjectColour, 1.0);
}

vec3 calDirectionalLight(DirLight light, vec3 normal, vec3 viewDirection)
{
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, fTextureUV));
	if(light.turnON == 0)
	{
		return ambient ;
	}
	vec3 lightDirection = normalize(-light.direction.xyz);
	
	//diffuse shading
	float diff = max(dot(normal, lightDirection), 0.0);
	
	//specular shading
	vec3 halfwayDir = normalize(lightDirection + viewDirection);
	float spec = pow(max(dot(viewDirection, halfwayDir), 0.0), material.shininess);
	//vec3 reflectDirection = reflect(-lightDirection, normal);
	//float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
	
	
	vec3 diffuse = light.diffuse.xyz * diff * vec3(texture(material.diffuse, fTextureUV));
	vec3 specular = light.specular.rgb * spec * vec3(texture(material.diffuse, fTextureUV));
	
	return(ambient + diffuse + specular);
}

vec3 calPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDirection)
{
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, fTextureUV));
	if(light.turnON == 0)
	{
		return ambient ;
	}
	vec3 lightDirection = normalize(light.position.xyz - fragPos);
	
	// diffuse shading
	float diff = max(dot(normal, lightDirection), 0.0);
	
	// specular shading
	vec3 halfwayDir = normalize(lightDirection + viewDirection);
	float spec = pow(max(dot(viewDirection, halfwayDir), 0.0), material.shininess);
	//vec3 reflectDirection = reflect(-lightDirection, normal);
	//float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
	
	// attenuation
	float distance = length(light.position.xyz - fragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	// combine results
	//vec3 ambient = light.ambient * vec3(texture(material.diffuse, fTextureUV));
	vec3 diffuse = light.diffuse.xyz * diff * vec3(texture(material.diffuse, fTextureUV));
	vec3 specular = light.specular.rgb * spec * vec3(texture(material.specular, fTextureUV));
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	return (ambient + diffuse + specular);
}

vec3 calSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDirection)
{
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, fTextureUV));
	if(light.turnON == 0)
	{
		return ambient ;
	}
    vec3 lightDirection = normalize(light.position.xyz - fragPos);
	
    // diffuse shading
    float diff = max(dot(normal, lightDirection), 0.0);
	
    // specular shading
	vec3 halfwayDir = normalize(lightDirection + viewDirection);
	float spec = pow(max(dot(viewDirection, halfwayDir), 0.0), material.shininess);
	//vec3 reflectDirection = reflect(-lightDirection, normal);
	//float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), material.shininess);
	
    // attenuation
    float distance = length(light.position.xyz - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    
    // spotlight intensity
    float currentLightRayAngle = dot(lightDirection, normalize(-light.direction.xyz)); 
	currentLightRayAngle = max(0.0f, currentLightRayAngle);
	float outerConeAngleCos = cos(radians(light.outerAngle));
	float innerConeAngleCos = cos(radians(light.innerAngle));
	float intensity = 1;
	if ( currentLightRayAngle < outerConeAngleCos )
	{
		intensity = 0;
	}
	else if ( currentLightRayAngle < innerConeAngleCos )
	{
		intensity = (currentLightRayAngle - outerConeAngleCos) / 
					(innerConeAngleCos - outerConeAngleCos);
	}
	
    // combine results
    //vec3 ambient = light.ambient * vec3(texture(material.diffuse, fTextureUV));
    vec3 diffuse = light.diffuse.xyz * diff * vec3(texture(material.diffuse, fTextureUV));
    vec3 specular = light.specular.rgb * spec * vec3(texture(material.specular, fTextureUV));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
	
    return (ambient + diffuse + specular);
}
	