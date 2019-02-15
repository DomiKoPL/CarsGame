#pragma once

#include <SFML/Graphics.hpp>
#include "ConstVariables.h"
#include <string>

class CarTextures
{
private:
	sf::Texture textures[AmountOfCarsTextures];
public:
	static CarTextures* GetInstance();
	void LoadTextures(std::string path);
	sf::Texture GetTexture(int id);
	sf::Texture GetRandomTexture();
	CarTextures();
	~CarTextures();
};
#define carTextures CarTextures::GetInstance()
