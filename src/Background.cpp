#include "Background.h"

Background * Background::GetInstance()
{
	static Background _background;
	return &_background;
}

void Background::LoadTextures(std::string path0, std::string path1)
{
	texture0.loadFromFile(path0);
	texture1.loadFromFile(path1);
}

void Background::SetTextures()
{
	for (int i = 0; i < AmountOfBackgroundImages; i++)
	{
		staticSprites[i].setTexture(texture0);
	}

	for (int i = 0; i < AmountOfBackgroundImages * 2; i++)
	{
		sprites[i].setTexture(texture1);
	}
}

void Background::Draw(sf::RenderWindow * window)
{
	for (int i = 0; i < AmountOfBackgroundImages; i++)
	{
		window->draw(staticSprites[i]);
	}

	for (int i = 0; i < AmountOfBackgroundImages * 2; i++)
	{
		window->draw(sprites[i]);
	}
}

void Background::Move(sf::Vector2f offset)
{
	for (int i = 0; i < AmountOfBackgroundImages * 2; i++)
	{
		sprites[i].move(offset);
		if (sprites[i].getPosition().y >= maxY)
		{
			sprites[i].setPosition(sf::Vector2f(0, minY ));
		}
	}
}

void Background::SetPositions()
{
	sf::Vector2f currentPosition(0.0f, 0.0f);
	for (int i = 0; i < AmountOfBackgroundImages; i++)
	{
		staticSprites[i].setPosition(currentPosition);

		currentPosition.y += staticSprites[i].getTexture()->getSize().y;
	}

	currentPosition = sf::Vector2f(0.0f, minY);

	for (int i = 0; i < AmountOfBackgroundImages * 2; i++)
	{
		sprites[i].setPosition(currentPosition);

		currentPosition.y += sprites[i].getTexture()->getSize().y * 2;
	}

	maxY = currentPosition.y;
}

Background::Background()
{
	LoadTextures("Resource/way0.png", "Resource/way1.png");

	SetTextures();
	SetPositions();
}


Background::~Background()
{
}
