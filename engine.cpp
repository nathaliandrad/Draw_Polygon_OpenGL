#include <algorithm>
#include <iostream>

#include "engine.h"
#include "game_object.h"
#include "expectations.h"
#include "shader_program.h"
#include "mesh.h"
#include "configuration.h"
#include "scene.h"
#include "assets.h"
#include "texture.h"

#define GLEW_STATIC
#include <glew.h>

#include <glfw3.h>

Engine::Engine(const char* game_name, Configuration* config)
{
	const auto initialize_glfw = [this, game_name, config]()
	{
		expect(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		_window = glfwCreateWindow(config->screen_width, config->screen_height, game_name, NULL, NULL);
		expect(_window != nullptr, "Failed to create GLFW window.");
		glfwMakeContextCurrent(_window);
	};
	const auto initialize_glew = [this]()
	{
		glewExperimental = GL_TRUE;
		const GLenum init_result = glewInit();
		expect(glewInit() == GLEW_OK, (char*)glewGetErrorString(init_result));
	};
	const auto initialize_gl = [this]()
	{
		const auto gl_debug_message_callback = [](
			GLenum,
			GLenum type,
			GLuint,
			GLenum severity,
			GLsizei,
			const GLchar* message,
			const void*)
		{
			if(severity > GL_DEBUG_SEVERITY_NOTIFICATION)
			{
				fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
					(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
					type, severity, message);
				std::cout << glGetError() << std::endl;
			}
		};

		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(gl_debug_message_callback, 0);
	};

	initialize_glfw();
	initialize_glew();
	initialize_gl();
}
Engine::~Engine()
{
}
void Engine::simulate(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	simulate_AI(seconds_to_simulate, assets, scene, config);
	simulate_physics(seconds_to_simulate, assets, scene, config);
	render(seconds_to_simulate, assets, scene, config);
}
void Engine::simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	for(auto game_object : scene->get_game_objects())
	{
		game_object->simulate_AI(seconds_to_simulate, assets, scene, config);
	}
}
void Engine::simulate_physics(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	for(auto game_object : scene->get_game_objects())
	{
		game_object->simulate_physics(seconds_to_simulate, assets, scene, config);
	}
}
void Engine::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	const auto prepare = [this]()
	{
		glfwSwapBuffers(_window);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	};
	const auto render_gameobjects = [this, assets, config, scene, seconds_to_simulate]()
	{
		for(auto game_object : scene->get_game_objects())
		{
			game_object->render(seconds_to_simulate, assets, scene, config);
		}
	};
	const auto cleanup = [this]()
	{
		glBindVertexArray(0);
		glUseProgram(0);
	};

	prepare();
	render_gameobjects();
	cleanup();	
}

GLFWwindow* Engine::window() const
{
	return _window;
}