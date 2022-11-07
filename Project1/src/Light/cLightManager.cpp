#include "cLightManager.h"

cLightManager::cLightManager()
{
}

cLightManager::~cLightManager()
{
}

void cLightManager::loadLightUniformLocation(unsigned int shaderID)
{
	light[0].position_location = glGetUniformLocation(shaderID, "Light[0].position");
	light[0].diffuse_location = glGetUniformLocation(shaderID, "Light[0].diffuse");
	light[0].specular_location = glGetUniformLocation(shaderID, "Light[0].specular");
	light[0].attenuation_location = glGetUniformLocation(shaderID, "Light[0].attenuation");
	light[0].direction_location = glGetUniformLocation(shaderID, "Light[0].direction");
	light[0].angle_location = glGetUniformLocation(shaderID, "Light[0].angle");
	light[0].type_location = glGetUniformLocation(shaderID, "Light[0].type");
	light[0].turnON_location = glGetUniformLocation(shaderID, "Light[0].turnON");

	light[1].position_location = glGetUniformLocation(shaderID, "Light[1].position");
	light[1].diffuse_location = glGetUniformLocation(shaderID, "Light[1].diffuse");
	light[1].specular_location = glGetUniformLocation(shaderID, "Light[1].specular");
	light[1].attenuation_location = glGetUniformLocation(shaderID, "Light[1].attenuation");
	light[1].direction_location = glGetUniformLocation(shaderID, "Light[1].direction");
	light[1].angle_location = glGetUniformLocation(shaderID, "Light[1].angle");
	light[1].type_location = glGetUniformLocation(shaderID, "Light[1].type");
	light[1].turnON_location = glGetUniformLocation(shaderID, "Light[1].turnON");

	light[2].position_location = glGetUniformLocation(shaderID, "Light[2].position");
	light[2].diffuse_location = glGetUniformLocation(shaderID, "Light[2].diffuse");
	light[2].specular_location = glGetUniformLocation(shaderID, "Light[2].specular");
	light[2].attenuation_location = glGetUniformLocation(shaderID, "Light[2].attenuation");
	light[2].direction_location = glGetUniformLocation(shaderID, "Light[2].direction");
	light[2].angle_location = glGetUniformLocation(shaderID, "Light[2].angle");
	light[2].type_location = glGetUniformLocation(shaderID, "Light[2].type");
	light[2].turnON_location = glGetUniformLocation(shaderID, "Light[2].turnON");

	light[3].position_location = glGetUniformLocation(shaderID, "Light[3].position");
	light[3].diffuse_location = glGetUniformLocation(shaderID, "Light[3].diffuse");
	light[3].specular_location = glGetUniformLocation(shaderID, "Light[3].specular");
	light[3].attenuation_location = glGetUniformLocation(shaderID, "Light[3].attenuation");
	light[3].direction_location = glGetUniformLocation(shaderID, "Light[3].direction");
	light[3].angle_location = glGetUniformLocation(shaderID, "Light[3].angle");
	light[3].type_location = glGetUniformLocation(shaderID, "Light[3].type");
	light[3].turnON_location = glGetUniformLocation(shaderID, "Light[3].turnON");

	light[4].position_location = glGetUniformLocation(shaderID, "Light[4].position");
	light[4].diffuse_location = glGetUniformLocation(shaderID, "Light[4].diffuse");
	light[4].specular_location = glGetUniformLocation(shaderID, "Light[4].specular");
	light[4].attenuation_location = glGetUniformLocation(shaderID, "Light[4].attenuation");
	light[4].direction_location = glGetUniformLocation(shaderID, "Light[4].direction");
	light[4].angle_location = glGetUniformLocation(shaderID, "Light[4].angle");
	light[4].type_location = glGetUniformLocation(shaderID, "Light[4].type");
	light[4].turnON_location = glGetUniformLocation(shaderID, "Light[4].turnON");
}			

void cLightManager::setLightToShader(unsigned int shaderID)
{
	for (size_t i = 0; i < MAX_LIGHT_SOURCE; i++)
	{


		glUniform4f(light[i].position_location,
			light[i].position.x,
			light[i].position.y,
			light[i].position.z,
			light[i].position.w);

		glUniform4f(light[i].diffuse_location,
			light[i].diffuse.x,
			light[i].diffuse.y,
			light[i].diffuse.z,
			light[i].diffuse.w);

		glUniform4f(light[i].specular_location,
			light[i].specular.x,
			light[i].specular.y,
			light[i].specular.z,
			light[i].specular.w);

		glUniform4f(light[i].attenuation_location,
			light[i].attenuation.x,
			light[i].attenuation.y,
			light[i].attenuation.z,
			light[i].attenuation.w);

		glUniform4f(light[i].direction_location,
			light[i].direction.x,
			light[i].direction.y,
			light[i].direction.z,
			light[i].direction.w);

		glUniform2f(light[i].angle_location,
			light[i].angle.x,
			light[i].angle.y);

		glUniform1i(light[i].turnON_location,
			light[i].turnON);

	}
}
