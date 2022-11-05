#pragma once
#include "cModelDrawInfo.h"
#include <fstream>

#define MODEL_LOAD_BUFFER 10000

class cModelLoader
{
public:
	cModelLoader();
	~cModelLoader();

    struct sVertex_XYZ_N_RGBA_UV
    {
        float x, y, z;
        float nx, ny, nz;
        float red, green, blue, alpha;
        float texture_u, texture_v;
    };

    struct sTrianglePLY
    {
        // The 3 vertex index values from the ply file
        unsigned int vertexIndices[3];
    };

	bool loadPLYFile(std::string filename, cModelDrawInfo modelDrawInfo, std::string error);

};

