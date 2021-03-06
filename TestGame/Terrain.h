#pragma once
#include <iostream>
#include <GL/glew.h>
#include "Shader.h"
#include "Textures.h"
#include <glm/glm.hpp>
#include "Geometry.h"
#include "Chunk.h"
#include <list>

class Terrain
{
public:
	Terrain();
	~Terrain();
	void Render(float * modelview, float * projection);
	std::list< glm::ivec3 > Terrain::Near(glm::vec3 position, int distance);
private:
	Shader * shader;
	GLuint textures[5];
	std::list< Chunk * > loadedChunks;
};

