#include "Main.h"

Player::Player(sf::Texture &texture) : animatedSprite(sf::seconds(0.2f)) {

	//animatedSprite(sf::seconds(0.2f));
	// map animation to a spritesheet
	walkDown.setSpriteSheet(texture);
	stillDown.setSpriteSheet(texture);
	walkUp.setSpriteSheet(texture);
	stillUp.setSpriteSheet(texture);
	walkRight.setSpriteSheet(texture);
	stillRight.setSpriteSheet(texture);
	walkLeft.setSpriteSheet(texture);
	stillLeft.setSpriteSheet(texture);
	// walking down frames
	walkDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkDown.addFrame(sf::IntRect(0, 0, 32, 32));
	walkDown.addFrame(sf::IntRect(64, 0, 32, 32));
	// standing still (down) frame
	stillDown.addFrame(sf::IntRect(0, 0, 32, 32));

	// walking up frames
	walkUp.addFrame(sf::IntRect(128, 0, 32, 32));
	walkUp.addFrame(sf::IntRect(96, 0, 32, 32));
	walkUp.addFrame(sf::IntRect(160, 0, 32, 32));
	// standing still (up) frame
	stillUp.addFrame(sf::IntRect(96, 0, 32, 32));

	// walking right frames
	walkRight.addFrame(sf::IntRect(256, 0, 32, 32));
	walkRight.addFrame(sf::IntRect(192, 0, 32, 32));
	walkRight.addFrame(sf::IntRect(224, 0, 32, 32));
	// standing still (right) frame
	stillRight.addFrame(sf::IntRect(192, 0, 32, 32));

	// walking left frames
	walkLeft.addFrame(sf::IntRect(320, 0, 32, 32));
	walkLeft.addFrame(sf::IntRect(288, 0, 32, 32));
	walkLeft.addFrame(sf::IntRect(352, 0, 32, 32));
	// standing still (right) frame
	stillLeft.addFrame(sf::IntRect(288, 0, 32, 32));

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

void Player::move(Direction direction) {
	float speed = 45.0f;
	
	switch (direction)
	{
	case Player::Down:
		animatedSprite.play(walkDown);
		animatedSprite.move(0.0f, speed * delta);
		//std::cout << speed * delta << std::endl;
		break;
	case Player::Up:
		animatedSprite.play(walkUp);
		animatedSprite.move(0.0f, -speed * delta);
		break;
	case Player::Right:
		animatedSprite.play(walkRight);
		animatedSprite.move(speed * delta, 0.0f);
		break;
	case Player::Left:
		animatedSprite.play(walkLeft);
		animatedSprite.move(-speed * delta, 0.0f);
		break;
	default:
		break;
	}

}

void Player::standStill(Direction direction) {
	switch (direction)
	{
	case Player::Down:
		animatedSprite.setAnimation(stillDown);
		break;
	case Player::Up:
		animatedSprite.play(stillUp);
		break;
	case Player::Right:
		animatedSprite.play(stillRight);
		break;
	case Player::Left:
		animatedSprite.play(stillLeft);
		break;
	default:
		break;
	}
}