#version 420

in vec4 fColour;		// colour;			
in vec4 fNormal;
in vec4 fVertWorldLocation;	// using only matModel

out vec4 pixelOutputColour;

void main()
{
    pixelOutputColour = fColour;
    
}