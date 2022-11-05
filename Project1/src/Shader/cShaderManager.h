#pragma once
#include "..\globalOpenGL.h"

#include <string>
#include <fstream>
#include <vector>
#include <map>
class cShaderManager
{
public:
	cShaderManager();
	~cShaderManager();

	class cShader
	{
	public:
		cShader();
		~cShader();

		enum eMyShaderType
		{
			VERTEX_SHADER,
			FRAGMENT_SHADER,
			UNDKNOW = 0xff
		};
		eMyShaderType shaderType;

		unsigned int ID;
		std::string fileName;
		std::vector<std::string> vecSource;

	};

	class cShaderProgram
	{
	public:
		cShaderProgram();
		~cShaderProgram();

		int getUniformID(std::string name);
		bool LoadUniformLocation(std::string varName);

		unsigned int ID;
		std::string callsign;
		std::map<std::string, int> mapUniformNameToUniformLocation;

	};

	bool createShaderProgram(const std::string callSign, cShader& vertex_shader, cShader& fragment_shader);
	bool useShaderProgram(unsigned int id);
	bool useShaderPRogram(std::string callSign);
	unsigned int getIDfromName(std::string callSign);

	//cShaderProgram* pGetShaderProgramFromName(std::string callSign);

private:
	bool cLoadShaderSourceCode(cShader& shader);
	bool cCompileShader(cShader& shader, std::string& error);
	bool cIsCompileOK(const unsigned int shader_id, std::string& error);
	bool cIsLinkOK(const unsigned int program_id, std::string& error);

	std::string lastError;
	std::map<unsigned int, cShaderProgram> mapIDtoShader;
	std::map<std::string, unsigned int> mapNameToID;
};

