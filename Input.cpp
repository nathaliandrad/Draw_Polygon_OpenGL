#include "input.h"

#include <iostream>

#include <glfw3.h>

Input* input;

Input::Input(GLFWwindow* window)
{
	const auto on_key_pressed_callback = [](GLFWwindow*, int key, int, int action, int)
	{
		switch (action)
		{
		case GLFW_PRESS:
			switch (key)
			{
			case GLFW_KEY_ESCAPE:
				input->set_button_state(Button::QUIT, Button_State::PRESSED);
				break;
			case GLFW_KEY_W:
				input->set_button_state(Button::FORWARD, Button_State::PRESSED);
				break;
			case GLFW_KEY_A:
				input->set_button_state(Button::LEFT, Button_State::PRESSED);
				break;
			case GLFW_KEY_S:
				input->set_button_state(Button::BACKWARD, Button_State::PRESSED);
				break;
			case GLFW_KEY_D:
				input->set_button_state(Button::RIGHT, Button_State::PRESSED);
				break;
			}
			break;

		case GLFW_RELEASE:
			switch (key)
			{
			case GLFW_KEY_ESCAPE:
				input->set_button_state(Button::QUIT, Button_State::RELEASED);
				break;
			case GLFW_KEY_W:
				input->set_button_state(Button::FORWARD, Button_State::RELEASED);
				break;
			case GLFW_KEY_A:
				input->set_button_state(Button::LEFT, Button_State::RELEASED);
				break;
			case GLFW_KEY_S:
				input->set_button_state(Button::BACKWARD, Button_State::RELEASED);
				break;
			case GLFW_KEY_D:
				input->set_button_state(Button::RIGHT, Button_State::RELEASED);
				break;
			}
			break;

		}
	};

	input = this;

	glfwSetKeyCallback(window, on_key_pressed_callback);
}
Input::~Input()
{
}

void Input::update(GLFWwindow* window)
{
	for (auto button : _button_state)
	{
		if (button.second == Button_State::PRESSED)
		{
			_button_state[button.first] = Button_State::DOWN;
		}
		else if (button.second == Button_State::RELEASED)
		{
			_button_state[button.first] = Button_State::UP;
		}
	}

	glfwPollEvents();

	if (glfwWindowShouldClose(window))
	{
		input->set_button_state(Button::QUIT, Button_State::PRESSED);
	}
}

bool Input::is_button_state(Button type, Button_State state) const
{
	if (_button_state.find(type) == _button_state.end())
	{
		if (state == Button_State::UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return _button_state.find(type)->second == state;
}

void Input::set_button_state(Button type, Button_State state)
{
	_button_state[type] = state;
}

