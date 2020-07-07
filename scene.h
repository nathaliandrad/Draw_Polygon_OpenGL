#pragma once

#include <map>
#include <string>
#include <vector>

class Game_Object;
class Input;

class Scene
{
public:
	Scene(const char* id);
	~Scene();

	virtual void update(const double seconds_to_simulate) = 0;

	Game_Object* get_game_object(const char* id) const;
	std::vector<Game_Object*> get_game_objects() const;

	const char* id() const;

protected:
	std::map<std::string, Game_Object*> _game_objects;
	const char*                         _id;
};