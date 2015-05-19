#ifndef _GAME_MODELS_H_
#define _GAME_MODELS_H_

#pragma once
#include "../Dependencies/glew.h"
#include "../Dependencies/freeglut.h"
#include "VertexFormat.h"
#include <vector>
#include <map>

namespace Models
{

	struct Model
	{
		unsigned int vao;
		std::vector<unsigned int> vbos;

		Model() {}
	};

	class GameModels
	{
	public:
		GameModels();
		~GameModels();
		void CreateTriangleModel(const std::string& gameModelName);
		void DeleteModel(const std::string& gameModelName);
		unsigned int GetModel(const std::string& gameModelName);
	private:
		std::map<std::string, Model> GameModeList;  //for storing models
	};

}

#endif