#ifndef VertexFormat_H_
#define VertexFormate_H_

#include "glm\glm.hpp" //installed through Package Manager

struct VertexFormat
{
	glm::vec3 position; //First attribute
	VertexFormat(const glm::vec3 &pos)
	{
		position = pos;
	}
};

#endif