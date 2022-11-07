#include "cXML.h"

cXML::cXML()
{
	this->mapModelNameAndPath.clear();
}

cXML::~cXML()
{
}

bool cXML::loadModelFromXML(std::string filename)
{
	pugi::xml_document modelList_xml;
	pugi::xml_parse_result result = modelList_xml.load_file(filename.c_str());
	if (!result)
	{
		std::cout << "Unable to load XML file" << std::endl;
		return false;
	}
	std::cout << "Loading Model from XML" << std::endl;
	pugi::xml_object_range<pugi::xml_node_iterator> modelList = modelList_xml.child("PLYMODEL").children();
	if (modelList.empty())
	{
		std::cout << "There are no entries" << std::endl;
		return false;
	}
	pugi::xml_node_iterator i_modelList;
	for (i_modelList = modelList.begin(); i_modelList != modelList.end(); i_modelList++)
	{
		pugi::xml_node modelNode = *i_modelList;
		pugi::xml_attribute_iterator i_modelAttrb;
		pugi::xml_attribute modelAttrbName;
		for (i_modelAttrb = modelNode.attributes_begin(); i_modelAttrb != modelNode.attributes_end(); i_modelAttrb++)
		{
			modelAttrbName = *i_modelAttrb;
		}
		mapModelNameAndPath.emplace(modelAttrbName.value(), modelNode.child_value());
	}

	return true;
}

bool cXML::findPathFromModelName(std::string modelName, std::string& modelPath)
{
	std::map<std::string, std::string>::iterator i_model = mapModelNameAndPath.find(modelName);
	if (i_model == mapModelNameAndPath.end())
	{
		return false;
	}
	modelPath = i_model->second;

	return true;
}
