#pragma once

#include "shader_program.h"
#include "texture.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class Textured_2D_Shader_Program : public Shader_Program
{
public:
	Textured_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Textured_2D_Shader_Program();

	void render(const Configuration* config, const Mesh* mesh, const Texture* texture, const glm::mat4* transformation) const;
};