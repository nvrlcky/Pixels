#include "Main.h"

Player::Player(sf::Texture &texture)
{
	// map animation to a spritesheet
	walkingAnimation.setSpriteSheet(texture);
	stillDown.setSpriteSheet(texture);

	// walking frames
	walkingAnimation.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimation.addFrame(sf::IntRect(64, 0, 32, 32));
	// standing still (UP) frame
	stillDown.addFrame(sf::IntRect(0, 0, 32, 32));

	// face up by default and start at (0,0)
	as.setAnimation(stillDown);
	//as.pause();
	as.setPosition(0, 0);

	//walkingAnimation.addFrame(sf::IntRect(0, 0, 32, 32));
}

Player::~Player()
{
}

AnimatedSprite Player::update(sf::Sprite &sprite, sf::Event &event, sf::Vector2i &origin) {
	float speed = 45.0f; // 45px per second
	float delta = clock.restart().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//as.setAnimation(walkingAnimation);
		as.play(walkingAnimation);
		as.move(0, speed * delta);

	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		as.setAnimation(stillDown);
		//as.pause();
	}
	as.update(clock.restart());
	return as;
}