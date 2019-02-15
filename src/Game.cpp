#include "Game.h"
#include <iostream>

void Game::UpdateScaleAndTime()
{
	EnemySpeedScale += EnemySpeedScaleIncrease;
	EnemySpeedScale = (EnemySpeedScale > EnemyMaxSpeedScale ? EnemyMaxSpeedScale : EnemySpeedScale);

	BackgroundSpeedScale += BackgroundSpeedScaleIncrease;
	BackgroundSpeedScale = (BackgroundSpeedScale > BackgroundMaxSpeedScale ? BackgroundMaxSpeedScale : BackgroundSpeedScale);

	PlayerXSpeedScale += PlayerXSpeedScaleIncrease;

	PlayerXSpeedScale = (PlayerXSpeedScale > PlayerMaxXSpeedScale ? PlayerMaxXSpeedScale : PlayerXSpeedScale);
}


void Game::SpawnEnemy()
{
	enemies.push_back(new Enemy());
	enemies.back()->SetRandomPosition();
}

bool Game::CanSpawnEnemy()
{
	if (!gamePaused && ((int)enemies.size() == 0 || enemies.back()->GetPosition().y - EnemyStartY >= 3.5f * player->GetSize().y))
	{
		return true;
	}
	return false;
}

void Game::GameOver()
{
	gameOver = true;
	gamePaused = true;
	//std::cout << "Score : " << currentScore << "\n";
}

void Game::PlayerMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player->Move(sf::Vector2f(-PlayerXSpeed, 0.0f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player->Move(sf::Vector2f(PlayerXSpeed, 0.0f));
	}
}

bool Game::EnemiesMove()
{
	int sz = enemies.size(), j = 0;
	for (int i = 0; i < sz; i++)
	{
		int id = i + j;
		if (enemies[id]->Move(sf::Vector2f(0, EnemyYSpeed * EnemySpeedScale)) == false)
		{
			enemies.erase(enemies.begin() + id);
			j--;
		}
		else if (enemies[id]->HitPlayer() == true)
		{
			//std::cout << "Hit \n";
			//enemies.erase(enemies.begin() + id);
			//j--;

			return false;
		}
	}
	return true;
}

void Game::EnemiesDraw()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Draw(window);
	}
}

Game * Game::GetInstance()
{
	static Game _game;
	return &_game;
}

void Game::Start()
{
	Restart();
	gamePaused = true;
	gameOver = false;

	ui->UpdateScoreText(currentScore);
	ui->PlayMusic();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		if (ui->PauseButtonClicked(event))
		{
			gamePaused = true;
		}

		if (ui->PlayButtonClicked(event))
		{
			gamePaused = false;
			if (gameOver)
			{
				gameOver = false;
				Restart();
			}
		}

		if (ui->VolumeUpButtonClicked(event))
		{
			ui->ChangeMusicVolume(1);
		}

		if (ui->VolumeDownButtonClicked(event))
		{
			ui->ChangeMusicVolume(-1);
		}

		if (!gamePaused && CanSpawnEnemy())
		{
			currentScore++;
			ui->UpdateScoreText(currentScore);

			SpawnEnemy();
			UpdateScaleAndTime();
			//std::cout << EnemySpeedScale << " " << BackgroundSpeedScale << " " << PlayerXSpeedScale << "\n";
		}

		if (!gamePaused)
		{
			PlayerMove();
		}

		window->clear();

		background->Draw(window);
		if (!gamePaused)
		{
			background->Move(sf::Vector2f(0.0f, BackgroundSpeed * BackgroundSpeedScale));
		}

		player->Draw(window);

		EnemiesDraw();
		if (!gamePaused  && EnemiesMove() == false)
		{
			GameOver();
		}


		if (gameOver)
		{
			ui->DrawGameOverMessage(window);
		}

		currentFPS = 1.f / clock.restart().asSeconds();
		ui->UpdateFPSCounter((int)currentFPS);

		ui->Draw(window);

		window->display();


	}
}

void Game::Pause()
{
	gamePaused = true;
}

void Game::Continue()
{
	gamePaused = false;
}

void Game::Restart()
{
	currentScore = 0;

	enemies.clear();

	EnemyYSpeed = DefaultEnemyYSpeed;
	EnemySpeedScale = DefaultEnemySpeedScale;

	BackgroundSpeed = DefaultBackgroundSpeed;
	BackgroundSpeedScale = DefaultBackgroundSpeedScale;

	PlayerXSpeed = DefaultPlayerXSpeed;
	PlayerXSpeedScale = DefaultPlayerXSpeedScale;
}

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "F1 GAME");

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window->setFramerateLimit(FrameRate);
}


Game::~Game()
{
}
