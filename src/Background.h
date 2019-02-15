#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "ConstVariables.h"

class Background
{
private:
	sf::Texture texture0, texture1;
	sf::Sprite sprites[AmountOfBackgroundImages * 2];
	sf::Sprite staticSprites[AmountOfBackgroundImages];
	float minY = -60.0f;
	float maxY;
public:
	static Background* GetInstance();
	void LoadTextures(std::string path0, std::string path1);
	void SetTextures();
	void Draw(sf::RenderWindow * window);
	void Move(sf::Vector2f offset);
	void SetPositions();
	Background();
	~Background();
};
#define background Background::GetInstance()

