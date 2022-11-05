#pragma once
#include "..\globalOpenGL.h"
#include "cModelDrawInfo.h"
#include "cModelLoader.h"
#include "cXML.h"
#include <string>
#include <map>
#include <fstream>


class cVAOManager
{
public:
	cVAOManager();
	~cVAOManager();

	bool loadModelToVAO(std::string filename, cModelDrawInfo& drawInfo, unsigned int shaderProgramID);
	bool loadModelList(std::string filename, unsigned int shaderProgramID);
	bool FindDrawInfo(std::string filename, cModelDrawInfo& drawInfo);

private:
	std::map<std::string, cModelDrawInfo> mapModelNametoVAOID;
};

