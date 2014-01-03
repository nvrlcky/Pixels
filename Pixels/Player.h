#pragma once

class Player
{
public:
	
	Player(sf::Texture &texture);
	~Player();
	Animation walkingAnimation;
	Animation stillDown;
	AnimatedSprite animatedSprite;
	sf::Clock clock, dirClock;
	sf::Vector2i dirOrigin;
	enum Direction { Down, Up, Right, Left };
	void setDirection(Direction);
	AnimatedSprite getSprite();


private:

	
};
