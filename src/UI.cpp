#include "UI.h"

void UI::LoadTextures()
{
	pauseButtonTexture.loadFromFile("Resource/pause.png");
	playButtonTexture.loadFromFile("Resource/play.png");

	volumeUpButtonTexture.loadFromFile("Resource/+.png");
	volumeDownButtonTexture.loadFromFile("Resource/-.png");
}

void UI::SetTextures()
{
	pauseButtonSprite.setTexture(pauseButtonTexture);
	playButtonSprite.setTexture(playButtonTexture);

	pauseButtonSprite.setPosition(sf::Vector2f(365, 520));
	playButtonSprite.setPosition(sf::Vector2f(365, 580));

	volumeUpButtonSprite.setTexture(volumeUpButtonTexture);
	volumeDownButtonSprite.setTexture(volumeDownButtonTexture);

	volumeUpButtonSprite.setPosition(sf::Vector2f(365, 400));
	volumeDownButtonSprite.setPosition(sf::Vector2f(365, 460));
}

void UI::LoadMusic()
{
	music.openFromFile("Resource/race.ogg");
}

bool UI::IsClickInBounds(sf::Event & event, sf::Sprite & sp, sf::Texture & tex)
{
	return (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x >= sp.getPosition().x &&
		event.mouseButton.x <= sp.getPosition().x + tex.getSize().x &&
		event.mouseButton.y >= sp.getPosition().y &&
		event.mouseButton.y <= sp.getPosition().y + tex.getSize().y);
}

void UI::LoadFont()
{
	font.loadFromFile("Resource/Beach Society Light.ttf");
}

void UI::SetTexts()
{
	score.setFont(font);
	score.setPosition(sf::Vector2f(358, 20));
	score.setString("Score");

	scoreText.setFont(font);
	scoreText.setPosition(sf::Vector2f(365, 50));
	scoreText.setCharacterSize(32);

	volumeLevelText.setFont(font);
	volumeLevelText.setPosition(sf::Vector2f(365, 360));
	volumeLevelText.setCharacterSize(32);

	UpdateVolumeLevelText();

	gameOverMessage.setFont(font);
	gameOverMessage.setPosition(sf::Vector2f(110.0f, 190.0f));
	gameOverMessage.setCharacterSize(45);
	gameOverMessage.setFillColor(sf::Color::Red);
	gameOverMessage.setString("GAME OVER");

	FPSCounter.setFont(font);
	FPSCounter.setPosition(sf::Vector2f(395, 0));
	FPSCounter.setCharacterSize(20);
	FPSCounter.setFillColor(sf::Color::Black);
}

void UI::UpdateScoreText(int & score)
{
	scoreText.setString(IntToString(score));
}

void UI::UpdateFPSCounter(int FPS)
{
	FPSCounter.setString(IntToString(FPS));
}

void UI::UpdateVolumeLevelText()
{
	volumeLevelText.setString(IntToString((int)music.getVolume()));
}

std::string UI::IntToString(int temp)
{
	if (temp == 0)
	{
		return "0";
	}
	std::string res = "";
	while (temp > 0)
	{
		res += (temp % 10) + '0';
		temp /= 10;
	}
	std::reverse(res.begin(), res.end());
	return res;
}

UI * UI::GetInstance()
{
	static UI _ui;
	return &_ui;
}

void UI::Draw(sf::RenderWindow * window)
{
	window->draw(score);

	window->draw(pauseButtonSprite);
	window->draw(playButtonSprite);

	window->draw(volumeUpButtonSprite);
	window->draw(volumeDownButtonSprite);

	window->draw(scoreText);
	window->draw(volumeLevelText);

	window->draw(FPSCounter);
}

bool UI::PauseButtonClicked(sf::Event &event)
{
	return IsClickInBounds(event, pauseButtonSprite, pauseButtonTexture);
}

bool UI::PlayButtonClicked(sf::Event &event)
{
	return IsClickInBounds(event, playButtonSprite, playButtonTexture);
}

void UI::PlayMusic()
{
	music.setLoop(true);
	music.play();
}

void UI::ChangeMusicVolume(int offset)
{
	int newVolume = music.getVolume() + offset;

	newVolume = std::max(0, std::min(newVolume + offset, 100));

	music.setVolume(newVolume);

	UpdateVolumeLevelText();
}

bool UI::VolumeUpButtonClicked(sf::Event & event)
{
	return IsClickInBounds(event, volumeUpButtonSprite, volumeUpButtonTexture);
}

bool UI::VolumeDownButtonClicked(sf::Event & event)
{
	return IsClickInBounds(event, volumeDownButtonSprite, volumeDownButtonTexture);
}

void UI::DrawGameOverMessage(sf::RenderWindow* window)
{
	window->draw(gameOverMessage);
}

UI::UI()
{
	LoadFont();
	LoadMusic();
	LoadTextures();

	SetTextures();
	SetTexts();
}


UI::~UI()
{

}
