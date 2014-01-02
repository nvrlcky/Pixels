#pragma once
class Networking
{
public:
	Networking();
	~Networking();
	void extract(sf::Packet &packet);
	sf::TcpSocket::Status sendPacket(sf::Packet &packet, sf::TcpSocket &socket, sf::Uint16 op, sf::Uint16 sz, std::string path, std::string file, std::string playerImg); // map packet
};