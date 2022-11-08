#pragma once
//#include "cLight.h"
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

class cDirLight //: public cLight
{
public:
    cDirLight();
    ~cDirLight();

    glm::vec4 direction;
    float ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
    int turnON;

    int direction_location;
    int ambient_location;
    int diffuse_location;
    int specular_location;
    int turnON_location;
};

