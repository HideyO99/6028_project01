#pragma once
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

class cLight
{
public:
	cLight();
	~cLight();

	enum LightType
	{
		LIGHT_POINT,
		LIGHT_SPOT,
		LIGHT_DIRECTION,
		LIGHT_UNDEF = 0xFF
	};

	glm::vec4 position;
	glm::vec4 diffuse;
	glm::vec4 specular;
	glm::vec4 attenuation;
	glm::vec4 direction;
	glm::vec2 angle; //x = innet , y = outer
	LightType type;
	int turnON;
	


	int position_location;
	int diffuse_location;
	int specular_location;
	int attenuation_location;
	int direction_location;
	int angle_location;
	int type_location;
	int turnON_location;

	void setConstantAttenuation(float newConstAtten);
	void setLinearAttenuation(float newLinearAtten);
	void setQuadraticAttenuation(float newQuadAtten);


};

