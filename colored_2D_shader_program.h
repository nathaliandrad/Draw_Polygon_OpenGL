#pragma once

#include "shader_program.h"

#include <vector>
#include "game_object.h"
#include "scene.h"
class Mesh;
struct Configuration;

class Colored_2D_Shader_Program : public Shader_Program
{
public:
	Colored_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Colored_2D_Shader_Program();

	void render(const Configuration* config, const Mesh* mesh, const std::vector<GLfloat>* colors, const glm::mat4* transformation) const;
};