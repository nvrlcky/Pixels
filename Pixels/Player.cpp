#include "Main.h"

Player::Player(sf::Texture &texture) : animatedSprite(sf::seconds(0.1f)) {

	//animatedSprite(sf::seconds(0.2f));
	// map animation to a spritesheet
	walkingAnimation.setSpriteSheet(texture);
	stillDown.setSpriteSheet(texture);

	// walking frames
	walkingAnimation.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimation.addFrame(sf::IntRect(64, 0, 32, 32));
	// standing still (down) frame
	stillDown.addFrame(sf::IntRect(0, 0, 32, 32));

	// face up by default and start at (0,0)
	animatedSprite.setAnimation(stillDown);
	//as.pause();
	animatedSprite.setPosition(0, 0);

	//walkingAnimation.addFrame(sf::IntRect(0, 0, 32, 32));
}

Player::~Player()
{
}

AnimatedSprite Player::update(sf::Event &event) {
	float speed = 45.0f; // 45px per second
	float delta = clock.restart().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//as.setAnimation(walkingAnimation);
		animatedSprite.play(walkingAnimation);
		animatedSprite.move(0.0f, speed * delta);
		//std::cout << "hi" << std::endl; -- for some reason, this has to be uncommented to make the walkingAnimation work correctly.
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
		animatedSprite.setAnimation(stillDown);
		//as.pause();
	}
	animatedSprite.update(clock.restart());
	return animatedSprite;
}