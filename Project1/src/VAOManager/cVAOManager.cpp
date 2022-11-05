#include "cVAOManager.h"

cVAOManager::cVAOManager()
{
}

cVAOManager::~cVAOManager()
{
}

bool cVAOManager::loadModelToVAO(std::string filename, cModelDrawInfo& drawInfo, unsigned int shaderProgramID)
{
	drawInfo.meshName = filename;

	drawInfo.CalculateExtents();

	glGenVertexArrays(1, &(drawInfo.VAO_ID));
	glBindVertexArray(drawInfo.VAO_ID);
	
	//vertices
	glGenBuffers(1, &(drawInfo.VertexBufferID));
	glBindBuffer(GL_ARRAY_BUFFER, drawInfo.VertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones) * drawInfo.numberOfVertices, (GLvoid*)drawInfo.pVertices, GL_STATIC_DRAW);

	//indices
	glGenBuffers(1, &(drawInfo.IndexBufferID));
	glBindBuffer(GL_ELEMENT_ARRAY_BARRIER_BIT, drawInfo.IndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BARRIER_BIT, sizeof(unsigned int) * drawInfo.numberOfIndices, (GLvoid*)drawInfo.pIndices, GL_STATIC_DRAW);


	GLint vColour_location = glGetAttribLocation(shaderProgramID, "vColour");
	glEnableVertexAttribArray(vColour_location);
	glVertexAttribPointer(vColour_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, r));		// Offset the member variable

	//in vec4 vPosition;			
	GLint vPosition_location = glGetAttribLocation(shaderProgramID, "vPosition");
	glEnableVertexAttribArray(vPosition_location);
	glVertexAttribPointer(vPosition_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, x));		// Offset the member variable

	//in vec4 vNormal;			
	GLint vNormal_location = glGetAttribLocation(shaderProgramID, "vNormal");
	glEnableVertexAttribArray(vNormal_location);
	glVertexAttribPointer(vNormal_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, nx));		// Offset the member variable

	//in vec4 vUVx2;			
	GLint vUVx2_location = glGetAttribLocation(shaderProgramID, "vUVx2");
	glEnableVertexAttribArray(vUVx2_location);
	glVertexAttribPointer(vUVx2_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, u0));		// Offset the member variable

	//in vec4 vTangent;			
	GLint vTangent_location = glGetAttribLocation(shaderProgramID, "vTangent");
	glEnableVertexAttribArray(vTangent_location);
	glVertexAttribPointer(vTangent_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, tx));		// Offset the member variable

	//in vec4 vBiNormal;		
	GLint vBiNormal_location = glGetAttribLocation(shaderProgramID, "vBiNormal");
	glEnableVertexAttribArray(vBiNormal_location);
	glVertexAttribPointer(vBiNormal_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, bx));		// Offset the member variable

	//in vec4 vBoneID;			
	GLint vBoneID_location = glGetAttribLocation(shaderProgramID, "vBoneID");
	glEnableVertexAttribArray(vBoneID_location);
	glVertexAttribPointer(vBoneID_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, vBoneID[0]));		// Offset the member variable

	//in vec4 vBoneWeight;		
	GLint vBoneWeight_location = glGetAttribLocation(shaderProgramID, "vBoneWeight");
	glEnableVertexAttribArray(vBoneWeight_location);
	glVertexAttribPointer(vBoneWeight_location,
		4, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones),						// Stride	(number of bytes)
		(void*)offsetof(cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones, vBoneWeight[0]));		// Offset the member variable

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableVertexAttribArray(vColour_location);
	glDisableVertexAttribArray(vPosition_location);
	glDisableVertexAttribArray(vNormal_location);
	glDisableVertexAttribArray(vUVx2_location);
	glDisableVertexAttribArray(vTangent_location);
	glDisableVertexAttribArray(vBiNormal_location);
	glDisableVertexAttribArray(vBoneID_location);
	glDisableVertexAttribArray(vBoneWeight_location);

	this->mapModelNametoVAOID[drawInfo.meshName] = drawInfo;

	return true;
}

bool cVAOManager::loadModelList(std::string filename, unsigned int shaderProgramID)
{
	cXML modelListXML;
	bool result;

	result = modelListXML.loadModelFromXML(filename);
	if (!result)
	{
		return false;
	}

	std::map<std::string, std::string>::iterator i_mapModel;

	for (i_mapModel = modelListXML.mapModelNameAndPath.begin(); i_mapModel != modelListXML.mapModelNameAndPath.end(); i_mapModel++)
	{
		cModelDrawInfo modelDrawInfo;
		cModelLoader fileLoader;
		std::string error = "";
		result = fileLoader.loadPLYFile(i_mapModel->second, modelDrawInfo, error);
		if (!result)
		{
			std::cout << "cannot load " << i_mapModel->first << std::endl;
			std::cout << "error " << error << std::endl;
			return false;
		}
		result = loadModelToVAO(i_mapModel->first, modelDrawInfo, shaderProgramID);
		if (!result)
		{
			std::cout << "cannot load " << i_mapModel->first << std::endl;
			return false;
		}
		std::cout << i_mapModel->first << " is loaded" << std::endl;
	}
	

	return true;
}

bool cVAOManager::FindDrawInfo(std::string filename, cModelDrawInfo& drawInfo)
{
	std::map<std::string, cModelDrawInfo>::iterator i_DrawInfo = mapModelNametoVAOID.find(filename);
	
	if (i_DrawInfo==mapModelNametoVAOID.end())
	{
		return false;
	}

	drawInfo = i_DrawInfo->second;

	return true;
}
