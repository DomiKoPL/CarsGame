#include "Player.h"

Player * Player::GetInstance()
{
	static Player _player;
	return &_player;
}

void Player::SetTexture(int id)
{
	texture = carTextures->GetTexture(id);

	sprite.setTexture(texture);
}

void Player::SetRandomTexture()
{
	texture = carTextures->GetRandomTexture();

	sprite.setTexture(texture);
}


void Player::Move(sf::Vector2f offset)
{
	sprite.move(offset);

	if (GetPosition().x < RoadMinX)
	{
		SetPosition(sf::Vector2f(RoadMinX, GetPosition().y));
	}
	if (GetPosition().x > RoadMaxX)
	{
		SetPosition(sf::Vector2f(RoadMaxX, GetPosition().y));
	}
}

void Player::Draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void Player::SetPosition(sf::Vector2f newPosition)
{
	sprite.setPosition(newPosition);
}

sf::Vector2f Player::GetPosition()
{
	return sprite.getPosition();
}

sf::Vector2f Player::GetSize()
{
	return sf::Vector2f(texture.getSize());
}

Player::Player()
{
	//default settings
	SetTexture(4);
	SetPosition(sf::Vector2f((RoadMaxX + RoadMinX) / 2, PlayerY));
}


Player::~Player()
{
}
