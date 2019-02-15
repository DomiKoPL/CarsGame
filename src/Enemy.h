#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "ConstVariables.h"
#include "CarTextures.h"

class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	void SetTexture(int id);
	void SetRandomTexture();
	bool HitPlayer();
	bool Move(sf::Vector2f offset);
	void Draw(sf::RenderWindow * window);
	void SetPosition(sf::Vector2f newPosition);
	void SetRandomPosition();
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	Enemy();
	~Enemy();
};

