#version 420

uniform mat4 MVP;
//in vec3 vCol; // vertex color
//in vec3 vPos; // vertex position

in vec4 vColour;			// Was vec3
in vec4 vPosition;			// Was vec3
in vec4 vNormal;			// Vertex normal
in vec4 vUVx2;				// 2 x Texture coords
in vec4 vTangent;			// For bump mapping
in vec4 vBiNormal;			// For bump mapping
in vec4 vBoneID;			// For skinned mesh (FBX)
in vec4 vBoneWeight;		// For skinned mesh (FBX)

// Going "out" to the fragment shader
out vec4 fColour;		// colour;			
out vec4 fNormal;
//out vec4 fVertWorldLocation;	// using only matModel
out vec4 fUVx2;
out vec4 fTangent;
out vec4 fBinormal;

//uniform
uniform mat4 mModel;
uniform mat4 mModelInverseTranspose;		// mModel with Only Rotation;
uniform mat4 mView;
uniform mat4 mProjection;

void main()
{
    vec3 vertexPosition = vPosition.xyz;
    //mat4 mMVP = mProjection * mView * mModel;

    gl_Position = MVP * vec4(vertexPosition, 1.0); 
    
    //lighting

    fNormal.xyz = normalize(mModelInverseTranspose * vec4(vNormal.xyz, 1.0f)).xyz;
	fNormal.w = 1.0f;

    fColour = vColour;
    fUVx2 = vUVx2;
    fTangent = vTangent;
    fBinormal = vBiNormal;
}