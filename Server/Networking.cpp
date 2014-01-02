#include "Main.h"

Networking::Networking(){}
Networking::~Networking(){}

void Networking::extract(sf::Packet &packet) {

	std::string msg;
	int pint;

	if (packet >> msg) std::cout << msg << std::endl;
	if (packet >> pint) std::cout << pint << std::endl;

}

// send map packet
sf::TcpSocket::Status Networking::sendPacket(sf::Packet &packet, sf::TcpSocket &socket, sf::Uint16 op, sf::Uint16 sz, std::string path, std::string file, std::string playerImg) {

	sf::Uint16 szPath = path.size();
	sf::Uint16 szFile = file.size();
	sf::Uint16 szPlayerImg= playerImg.size();
	sz = sizeof(op + sz + szPath + szFile + szPlayerImg);
	packet << op << sz << path << file << playerImg;
	if (socket.send(packet)) return sf::TcpSocket::Status::Done;
	else return sf::TcpSocket::Status::Error;
}