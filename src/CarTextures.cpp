#include "CarTextures.h"
#include <random>


CarTextures * CarTextures::GetInstance()
{
	static CarTextures _carTextures;
	return &_carTextures;
}

void CarTextures::LoadTextures(std::string path)
{
	for (int i = 0; i < AmountOfCarsTextures; i++)
	{
		path[path.size() - 5] = (i + '0');
		textures[i].loadFromFile(path);
	}
}

sf::Texture CarTextures::GetTexture(int id)
{
	return textures[id];
}

sf::Texture CarTextures::GetRandomTexture()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, AmountOfCarsTextures - 1);

	int id = dist6(rng);

	return GetTexture(id);
}

CarTextures::CarTextures()
{
	LoadTextures("Resource/car0.png");
}


CarTextures::~CarTextures()
{
}
