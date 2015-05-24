#version 420 core
layout(location = 0) in vec3 in_position; //set the first input on index 0 for the in_position attribute.
layout(location = 1) in vec4 in_color;

out vec4 color;

void main()
{
	color = in_color;
	gl_Position = vec4(in_position, 1.0); //w is 1, we added a dimension to cast as a vec4.

}