#pragma once
#include <pugixml/pugixml.hpp>
#include <map>
#include <iostream>
#include <glm\glm.hpp>


class cXML
{
public:
	cXML();
	~cXML();

	bool loadModelFromXML(std::string filename);
	bool findPathFromModelName(std::string modelName, std::string& modelPath);

	std::map<std::string, std::string> mapModelNameAndPath;
	std::map<std::string, glm::vec3> mapModelNameAndPosition;
};

