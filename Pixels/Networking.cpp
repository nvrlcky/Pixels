#include "Main.h"


Networking::Networking()
{
}


Networking::~Networking()
{
}

void Networking::sendPacket(sf::Packet &packet, sf::TcpSocket &socket, sf::Sprite &sprite) {

}

bool Networking::sendPacket(sf::Packet &packet) {
	sf::TcpSocket socket;
	if (!socket.send(packet)) {
		return false;
	} return true;
}

sf::Packet Networking::createPacket(std::string msg) {
	sf::Packet packet;
	packet << msg;
	return packet;
}

