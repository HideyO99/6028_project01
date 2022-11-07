#include "cLightManager.h"

cLightManager::cLightManager()
{
}

cLightManager::~cLightManager()
{
}

void cLightManager::loadLightUniformLocation(unsigned int shaderID)
{
	veclight.position_location = glGetUniformLocation(shaderID, "Light.position");
	veclight.diffuse_location = glGetUniformLocation(shaderID, "Light.diffuse");
	veclight.specular_location = glGetUniformLocation(shaderID, "Light.specular");
	veclight.attenuation_location = glGetUniformLocation(shaderID, "Light.attenuation");
	veclight.direction_location = glGetUniformLocation(shaderID, "Light.direction");
	veclight.param1_location = glGetUniformLocation(shaderID, "Light.param1");
	veclight.param2_location = glGetUniformLocation(shaderID, "Light.param2");
}

void cLightManager::setLightToShader(unsigned int shaderID)
{
	glUniform4f(veclight.position_location,
				veclight.position.x,
				veclight.position.y,
				veclight.position.z,
				veclight.position.w);

	glUniform4f(veclight.diffuse_location,
				veclight.diffuse.x,
				veclight.diffuse.y,
				veclight.diffuse.z,
				veclight.diffuse.w);

	glUniform4f(veclight.specular_location,
				veclight.specular.x,
				veclight.specular.y,
				veclight.specular.z,
				veclight.specular.w);

	glUniform4f(veclight.attenuation_location,
				veclight.attenuation.x,
				veclight.attenuation.y,
				veclight.attenuation.z,
				veclight.attenuation.w);

	glUniform4f(veclight.direction_location,
				veclight.direction.x,
				veclight.direction.y,
				veclight.direction.z,
				veclight.direction.w);

	glUniform4f(veclight.param1_location,
				veclight.param1.x,
				veclight.param1.y,
				veclight.param1.z,
				veclight.param1.w);

	glUniform4f(veclight.param2_location,
				veclight.param2.x,
				veclight.param2.y,
				veclight.param2.z,
				veclight.param2.w);
}
