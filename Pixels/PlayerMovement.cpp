#include "Main.h"

PlayerMovement::PlayerMovement()
{
	// constructor
}

PlayerMovement::~PlayerMovement()
{
}

void PlayerMovement::initMovement(sf::Sprite &sprite, AnimatedSprite &as, sf::Texture &texture, sf::Clock &clock, sf::Vector2i &origin) {
	float speed = 100.0f; // 50px per second
	float delta = clock.restart().asSeconds(); // elapsed time in seconds

	Animation walkingAnimation;
	Animation stillDown;
	walkingAnimation.setSpriteSheet(texture);
	stillDown.setSpriteSheet(texture);
	//walkingAnimation.addFrame(sf::IntRect(0, 0, 32, 32));
	walkingAnimation.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimation.addFrame(sf::IntRect(64, 0, 32, 32));
	stillDown.addFrame(sf::IntRect(0, 0, 32, 32));

	//AnimatedSprite as(sf::seconds(0.5));
	as.setAnimation(stillDown);
	as.pause();
	as.setPosition(0, 0);
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		
		origin.x = Left;
		sprite.move(-speed * delta, 0);
		std::cout << -speed * delta << std::endl;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		origin.x = Right;
		sprite.move(speed * delta, 0.0f);
		std::cout << speed * delta << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		origin.x = Up;
		sprite.move(0, -speed * delta);
		std::cout << -speed * delta << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		as.play(walkingAnimation);
		as.move(0.0f, speed * delta);
		/*origin.x = Down;
		sprite.move(0, speed * delta);*/
		std::cout << speed * delta << std::endl;
		
	}


	//sprite.setTextureRect(sf::IntRect(origin.x, origin.y, 32, 32));

}