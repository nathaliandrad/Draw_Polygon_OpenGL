#pragma once

#include <map>

struct GLFWwindow;

class Input
{
public:
	Input(GLFWwindow* window);
	~Input();

	enum class Button
	{
		QUIT,

		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP
	};

	void update(GLFWwindow* window);

	void set_button_state(Button type, Button_State state);
	bool is_button_state(Button type, Button_State state) const;

private:
	std::map<Button, Button_State> _button_state;
};

