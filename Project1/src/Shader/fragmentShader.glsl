#version 420

in vec4 fColour;		// colour;			
in vec4 fNormal;
in vec4 fVertWorldLocation;	// using only matModel

out vec4 pixelOutputColour;

uniform vec4 RGBA_Colour;

void main()
{
    vec3 materialColour = fColour.rgb;
    //materialColour = RGBA_Colour.rgb;

    pixelOutputColour = vec4(materialColour.rgb, 1.0f);
    //gl_FragColor = vec4(0.5f,0.9f,0.1f, 1.0f);
    
}