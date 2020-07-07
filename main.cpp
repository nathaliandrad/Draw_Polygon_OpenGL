#include "engine.h"
#include "assets.h"
#include "scene.h"
#include "configuration.h"
#include "game_scene.h"

#include <glfw3.h>

#include <iostream>
#include <chrono>
#include <thread>
#include <stack>

int main(void)
{
	try
	{
		Configuration* config = new Configuration();
		Engine* engine        = new Engine("Game", config);
		Assets* assets        = new Assets();

		std::stack<Scene*> scenes;
		scenes.push(new Game_Scene());

		const double frames_per_second = 60.0;
		const double frame_time_s      = 1.0 / frames_per_second;
		double frame_start_time_s      = 0;
		double frame_end_time_s        = frame_time_s;
		while(!glfwWindowShouldClose(engine->window()))
		{
			const double previous_frame_duration_s = frame_end_time_s - frame_start_time_s;
			frame_start_time_s                     = glfwGetTime();

			glfwPollEvents();
			scenes.top()->update(previous_frame_duration_s);
			engine->simulate(previous_frame_duration_s, assets, scenes.top(), config);

			const double current_time_s           = glfwGetTime();
			const double current_frame_duration_s = current_time_s - frame_start_time_s;
			if(current_frame_duration_s < frame_time_s)
			{
				const double time_to_sleep_for_s = frame_time_s - current_frame_duration_s;
				std::this_thread::sleep_for(std::chrono::milliseconds((int)(time_to_sleep_for_s * 1000.0)));
			}

			frame_end_time_s = glfwGetTime();
		}
	}
	catch(const std::exception& exception)
	{
		std::cout << "Unhandled exception caught in main. Exception: " << exception.what() << std::endl;
		std::cout << "GL Error: " << std::hex << (int)glGetError();
		exit(1);
	}
	

	return 0;
}