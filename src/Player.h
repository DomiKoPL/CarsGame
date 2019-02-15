#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "ConstVariables.h"
#include "CarTextures.h"

class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	static Player* GetInstance();
	void SetTexture(int id);
	void SetRandomTexture();
	void Move(sf::Vector2f offset);
	void Draw(sf::RenderWindow * window);
	void SetPosition(sf::Vector2f newPosition);
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	Player();
	~Player();
};
#define player Player::GetInstance()
