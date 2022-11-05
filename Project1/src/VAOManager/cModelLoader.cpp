#include "cModelLoader.h"

cModelLoader::cModelLoader()
{
}

cModelLoader::~cModelLoader()
{
}

bool cModelLoader::loadPLYFile(std::string filename, cModelDrawInfo modelDrawInfo, std::string error)
{
	sVertex_XYZ_N_RGBA_UV* pTheModelArray = NULL;
	sTrianglePLY* pTheModelTriangleArray = NULL;

	std::ifstream modelFile(filename);
	if (!modelFile.is_open())
	{
		error = " cannot open " + filename;
		return false;
	}

	char buffer[MODEL_LOAD_BUFFER];
	modelFile.getline(buffer, MODEL_LOAD_BUFFER);
	std::string nextToken;

	while (modelFile >> nextToken)
	{
		if (nextToken == "vertex")
		{
			break;
		}
	}
	modelFile >> modelDrawInfo.numberOfVertices;

	while (modelFile >> nextToken)
	{
		if (nextToken == "face")
		{
			break;
		}
	}
	modelFile >> modelDrawInfo.numberOfTriangles;

	while (modelFile >> nextToken)
	{
		if (nextToken == "end_header")
		{
			break;
		}
	}

	pTheModelArray = new sVertex_XYZ_N_RGBA_UV[modelDrawInfo.numberOfVertices];

	for (unsigned int i = 0; i != modelDrawInfo.numberOfVertices; i++)
	{
		modelFile >> pTheModelArray[i].x;
		modelFile >> pTheModelArray[i].y;
		modelFile >> pTheModelArray[i].z;

		modelFile >> pTheModelArray[i].nx;
		modelFile >> pTheModelArray[i].ny;
		modelFile >> pTheModelArray[i].nz;

		modelFile >> pTheModelArray[i].red;
		modelFile >> pTheModelArray[i].green;
		modelFile >> pTheModelArray[i].blue;
		modelFile >> pTheModelArray[i].alpha;

		modelFile >> pTheModelArray[i].texture_u;
		modelFile >> pTheModelArray[i].texture_v;
	}
	
	pTheModelTriangleArray = new sTrianglePLY[modelDrawInfo.numberOfTriangles];

	for (unsigned int i = 0; i != modelDrawInfo.numberOfTriangles; i++)
	{
		modelFile >> pTheModelTriangleArray[i].vertexIndices[0];
		modelFile >> pTheModelTriangleArray[i].vertexIndices[1];
		modelFile >> pTheModelTriangleArray[i].vertexIndices[2];
	}

	modelFile.close();

	modelDrawInfo.pVertices = new cModelDrawInfo::sVertex_RGBA_XYZ_N_UV_T_BiN_Bones[modelDrawInfo.numberOfVertices];

	for (unsigned int i = 0; i != modelDrawInfo.numberOfVertices; i++) 
	{
		modelDrawInfo.pVertices[i].x = pTheModelArray[i].x;
		modelDrawInfo.pVertices[i].y = pTheModelArray[i].y;
		modelDrawInfo.pVertices[i].z = pTheModelArray[i].z;

		modelDrawInfo.pVertices[i].r = pTheModelArray[i].red;
		modelDrawInfo.pVertices[i].g = pTheModelArray[i].green;
		modelDrawInfo.pVertices[i].b = pTheModelArray[i].blue;

		modelDrawInfo.pVertices[i].nx = pTheModelArray[i].nx;
		modelDrawInfo.pVertices[i].ny = pTheModelArray[i].ny;
		modelDrawInfo.pVertices[i].nz = pTheModelArray[i].nz;
	}

	modelDrawInfo.numberOfIndices = modelDrawInfo.numberOfTriangles * 3;
	modelDrawInfo.pIndices = new unsigned int[modelDrawInfo.numberOfIndices];

	unsigned int vertexElementIndex = 0;
	for (unsigned int i = 0; i != modelDrawInfo.numberOfTriangles; i++)
	{
		modelDrawInfo.pIndices[vertexElementIndex + 0] = pTheModelTriangleArray[i].vertexIndices[0];
		modelDrawInfo.pIndices[vertexElementIndex + 1] = pTheModelTriangleArray[i].vertexIndices[1];
		modelDrawInfo.pIndices[vertexElementIndex + 2] = pTheModelTriangleArray[i].vertexIndices[2];

		vertexElementIndex += 3;
	}

	delete[] pTheModelArray;
	delete[] pTheModelTriangleArray;

	return true;
}
