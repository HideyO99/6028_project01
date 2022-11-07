#pragma once
#include "..\globalOpenGL.h"
#include "cModelDrawInfo.h"
#include "..\XML\cXML.h"
#include <string>
#include <map>
#include <fstream>
#include "../MeshObj/cMeshObj.h"

#define MODEL_LOAD_BUFFER 10000
class cVAOManager
{
public:
	cVAOManager();
	~cVAOManager();

	struct sTrianglePLY
	{
		// The 3 vertex index values from the ply file
		unsigned int vertexIndices[3];
	};

	bool loadModelToVAO(std::string filename, cModelDrawInfo& drawInfo, unsigned int shaderProgramID);
	bool loadModelList(std::string filename, unsigned int shaderProgramID);
	bool FindDrawInfo(std::string filename, cModelDrawInfo& drawInfo);
	bool loadPLYFile(std::string filename, cModelDrawInfo& modelDrawInfo, std::string error);

	std::map<std::string, cMeshObj*> mapInstanceNametoMeshObj;

private:
	std::map<std::string, cModelDrawInfo> mapModelNametoVAOID;
};

