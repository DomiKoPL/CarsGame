#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

class UI
{
private:
	sf::Texture pauseButtonTexture, playButtonTexture;
	sf::Sprite pauseButtonSprite, playButtonSprite;
	void LoadTextures();
	void SetTextures();
	bool IsClickInBounds(sf::Event &event, sf::Sprite &sp, sf::Texture &tex);

	sf::Texture volumeDownButtonTexture, volumeUpButtonTexture;
	sf::Sprite volumeDownButtonSprite, volumeUpButtonSprite;
	sf::Music music;
	void LoadMusic();

	sf::Font font;
	void LoadFont();
	sf::Text scoreText, volumeLevelText;
	void SetTexts();
	void UpdateVolumeLevelText();
	sf::Text score;

	sf::Text gameOverMessage;

	sf::Text FPSCounter;

	std::string IntToString(int temp);// temp >= 0
public:
	static UI* GetInstance();
	void Draw(sf::RenderWindow* window);
	bool PauseButtonClicked(sf::Event &event);
	bool PlayButtonClicked(sf::Event &event);

	void PlayMusic();
	void ChangeMusicVolume(int newVolume);
	bool VolumeUpButtonClicked(sf::Event &event);
	bool VolumeDownButtonClicked(sf::Event &event);
	void DrawGameOverMessage(sf::RenderWindow* window);
	void UpdateScoreText(int &score);
	void UpdateFPSCounter(int FPS);
	UI();
	~UI();
};
#define ui UI::GetInstance()

