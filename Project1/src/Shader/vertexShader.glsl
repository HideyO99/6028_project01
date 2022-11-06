#version 420

//uniform mat4 MVP;
//in vec3 vCol; // vertex color
//in vec3 vPos; // vertex position


layout(location = 0) in vec3 vPosition ;			// Was vec3
layout(location = 1) in vec3 vNormal ;			// Vertex normal
layout(location = 2) in vec4 vColour ;			// Was vec3

// Going "out" to the fragment shader
out vec4 fColour;		// colour;			
out vec4 fNormal;
out vec4 fVertWorldLocation;	// using only matModel

//uniform
uniform mat4 mModel;
uniform mat4 mModelInverseTranspose;		// mModel with Only Rotation;
uniform mat4 mView;
uniform mat4 mProjection;

void main()
{
    vec3 vertPosition = vPosition.xyz;
    mat4 mMVP = mProjection * mView * mModel;

    gl_Position = mMVP * vec4(vertPosition, 1.0); 

    fVertWorldLocation.xyz = (mModel * vec4(vertPosition, 1.0f)).xyz;
	fVertWorldLocation.w = 1.0f;

    fNormal.xyz = normalize(mModelInverseTranspose * vec4(vNormal.xyz, 1.0f)).xyz;
	fNormal.w = 1.0f;

    fColour = vec4(vColour.rgb/0xff,1.0f);

}