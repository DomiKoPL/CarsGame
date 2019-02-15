#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "Background.h"
#include "Player.h"
#include "UI.h"

class Game
{
private:
	//Enemy
	float DefaultEnemyYSpeed = 0.7f;
	float EnemyYSpeed = 0.0f;

	float EnemyMaxSpeedScale = 25.0f;
	float DefaultEnemySpeedScale = 1.0f;
	float EnemySpeedScale = 0.0f;

	float EnemySpeedScaleIncrease = 0.25f;
	//Background
	float DefaultBackgroundSpeed = 0.6f;
	float BackgroundSpeed = 0.0f;

	float BackgroundMaxSpeedScale = 25.0f;
	float DefaultBackgroundSpeedScale = 1.0f;
	float BackgroundSpeedScale = 0.0f;

	float BackgroundSpeedScaleIncrease = 0.25f;
	//Player
	float DefaultPlayerXSpeed = 1.8f;
	float PlayerXSpeed = 0.0f;

	float PlayerMaxXSpeedScale = 7.0f;
	float DefaultPlayerXSpeedScale = 1.0f;
	float PlayerXSpeedScale = 0.0f;

	float PlayerXSpeedScaleIncrease = 0.10f;

	//
	bool gamePaused = true;
	bool gameOver = false;
	std::vector < Enemy* > enemies;
	sf::RenderWindow* window;

	void UpdateScaleAndTime();
	void SpawnEnemy();
	bool CanSpawnEnemy();
	void GameOver();
	void PlayerMove();
	bool EnemiesMove();
	void EnemiesDraw();
	int currentScore = 0;

	sf::Clock clock;
	float currentFPS;
public:
	static Game* GetInstance();
	void Start();
	void Pause();
	void Continue();
	void Restart();
	Game();
	~Game();
};
#define game Game::GetInstance()

