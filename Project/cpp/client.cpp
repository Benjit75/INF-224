//
// Client C++ pour communiquer avec un serveur TCP
// eric lecolinet - telecom paristech - 2016/2020
//

#include <iostream>
#include <string>
#include <algorithm>
#include "ccsocket.h"

static const std::string HOST = "127.0.0.1";
static const int PORT = 3331;

int main() {
  Socket sock;
  SocketBuffer sockbuf(sock);

  int status = sock.connect(HOST, PORT);

  if (status < 0) {
    switch (status) {
      case Socket::Failed:
        std::cerr << "Client: Couldn't reach host " << HOST << ":" << PORT << std::endl;
        return 1;
      case Socket::UnknownHost:
        std::cerr << "Client: Couldn't find host " << HOST << ":" << PORT << std::endl;
        return 1;
      default:
        std::cerr << "Client: Couldn't connect host " << HOST << ":" << PORT << std::endl;
        return 1;
    }
  }

  std::cout << "Client connected to " << HOST << ":" << PORT << std::endl;

  while (std::cin) {
    std::cout << "Request: ";
    std::string request, response;

    std::getline(std::cin, request);

    // Replace '\n' with ';' in the request string
    std::replace(request.begin(), request.end(), '\n', ';');

    // Send the request to the server
    if (sockbuf.writeLine(request) < 0) {
      std::cerr << "Client: Couldn't send message" << std::endl;
      return 2;
    }
    
    if (request == "QUIT") return 0;

    // Receive the response from the server
    if (sockbuf.readLine(response) < 0) {
      std::cerr << "Client: Couldn't receive message" << std::endl;
      return 2;
    }

    // Replace ';' with '\n' in the response string
    std::replace(response.begin(), response.end(), ';', '\n');

    std::cout << "Response: " << response << std::endl;
  }

  return 0;
}
