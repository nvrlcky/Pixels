#pragma once

class PlayerMovement
{
public:
	PlayerMovement();
	~PlayerMovement();
	//sf::Vector2i dirOrigin;
	void initMovement(sf::Sprite &sprite, AnimatedSprite &as, sf::Texture &texture, sf::Clock &clock, sf::Vector2i &origin);

private:
	enum Direction { Down = 0, Up = 96, Right = 192, Left = 288 };
};



