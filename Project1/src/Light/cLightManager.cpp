#include "cLightManager.h"

cLightManager::cLightManager()
{
}

cLightManager::~cLightManager()
{
}

void cLightManager::loadLightUniformLocation(unsigned int shaderID)
{
	//directional light
	directionLight.direction_location = glGetUniformLocation(shaderID, "dirLight.position");
	directionLight.ambient_location = glGetUniformLocation(shaderID, "dirLight.ambient");
	directionLight.diffuse_location = glGetUniformLocation(shaderID, "dirLight.diffuse");
	directionLight.specular_location = glGetUniformLocation(shaderID, "dirLight.specular");
	directionLight.turnON_location = glGetUniformLocation(shaderID, "dirLight.turnON");

	//point light
	pointLight[0].position_location		= glGetUniformLocation(shaderID, "pointLights[0].position");
	pointLight[0].ambient_location		= glGetUniformLocation(shaderID, "pointLights[0].ambient");
	pointLight[0].diffuse_location		= glGetUniformLocation(shaderID, "pointLights[0].diffuse");
	pointLight[0].specular_location		= glGetUniformLocation(shaderID, "pointLights[0].specular");
	pointLight[0].constant_location		= glGetUniformLocation(shaderID, "pointLights[0].constant");
	pointLight[0].linear_location		= glGetUniformLocation(shaderID, "pointLights[0].linear");
	pointLight[0].quadratic_location	= glGetUniformLocation(shaderID, "pointLights[0].quadratic");
	pointLight[0].turnON_location		= glGetUniformLocation(shaderID, "pointLights[0].turnON");

	pointLight[1].position_location		= glGetUniformLocation(shaderID, "pointLights[1].position");
	pointLight[1].ambient_location		= glGetUniformLocation(shaderID, "pointLights[1].ambient");
	pointLight[1].diffuse_location		= glGetUniformLocation(shaderID, "pointLights[1].diffuse");
	pointLight[1].specular_location		= glGetUniformLocation(shaderID, "pointLights[1].specular");
	pointLight[1].constant_location		= glGetUniformLocation(shaderID, "pointLights[1].constant");
	pointLight[1].linear_location		= glGetUniformLocation(shaderID, "pointLights[1].linear");
	pointLight[1].quadratic_location	= glGetUniformLocation(shaderID, "pointLights[1].quadratic");
	pointLight[1].turnON_location		= glGetUniformLocation(shaderID, "pointLights[1].turnON");

	pointLight[2].position_location		= glGetUniformLocation(shaderID, "pointLights[2].position");
	pointLight[2].ambient_location		= glGetUniformLocation(shaderID, "pointLights[2].ambient");
	pointLight[2].diffuse_location		= glGetUniformLocation(shaderID, "pointLights[2].diffuse");
	pointLight[2].specular_location		= glGetUniformLocation(shaderID, "pointLights[2].specular");
	pointLight[2].constant_location		= glGetUniformLocation(shaderID, "pointLights[2].constant");
	pointLight[2].linear_location		= glGetUniformLocation(shaderID, "pointLights[2].linear");
	pointLight[2].quadratic_location	= glGetUniformLocation(shaderID, "pointLights[2].quadratic");
	pointLight[2].turnON_location		= glGetUniformLocation(shaderID, "pointLights[2].turnON");

	pointLight[3].position_location		= glGetUniformLocation(shaderID, "pointLights[3].position");
	pointLight[3].ambient_location		= glGetUniformLocation(shaderID, "pointLights[3].ambient");
	pointLight[3].diffuse_location		= glGetUniformLocation(shaderID, "pointLights[3].diffuse");
	pointLight[3].specular_location		= glGetUniformLocation(shaderID, "pointLights[3].specular");
	pointLight[3].constant_location		= glGetUniformLocation(shaderID, "pointLights[3].constant");
	pointLight[3].linear_location		= glGetUniformLocation(shaderID, "pointLights[3].linear");
	pointLight[3].quadratic_location	= glGetUniformLocation(shaderID, "pointLights[3].quadratic");
	pointLight[3].turnON_location		= glGetUniformLocation(shaderID, "pointLights[3].turnON");

	pointLight[4].position_location		= glGetUniformLocation(shaderID, "pointLights[4].position");
	pointLight[4].ambient_location		= glGetUniformLocation(shaderID, "pointLights[4].ambient");
	pointLight[4].diffuse_location		= glGetUniformLocation(shaderID, "pointLights[4].diffuse");
	pointLight[4].specular_location		= glGetUniformLocation(shaderID, "pointLights[4].specular");
	pointLight[4].constant_location		= glGetUniformLocation(shaderID, "pointLights[4].constant");
	pointLight[4].linear_location		= glGetUniformLocation(shaderID, "pointLights[4].linear");
	pointLight[4].quadratic_location	= glGetUniformLocation(shaderID, "pointLights[4].quadratic");
	pointLight[4].turnON_location		= glGetUniformLocation(shaderID, "pointLights[4].turnON");

	//spot light
	spotLight[0].position_location		= glGetUniformLocation(shaderID, "spotLight[0].position");
	spotLight[0].direction_location		= glGetUniformLocation(shaderID, "spotLight[0].direction");
	spotLight[0].ambient_location		= glGetUniformLocation(shaderID, "spotLight[0].ambient");
	spotLight[0].diffuse_location		= glGetUniformLocation(shaderID, "spotLight[0].diffuse");
	spotLight[0].specular_location		= glGetUniformLocation(shaderID, "spotLight[0].specular");
	spotLight[0].constant_location		= glGetUniformLocation(shaderID, "spotLight[0].constant");
	spotLight[0].linear_location		= glGetUniformLocation(shaderID, "spotLight[0].linear");
	spotLight[0].quadratic_location		= glGetUniformLocation(shaderID, "spotLight[0].quadratic");
	spotLight[0].innerAngle_location	= glGetUniformLocation(shaderID, "spotLight[0].innerAngle");
	spotLight[0].outerAngle_location	= glGetUniformLocation(shaderID, "spotLight[0].outerAngle");
	spotLight[0].turnON_location		= glGetUniformLocation(shaderID, "spotLight[0].turnON");

	spotLight[1].position_location		= glGetUniformLocation(shaderID, "spotLight[1].position");
	spotLight[1].direction_location		= glGetUniformLocation(shaderID, "spotLight[1].direction");
	spotLight[1].ambient_location		= glGetUniformLocation(shaderID, "spotLight[1].ambient");
	spotLight[1].diffuse_location		= glGetUniformLocation(shaderID, "spotLight[1].diffuse");
	spotLight[1].specular_location		= glGetUniformLocation(shaderID, "spotLight[1].specular");
	spotLight[1].constant_location		= glGetUniformLocation(shaderID, "spotLight[1].constant");
	spotLight[1].linear_location		= glGetUniformLocation(shaderID, "spotLight[1].linear");
	spotLight[1].quadratic_location		= glGetUniformLocation(shaderID, "spotLight[1].quadratic");
	spotLight[1].innerAngle_location	= glGetUniformLocation(shaderID, "spotLight[1].innerAngle");
	spotLight[1].outerAngle_location	= glGetUniformLocation(shaderID, "spotLight[1].outerAngle");
	spotLight[1].turnON_location		= glGetUniformLocation(shaderID, "spotLight[1].turnON");

	spotLight[2].position_location		= glGetUniformLocation(shaderID, "spotLight[2].position");
	spotLight[2].direction_location		= glGetUniformLocation(shaderID, "spotLight[2].direction");
	spotLight[2].ambient_location		= glGetUniformLocation(shaderID, "spotLight[2].ambient");
	spotLight[2].diffuse_location		= glGetUniformLocation(shaderID, "spotLight[2].diffuse");
	spotLight[2].specular_location		= glGetUniformLocation(shaderID, "spotLight[2].specular");
	spotLight[2].constant_location		= glGetUniformLocation(shaderID, "spotLight[2].constant");
	spotLight[2].linear_location		= glGetUniformLocation(shaderID, "spotLight[2].linear");
	spotLight[2].quadratic_location		= glGetUniformLocation(shaderID, "spotLight[2].quadratic");
	spotLight[2].innerAngle_location	= glGetUniformLocation(shaderID, "spotLight[2].innerAngle");
	spotLight[2].outerAngle_location	= glGetUniformLocation(shaderID, "spotLight[2].outerAngle");
	spotLight[2].turnON_location		= glGetUniformLocation(shaderID, "spotLight[2].turnON");

	spotLight[3].position_location		= glGetUniformLocation(shaderID, "spotLight[3].position");
	spotLight[3].direction_location		= glGetUniformLocation(shaderID, "spotLight[3].direction");
	spotLight[3].ambient_location		= glGetUniformLocation(shaderID, "spotLight[3].ambient");
	spotLight[3].diffuse_location		= glGetUniformLocation(shaderID, "spotLight[3].diffuse");
	spotLight[3].specular_location		= glGetUniformLocation(shaderID, "spotLight[3].specular");
	spotLight[3].constant_location		= glGetUniformLocation(shaderID, "spotLight[3].constant");
	spotLight[3].linear_location		= glGetUniformLocation(shaderID, "spotLight[3].linear");
	spotLight[3].quadratic_location		= glGetUniformLocation(shaderID, "spotLight[3].quadratic");
	spotLight[3].innerAngle_location	= glGetUniformLocation(shaderID, "spotLight[3].innerAngle");
	spotLight[3].outerAngle_location	= glGetUniformLocation(shaderID, "spotLight[3].outerAngle");
	spotLight[3].turnON_location		= glGetUniformLocation(shaderID, "spotLight[3].turnON");

	spotLight[4].position_location		= glGetUniformLocation(shaderID, "spotLight[4].position");
	spotLight[4].direction_location		= glGetUniformLocation(shaderID, "spotLight[4].direction");
	spotLight[4].ambient_location		= glGetUniformLocation(shaderID, "spotLight[4].ambient");
	spotLight[4].diffuse_location		= glGetUniformLocation(shaderID, "spotLight[4].diffuse");
	spotLight[4].specular_location		= glGetUniformLocation(shaderID, "spotLight[4].specular");
	spotLight[4].constant_location		= glGetUniformLocation(shaderID, "spotLight[4].constant");
	spotLight[4].linear_location		= glGetUniformLocation(shaderID, "spotLight[4].linear");
	spotLight[4].quadratic_location		= glGetUniformLocation(shaderID, "spotLight[4].quadratic");
	spotLight[4].innerAngle_location	= glGetUniformLocation(shaderID, "spotLight[4].innerAngle");
	spotLight[4].outerAngle_location	= glGetUniformLocation(shaderID, "spotLight[4].outerAngle");
	spotLight[4].turnON_location		= glGetUniformLocation(shaderID, "spotLight[4].turnON");

	//light[0].position_location = glGetUniformLocation(shaderID, "Light[0].position");
	//light[0].diffuse_location = glGetUniformLocation(shaderID, "Light[0].diffuse");
	//light[0].specular_location = glGetUniformLocation(shaderID, "Light[0].specular");
	//light[0].attenuation_location = glGetUniformLocation(shaderID, "Light[0].attenuation");
	//light[0].direction_location = glGetUniformLocation(shaderID, "Light[0].direction");
	//light[0].angle_location = glGetUniformLocation(shaderID, "Light[0].angle");
	//light[0].type_location = glGetUniformLocation(shaderID, "Light[0].type");
	//light[0].turnON_location = glGetUniformLocation(shaderID, "Light[0].turnON");

	//light[1].position_location = glGetUniformLocation(shaderID, "Light[1].position");
	//light[1].diffuse_location = glGetUniformLocation(shaderID, "Light[1].diffuse");
	//light[1].specular_location = glGetUniformLocation(shaderID, "Light[1].specular");
	//light[1].attenuation_location = glGetUniformLocation(shaderID, "Light[1].attenuation");
	//light[1].direction_location = glGetUniformLocation(shaderID, "Light[1].direction");
	//light[1].angle_location = glGetUniformLocation(shaderID, "Light[1].angle");
	//light[1].type_location = glGetUniformLocation(shaderID, "Light[1].type");
	//light[1].turnON_location = glGetUniformLocation(shaderID, "Light[1].turnON");

	//light[2].position_location = glGetUniformLocation(shaderID, "Light[2].position");
	//light[2].diffuse_location = glGetUniformLocation(shaderID, "Light[2].diffuse");
	//light[2].specular_location = glGetUniformLocation(shaderID, "Light[2].specular");
	//light[2].attenuation_location = glGetUniformLocation(shaderID, "Light[2].attenuation");
	//light[2].direction_location = glGetUniformLocation(shaderID, "Light[2].direction");
	//light[2].angle_location = glGetUniformLocation(shaderID, "Light[2].angle");
	//light[2].type_location = glGetUniformLocation(shaderID, "Light[2].type");
	//light[2].turnON_location = glGetUniformLocation(shaderID, "Light[2].turnON");

	//light[3].position_location = glGetUniformLocation(shaderID, "Light[3].position");
	//light[3].diffuse_location = glGetUniformLocation(shaderID, "Light[3].diffuse");
	//light[3].specular_location = glGetUniformLocation(shaderID, "Light[3].specular");
	//light[3].attenuation_location = glGetUniformLocation(shaderID, "Light[3].attenuation");
	//light[3].direction_location = glGetUniformLocation(shaderID, "Light[3].direction");
	//light[3].angle_location = glGetUniformLocation(shaderID, "Light[3].angle");
	//light[3].type_location = glGetUniformLocation(shaderID, "Light[3].type");
	//light[3].turnON_location = glGetUniformLocation(shaderID, "Light[3].turnON");

	//light[4].position_location = glGetUniformLocation(shaderID, "Light[4].position");
	//light[4].diffuse_location = glGetUniformLocation(shaderID, "Light[4].diffuse");
	//light[4].specular_location = glGetUniformLocation(shaderID, "Light[4].specular");
	//light[4].attenuation_location = glGetUniformLocation(shaderID, "Light[4].attenuation");
	//light[4].direction_location = glGetUniformLocation(shaderID, "Light[4].direction");
	//light[4].angle_location = glGetUniformLocation(shaderID, "Light[4].angle");
	//light[4].type_location = glGetUniformLocation(shaderID, "Light[4].type");
	//light[4].turnON_location = glGetUniformLocation(shaderID, "Light[4].turnON");
}			

void cLightManager::setLightToShader(unsigned int shaderID)
{
	glUniform4f(directionLight.direction_location,
				directionLight.direction.x,
				directionLight.direction.y,
				directionLight.direction.z,
				directionLight.direction.w);

	glUniform1f(directionLight.ambient_location, directionLight.ambient);

	glUniform4f(directionLight.diffuse_location,
				directionLight.diffuse.x,
				directionLight.diffuse.y,
				directionLight.diffuse.z,
				directionLight.diffuse.w);

	glUniform4f(directionLight.specular_location,
				directionLight.specular.x,
				directionLight.specular.y,
				directionLight.specular.z,
				directionLight.specular.w);

	glUniform1f(directionLight.turnON_location, directionLight.turnON);

	for (size_t i = 0; i < MAX_LIGHT_SOURCE; i++)
	{
		glUniform4f(pointLight[i].position_location,
			pointLight[i].position.x,
			pointLight[i].position.y,
			pointLight[i].position.z,
			pointLight[i].position.w);

		glUniform1f(pointLight[i].ambient_location, pointLight[i].ambient);

		glUniform4f(pointLight[i].diffuse_location,
			pointLight[i].diffuse.x,
			pointLight[i].diffuse.y,
			pointLight[i].diffuse.z,
			pointLight[i].diffuse.w);

		glUniform4f(pointLight[i].specular_location,
			pointLight[i].specular.x,
			pointLight[i].specular.y,
			pointLight[i].specular.z,
			pointLight[i].specular.w);

		glUniform1f(pointLight[i].constant_location, pointLight[i].constant);

		glUniform1f(pointLight[i].linear_location, pointLight[i].linear);

		glUniform1f(pointLight[i].quadratic_location, pointLight[i].quadratic);

		glUniform1f(pointLight[i].turnON_location, pointLight[i].turnON);

		glUniform4f(spotLight[i].position_location,
			spotLight[i].position.x,
			spotLight[i].position.y,
			spotLight[i].position.z,
			spotLight[i].position.w);

		glUniform4f(spotLight[i].direction_location,
			spotLight[i].direction.x,
			spotLight[i].direction.y,
			spotLight[i].direction.z,
			spotLight[i].direction.w);

		glUniform1f(spotLight[i].ambient_location, spotLight[i].ambient);

		glUniform4f(spotLight[i].diffuse_location,
			spotLight[i].diffuse.x,
			spotLight[i].diffuse.y,
			spotLight[i].diffuse.z,
			spotLight[i].diffuse.w);

		glUniform4f(spotLight[i].specular_location,
			spotLight[i].specular.x,
			spotLight[i].specular.y,
			spotLight[i].specular.z,
			spotLight[i].specular.w);

		glUniform1f(spotLight[i].constant_location, spotLight[i].constant);

		glUniform1f(spotLight[i].linear_location, spotLight[i].linear);

		glUniform1f(spotLight[i].quadratic_location, spotLight[i].quadratic);

		glUniform1f(spotLight[i].innerAngle_location, spotLight[i].innerAngle);

		glUniform1f(spotLight[i].outerAngle_location, spotLight[i].outerAngle);

		glUniform1f(spotLight[i].turnON_location, spotLight[i].turnON);

		//glUniform4f(light[i].position_location,
		//	light[i].position.x,
		//	light[i].position.y,
		//	light[i].position.z,
		//	light[i].position.w);

		//glUniform4f(light[i].diffuse_location,
		//	light[i].diffuse.x,
		//	light[i].diffuse.y,
		//	light[i].diffuse.z,
		//	light[i].diffuse.w);

		//glUniform4f(light[i].specular_location,
		//	light[i].specular.x,
		//	light[i].specular.y,
		//	light[i].specular.z,
		//	light[i].specular.w);

		//glUniform4f(light[i].attenuation_location,
		//	light[i].attenuation.x,
		//	light[i].attenuation.y,
		//	light[i].attenuation.z,
		//	light[i].attenuation.w);

		//glUniform4f(light[i].direction_location,
		//	light[i].direction.x,
		//	light[i].direction.y,
		//	light[i].direction.z,
		//	light[i].direction.w);

		//glUniform2f(light[i].angle_location,
		//	light[i].angle.x,
		//	light[i].angle.y);

		//glUniform1i(light[i].turnON_location,
		//	light[i].turnON);

	}
}
