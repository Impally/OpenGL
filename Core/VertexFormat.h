#ifndef VertexFormat_H_
#define VertexFormate_H_

#include "glm\glm.hpp" //installed through Package Manager

struct VertexFormat
{
	glm::vec3 position; //First attribute
	glm::vec4 color;

	VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColor)
	{
		position = iPos;
		color = iColor;
	}
};

#endif