#version 420

uniform mat4 MVP;
//in vec3 vCol; // vertex color
//in vec3 vPos; // vertex position

in vec4 vColour;			// Was vec3
in vec3 vPosition;			// Was vec3
in vec3 vNormal;			// Vertex normal

// Going "out" to the fragment shader
out vec4 fColour;		// colour;			
out vec4 fNormal;
//out vec4 fVertWorldLocation;	// using only matModel

//uniform
uniform mat4 mModel;
uniform mat4 mModelInverseTranspose;		// mModel with Only Rotation;
uniform mat4 mView;
uniform mat4 mProjection;

void main()
{
    //mat4 mMVP = mProjection * mView * mModel;

    gl_Position = MVP * vec4(vPosition, 1.0); 

    fNormal.xyz = normalize(mModelInverseTranspose * vec4(vNormal.xyz, 1.0f)).xyz;
	fNormal.w = 1.0f;

    fColour = vColour;

}