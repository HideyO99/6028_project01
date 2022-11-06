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
	glm::vec3 position;
	float scale;
	bool isWireframe;
	glm::vec4 color_RGBA;
	bool isVisible;

};

