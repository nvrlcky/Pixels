#include "Main.h"

int main(int argc, char* argv[])
{

	// sf::IntRect crops the image with the origins (0,0) and L,H (32,32)

	sf::RenderWindow window(sf::VideoMode(512, 512), "Derp");
	//window.setFramerateLimit(60);	//vba uses 20fps

	// put these somewhere else eventually (player tings)
	PlayerMovement pm;
	sf::Sprite Sprite;
	sf::Vector2i dirOrigin;
	sf::Clock clock;
	sf::Texture	pTexture;
	/*if (!pTexture.loadFromFile("img\\player\\male2.png"))
		return 2;*/
	sf::Packet packet;
	// networking
	sf::TcpSocket tsock;
	sf::Time timeout = sf::seconds(5.0f);
	//Networking nt;


	// listen for incoming data from the server
	/*sf::TcpListener listen;
	listen.listen(tsock.AnyPort);
	listen.accept(tsock);
	 ShowWindow(GetConsoleWindow(), SW_HIDE);  -- for release version (hide the console) must inc windows.h */
	 //return 1 if connection not established
	if (tsock.connect("127.0.0.1", 1337, timeout) != sf::TcpSocket::Status::Done) return 1;


	// recieve packet, extract contents, set values accordingly
	// todo: make a function to do all this crap
	tsock.receive(packet);
	std::cout << "Recieved packet from server. Packet size: " << sizeof(packet) << " bytes" << std::endl;
	int op;
	std::string path, file, playerImg;
	packet >> op >> path >> file >> playerImg;
	std::cout << "Extracted packet contents successfully." << std::endl;
	std::cout << "Setting map data and player data accordingly." << std::endl;
	tmx::MapLoader ml(path);
	if (!ml.Load(file)) return 1;
	if (!pTexture.loadFromFile(playerImg)) return 1;
	//Sprite.setTexture(pTexture);
	
	
	
	Animation walkingAnimation;
	Animation stillDown;
	walkingAnimation.setSpriteSheet(pTexture);
	stillDown.setSpriteSheet(pTexture);
	//walkingAnimation.addFrame(sf::IntRect(0, 0, 32, 32));
	walkingAnimation.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimation.addFrame(sf::IntRect(64, 0, 32, 32));
	stillDown.addFrame(sf::IntRect(0, 0, 32, 32));

	AnimatedSprite as(sf::seconds(0.5));
	as.setAnimation(stillDown);
	as.pause();
	as.setPosition(0, 0);

	 // elapsed time in seconds
	sf::Clock clockAs;
	sf::Event event;
	// game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// close window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
				window.close();	
		}
		float speed = 45.0f; // 45px per second
		float delta = clock.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			//as.setAnimation(walkingAnimation);
			//as.play(walkingAnimation);
			as.play(walkingAnimation);
			as.move(0, speed * delta);

		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down){
			as.setAnimation(stillDown);
			//as.pause();
		}
		as.update(clockAs.restart());
		//pm.initMovement(Sprite, pTexture, clock, dirOrigin);

		
		//window.draw(Sprite);
		window.clear();
		window.draw(ml);
		window.draw(as);
		window.display();

	}
	return 0;
}