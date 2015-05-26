#include "Model.h"
using namespace Rendering;
using namespace Models;

Model::Mode() {}

Model::~Model()
{
	Destroy();
}

void Model::Draw()
{
	//will be overriden
}

void Model::Update()
{
	//will be overriden
}

void Model::SetPRogram(GLuint program)
{
	this->program = program;
}

GLuint Model::GetVao() const
{
	return vao;
}

const std::vector<GLuint>& Model::GetVbos() const
{
	return vbos;
}

void Model::Destroy()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(vbos.size(), &vbos[0]);
	vbos.clear();
}