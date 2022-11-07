#version 420

in vec4 fColor;		// color;			
in vec4 fNormal;
in vec4 fVertWorldLocation;	// using only matModel
in vec2 fTextureUV;


out vec4 pixelOutputColor;

struct sLight
{
	vec4 position;			
	vec4 diffuse;	
	vec4 specular;	    // rgb = highlight colour, w = power
	vec4 attenuation;	// x = constant, y = linear, z = quadratic, w = DistanceCutOff
	vec4 direction;	    // Spot, directional lights
	vec4 param1;	    // x = lightType, y = inner angle, z = outer angle, w = TBD
	                    // 0 = pointlight
					    // 1 = spot light
					    // 2 = directional light
	vec4 param2;	    // x = 0 for off, 1 for on
};

uniform vec4 eyeLocation;
uniform vec4 RGBA_Color;
uniform sLight Light;

uniform vec4 specularColour;			// RGB object hightlight COLOUR
										// For most material, this is white (1,1,1)
										// For metals google "metal specular hightlight colour"
										// For plastic, it's the same colour as the diffuse
										// W value is the "specular power" or "Shininess" 
										// Starts at 1, and goes to 10,000s
										//	1 = not shiny 
										// 10 = "meh" shiny

void main()
{
	vec4 finalObjectColour = vec4( 0.0f, 0.0f, 0.0f, 1.0f );
	
    vec3 materialColor = fColor.rgb;
    //materialColour = RGBA_Color.rgb/0xff;
    
    vec3 ambient = 0.4 * materialColor;
    
    vec3 normal = normalize(fNormal.xyz);
	int LightType = int(Light.param1.x);
	
	if( LightType == 2)
	{
		vec3 lightContrib = Light.diffuse.rgb;
		float dotProd = dot(-Light.direction.xyz, normalize(normal.xyz));
		dotProd = max( 0.0f, dotProd);
		lightContrib *= dotProd;
		finalObjectColour.rgb += (materialColor.rgb * Light.diffuse.rgb * lightContrib);
	}
	
	vec3 vLightToVertex = Light.position.xyz - fVertWorldLocation.xyz;
	float distanceToLight = length(vLightToVertex);
	vec3 lightVector = normalize(vLightToVertex);
	float dotProduct = dot(lightVector, fNormal.xyz);
	dotProduct = max( 0.0f, dotProduct );
	vec3 lightDiffuseContrib = dotProduct * Light.diffuse.rgb;
	
	vec3 lightSpecularContrib = vec3(0.0f);
	vec3 reflectVector = reflect( -lightVector, normalize(normal.xyz) );
	
	vec3 eyeVector = normalize(eyeLocation.xyz - fVertWorldLocation.xyz);
	float objectSpecularPower = specularColour.w;
	lightSpecularContrib = pow( max(0.0f, dot( eyeVector, reflectVector) ), objectSpecularPower ) * (specularColour.rgb * Light.specular.rgb);
	
	float atten = 1.0f /( Light.attenuation.x + Light.attenuation.y * distanceToLight +	Light.attenuation.z * distanceToLight*distanceToLight );  
    
	lightDiffuseContrib *= atten;
	lightSpecularContrib *= atten;
	
	if(LightType == 1)
	{
		vec3 vertexToLight = normalize(fVertWorldLocation.xyz - Light.position.xyz);
		
		float currentLightRayAngle = dot( vertexToLight.xyz, Light.direction.xyz );
		
		currentLightRayAngle = max(0.0f, currentLightRayAngle);
		float outerConeAngleCos = cos(radians(Light.param1.z));
		float innerConeAngleCos = cos(radians(Light.param1.y));
		
		if ( currentLightRayAngle < outerConeAngleCos )
		{
			// Nope. so it's in the dark
			lightDiffuseContrib = vec3(0.0f, 0.0f, 0.0f);
			lightSpecularContrib = vec3(0.0f, 0.0f, 0.0f);
		}
		else if ( currentLightRayAngle < innerConeAngleCos )
		{

			float penumbraRatio = (currentLightRayAngle - outerConeAngleCos) / 
								  (innerConeAngleCos - outerConeAngleCos);
								  
			lightDiffuseContrib *= penumbraRatio;
			lightSpecularContrib *= penumbraRatio;
		}		
	}
	
	finalObjectColour.rgb += (materialColor.rgb * lightDiffuseContrib.rgb) + (specularColour.rgb  * lightSpecularContrib.rgb );
	
	pixelOutputColor = vec4(finalObjectColour.rgb , 1.0);
	pixelOutputColor.rgb += ambient;
}