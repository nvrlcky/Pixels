#pragma once

class Networking
{
public:
	Networking();
	~Networking();
	sf::Packet createPacket(std::string msg);
	bool sendPacket(sf::Packet &packet);
	void sendPacket(sf::Packet &packet, sf::TcpSocket &socket, sf::Sprite &sprite);

};

struct data
{
	std::string path = "\\img\\male2.png";
	sf::Int8 op = 0;
	std::string file = "littleroot.tmx";
};

//sf::Packet& operator << (sf::Packet &packet, const data& data) {
//	return packet << data.file;
//}