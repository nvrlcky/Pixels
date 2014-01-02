#pragma once

class Player
{
public:
	Player(sf::Texture &texture);
	~Player();

	Animation walkingAnimation;
	Animation stillDown;
	AnimatedSprite as;
	sf::Clock clock;
	//sf::Vector2i dirOrigin;
	AnimatedSprite update(sf::Sprite &sprite, sf::Event &event, sf::Vector2i &origin);

private:
	enum Direction { Down = 0, Up = 96, Right = 192, Left = 288 };
};



