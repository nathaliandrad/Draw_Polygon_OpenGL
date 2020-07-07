#version 330 core

in vec2 vertex_position;
in vec4 vertex_color;

uniform mat4 transformation;

out vec4 interpolated_color;

void main()
{
    vec4 transformed_position = transformation * vec4(vertex_position.xy, 1.0, 1.0);

   // gl_Position        = vec4(vertex_position.xy, 1.0, 1.0);
    gl_Position        = transformed_position;
    interpolated_color = vertex_color;
}