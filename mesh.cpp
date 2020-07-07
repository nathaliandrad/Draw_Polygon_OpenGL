#pragma once

#include "mesh.h"

Mesh::Mesh(const char* id)
	: Asset(id)
{
}
Mesh::~Mesh()
{
}

const std::vector<GLfloat> Mesh::verticies() const
{
	return _verticies;
}

const std::vector<GLfloat> Mesh::texture_coordinates() const
{
	return _texture_coordinates;
}

const std::vector<GLfloat> Mesh::indicies() const
{
	return _indicies;
}

const std::vector<GLfloat> Mesh::normals() const
{
	return _normals;
}