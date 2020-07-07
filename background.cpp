#include "background.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Background::Background(const char* id)
	: Game_Object(id)
{
}
Background::~Background()
{
}


void Background::simulate_AI(const double, const Assets*, const Scene*, const Configuration*)
{

}
void Background::render(const double, const Assets* assets, const Scene*, const Configuration* config)
{
	std::vector<GLfloat> colors =
	{
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
	};

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program *)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh*                   mesh       = (Mesh*)assets->get_asset("Mesh.Quad");


	program->render(config, mesh, &colors);
}