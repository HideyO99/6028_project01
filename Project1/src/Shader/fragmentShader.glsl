#version 420

in vec4 fColour;		// colour;			
in vec4 fNormal;
in vec4 fVertWorldLocation;	// using only matModel
in vec4 fUVx2;
in vec4 fTangent;
in vec4 fBinormal;

out vec4 pixelOutputColour;

void main()
{
    pixelOutputColour = fColour;
    
}