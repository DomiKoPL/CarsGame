#include "Enemy.h"
#include "Player.h"
#include <random>
#include <iostream>

void Enemy::SetTexture(int id)
{
	texture = carTextures->GetTexture(id);

	sprite.setTexture(texture);

	sprite.rotate(180);
}

void Enemy::SetRandomTexture()
{
	texture = carTextures->GetRandomTexture();

	sprite.setTexture(texture);

	sprite.rotate(180);

	sprite.setOrigin(sf::Vector2f(58.0f, 0));
}

bool Enemy::HitPlayer()
{
	float x1 = GetPosition().x, x2 = GetPosition().x + GetSize().x;
	float xp1 = player->GetPosition().x, xp2 = player->GetPosition().x + player->GetSize().x;

	if ((x1 >= xp1 && x1 <= xp2) || (x2 >= xp1 && x2 <= xp2))
	{
		float y1 = GetPosition().y, y2 = GetPosition().y - GetSize().y;
		float yp1 = player->GetPosition().y, yp2 = player->GetPosition().y + player->GetSize().y;

		if ((y1 >= yp1 && y1 <= yp2) || (y2 >= yp1 && y2 <= yp2))
		{
			return true;
		}

	}
	return false;
}

bool Enemy::Move(sf::Vector2f offset)
{
	sprite.move(offset);

	if (GetPosition().y >= EnemyMaxY)
	{
		return false;
	}

	return true;
}

void Enemy::Draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}

void Enemy::SetPosition(sf::Vector2f newPosition)
{
	sprite.setPosition(newPosition);
}

void Enemy::SetRandomPosition()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, NumberOfLanes - 1);

	int x = dist6(rng);

	sprite.setPosition(sf::Vector2f(RoadX[x], EnemyStartY));
}

sf::Vector2f Enemy::GetPosition()
{
	return sprite.getPosition();
}

sf::Vector2f Enemy::GetSize()
{
	return sf::Vector2f(texture.getSize());
}

Enemy::Enemy()
{
	SetRandomTexture();
}

Enemy::~Enemy()
{
}
