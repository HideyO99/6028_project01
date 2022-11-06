#include "cMeshObj.h"

cMeshObj::cMeshObj()
{
	meshName.clear();

	position = glm::vec3(0.f);
	scale = 1.f;
	isWireframe = false;

	color_RGBA = glm::vec4(0.f, 0.f, 0.f, 1.f);
	isVisible = false;
}

cMeshObj::~cMeshObj()
{
}
