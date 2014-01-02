#include "Main.h"

// 
// 
// 
// THIS IS THE SERVER NIGGGGGAAA
// 
// 
// 
int main() {
	sf::TcpSocket tsock;
	tsock.connect("127.0.0.1", tsock.AnyPort);

	sf::TcpListener listener;
	listener.listen(1337);
	listener.setBlocking(true);
	sf::Packet packet;
	Networking nt;

	std::cout << "Awaiting connection....." << std::endl;
	// establish connect when connection is recieved and store return
	sf::TcpSocket::Status status = listener.accept(tsock);

	// packet listen loop runs only when status returns Done (0)
	while (status == tsock.Done)
	{
		std::cout << "connected to: " << tsock.getRemoteAddress() << " on port (" << tsock.getRemotePort() << ")" << std::endl;
		//packet << "hello";
		//tsock.send(packet);
		packet.clear();
		int op = 0;
		packet << op << "img\\towns\\littleroot" << "littleroot.tmx" << "img\\player\\male2.png";
		sf::TcpSocket::Status status = tsock.send(packet);
		if  (status == sf::TcpSocket::Status::Done)
		std::cout << "sent the packet ^_^" << std::endl;
		else return 1;
		// recieve data from the client
		/*tsock.receive(packet);
		nt.extract(packet);*/

		// recheck to see if the socket disconnected or not
		status = listener.accept(tsock);
	}
	return 0;
}
