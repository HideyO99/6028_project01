#version 420

layout (location = 0) in vec3 vPosition ;
layout (location = 1) in vec3 vNormal ;		
layout (location = 2) in vec4 vColour ;			

// Going "out" to the fragment shader
out vec4 fColour;		
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
    vec3 vertNormal = vNormal.xyz;
    mat4 mMVP = mProjection * mView * mModel;

    gl_Position = mMVP * vec4(vertPosition, 1.0); 

    fVertWorldLocation.xyz = (mModel * vec4(vertPosition, 1.0f)).xyz;
	fVertWorldLocation.w = 1.0f;

    fNormal.xyz = normalize(mModelInverseTranspose * vec4(vertNormal, 1.0f)).xyz;
	fNormal.w = 1.0f;

    fColour = vec4(vColour.rgb/0xff,1.0f);

}