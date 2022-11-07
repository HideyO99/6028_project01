#pragma once
#include "..\globalOpenGL.h"
#include "cLight.h"
#include <string>

class cLightManager
{
public:
	cLightManager();
	~cLightManager();

	cLight veclight;

	void loadLightUniformLocation(unsigned int shaderID);
	void setLightToShader(unsigned int shaderID);
};

