#pragma once
#include "..\globalOpenGL.h"
#include "cLight.h"
#include <string>
#include "cDirLight.h"
#include "cPointLight.h"
#include "cSpotLight.h"

#define MAX_LIGHT_SOURCE 5

class cLightManager
{
public:
	cLightManager();
	~cLightManager();

	//cLight light[MAX_LIGHT_SOURCE];
	cDirLight directionLight;
	cPointLight pointLight[MAX_LIGHT_SOURCE];
	cSpotLight spotLight[MAX_LIGHT_SOURCE];

	void loadLightUniformLocation(unsigned int shaderID);
	void setLightToShader(unsigned int shaderID);
};

