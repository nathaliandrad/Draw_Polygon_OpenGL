#pragma once

#include "game_object.h"
#include "scene.h"
#include "configuration.h"

Game_Object::Game_Object(const char* id)
	: _id(id)
{
}
Game_Object::~Game_Object()
{
}

const char* Game_Object::id() const
{
	return _id;
}

void Game_Object::simulate_physics(const double, const Assets*, const Scene*, const Configuration*)
{
}

glm::mat4x4 Game_Object::transformation(const Scene* , const Configuration* config) const
{
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), _translation);
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), _scale);

	glm::mat4 rotation_x = glm::rotate(_rotation.x, glm::vec3(1.f, 0.f, 0.f));
	glm::mat4 rotation_y = glm::rotate(_rotation.y, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 rotation_z = glm::rotate(_rotation.z, glm::vec3(0.f, 0.f, 1.f));
	glm::mat4 rotation = rotation_x * rotation_y * rotation_z;

	glm::mat4 model = translation * rotation * scale;

	const float aspect_ratio = float(config->screen_width) / config->screen_height;
	const float x_units = aspect_ratio * config->y_units;

	glm::mat4 projection_scale = glm::scale(glm::mat4(1.0f), glm::vec3(2.0f / x_units, 2.0f / config->y_units, 1));
	glm::mat4 projection_translation = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, 0.f));
	glm::mat4 projection = projection_translation * projection_scale;

	return projection * model;
}


