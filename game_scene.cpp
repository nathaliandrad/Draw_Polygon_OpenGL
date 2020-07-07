#include "game_scene.h"
#include "Polygon.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{

	Polygon* polygon = new Polygon("Game_Object.Polygon");
	_game_objects[polygon->id()] = polygon;


}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double)
{
}