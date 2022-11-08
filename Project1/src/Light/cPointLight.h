#pragma once
//#include "cLight.h"
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

class cPointLight //: public cLight
{
public:
	cPointLight();
	~cPointLight();

    glm::vec4 position;
    float ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
    float constant;
    float linear;
    float quadratic;
    int turnON;

    int position_location;
    int ambient_location;
    int diffuse_location;
    int specular_location;
    int constant_location;
    int linear_location;
    int quadratic_location;
    int turnON_location;
};

