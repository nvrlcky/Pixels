#pragma once

class Player
{
public:
	Player(sf::Texture &texture);
	~Player();
	Animation walkingAnimation;
	Animation stillDown;
	AnimatedSprite animatedSprite;
	sf::Clock clock;
	sf::Vector2i dirOrigin;
	AnimatedSprite update(sf::Event &event);

private:
	enum Direction { Down = 0, Up = 96, Right = 192, Left = 288 };
};



