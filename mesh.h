#pragma once

#include "asset.h"

#include <vector>

#define GLEW_STATIC
#include <glew.h>

class Mesh : public Asset
{
public:
	Mesh(const char* id);
	~Mesh();

	const std::vector<GLfloat> verticies()           const;
	const std::vector<GLfloat> texture_coordinates() const;
	const std::vector<GLfloat> indicies()            const;
	const std::vector<GLfloat> normals()             const;
	
protected:
	std::vector<GLfloat> _verticies;
	std::vector<GLfloat> _texture_coordinates;
	std::vector<GLfloat> _indicies;
	std::vector<GLfloat> _normals;
};