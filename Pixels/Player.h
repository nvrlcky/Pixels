#pragma once

class Player
{
public:
	
	Player(sf::Texture &texture);
	~Player();
	Animation walkDown;
	Animation stillDown;
	Animation walkUp;
	Animation stillUp;
	Animation walkRight;
	Animation stillRight;
	Animation walkLeft;
	Animation stillLeft;
	AnimatedSprite animatedSprite;
	sf::Clock clock, dirClock;
	sf::Vector2i dirOrigin;
	enum Direction { Down, Up, Right, Left };
	void move(Direction);
	void standStill(Direction direction);
	AnimatedSprite getSprite();
	float delta;


private:

	
};
