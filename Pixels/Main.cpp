#include "Main.h"

int main(int argc, char* argv[])
{

	// sf::IntRect crops the image with the origins (0,0) and L,H (32,32)

	sf::RenderWindow window(sf::VideoMode(512, 512), "Derp");
	//window.setFramerateLimit(60);	//vba uses 20fps

	// put these somewhere else eventually (player tings)
	sf::Clock clock;
	sf::Texture	pTexture;
	Player player(pTexture);
	/*if (!pTexture.loadFromFile("img\\player\\male2.png"))
		return 2;*/
	sf::Packet packet;
	// networking
	sf::TcpSocket tsock;
	//Networking nt;


	// listen for incoming data from the server
	/*sf::TcpListener listen;
	listen.listen(tsock.AnyPort);
	listen.accept(tsock);
	 ShowWindow(GetConsoleWindow(), SW_HIDE);  -- for release version (hide the console) must inc windows.h */
	 //return 1 if connection not established
	//if (tsock.connect("127.0.0.1", 1337, sf::seconds(5.0f)) != sf::TcpSocket::Status::Done) return 1;


	//// recieve packet, extract contents, set values accordingly
	//// todo: make a function to do all this crap
	//tsock.receive(packet);
	//std::cout << "Recieved packet from server. Packet size: " << sizeof(packet) << " bytes" << std::endl;
	//int op;
	//std::string path, file, playerImg;
	//packet >> op >> path >> file >> playerImg;
	//std::cout << "Extracted packet contents successfully." << std::endl;
	//std::cout << "Setting map data and player data accordingly." << std::endl;
	tmx::MapLoader ml("img\\towns\\littleroot");
	if (!ml.Load("littleroot.tmx")) return 1;
	if (!pTexture.loadFromFile("img\\player\\male2.png")) return 1;
	//Sprite.setTexture(pTexture);
	
	
	
	

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
		window.clear();
		AnimatedSprite as = player.update(event);
		window.draw(ml);
		window.draw(as);
		//window.draw(Sprite);
		window.display();

	}
	return 0;
}