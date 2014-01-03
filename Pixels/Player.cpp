#include "Main.h"

Player::Player(sf::Texture &texture) : animatedSprite(sf::seconds(0.6f)) {

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

AnimatedSprite Player::getSprite() {
	animatedSprite.update(clock.restart());
	return animatedSprite;
}

void Player::setDirection(Direction direction) {
	float speed = 45.0f; // 100px per second
	float delta = dirClock.restart().asSeconds();
	switch (direction)
	{
	case Player::Down:
		animatedSprite.play(walkingAnimation);
		animatedSprite.move(0.0f, speed * delta);
		std::cout << speed * delta << std::endl;
		break;
	case Player::Up:
		animatedSprite.play(walkingAnimation);
		animatedSprite.move(0.0f, -speed * delta);
		break;
	case Player::Right:
		animatedSprite.play(walkingAnimation);
		animatedSprite.move(speed * delta, 0.0f);
		break;
	case Player::Left:
		animatedSprite.play(walkingAnimation);
		animatedSprite.move(-speed * delta, 0.0f);
		break;
	default:
		break;
	}

}