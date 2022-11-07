#pragma once
#include <string>
#include <glm/glm.hpp>
//#include <glm/vec3.hpp>

class cMeshObj
{
public:
	cMeshObj();
	~cMeshObj();

	std::string meshName;
	std::string instanceName;
	glm::vec3 position;
	glm::vec3 rotation;
	float scale;
	bool isWireframe;
	glm::vec4 color_RGBA;
	bool isVisible;

};

