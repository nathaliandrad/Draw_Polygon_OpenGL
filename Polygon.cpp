#include "Polygon.h"
#include "colored_2D_shader_program.h"
#include "assets.h"
#include "engine.h"
#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>


Polygon::Polygon(const char* id)
	: Game_Object(id)
{
	_scale = glm::vec3(1.5, 1.0, 1.0);
	_total_time_s = 0;

}

Polygon::~Polygon()
{
}

void Polygon::simulate_AI(const double, const Assets*, const Scene*, const Configuration*)
{

}
/*
void Blocky_Boy::simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
}
*/
void Polygon::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{

	_total_time_s += seconds_to_simulate;

	//_rotation.z = (float)_total_time_s;
	//_translation = glm::vec3(cos(_total_time_s), sin(_total_time_s),  0);

	std::vector<GLfloat> colors = {
	1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};

	/*
	1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	*/

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Polygon");

	glm::mat4 trans = transformation(scene, config);

	program->render(config, mesh, &colors, &trans);


}

