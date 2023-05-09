#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Table.h"

const int PORT = 3331;

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
  return str;
}

int main(int argc, char* argv[])
{
  // create the Table object
  Table table;

  // create the TCPServer
  auto* server =
      new TCPServer([&](std::string const& request, std::string& response) {

        // Replace all '\n' with ';'
        std::string req = replaceAll(request, "\n", ";");

        // the request sent by the client to the server
        std::cout << "request: " << req << std::endl;

        // Parse the request string
        std::stringstream ss(req);
        std::string command;
        ss >> command;

        // Execute the appropriate method based on the command
        if (command == "PLAY") {
          std::string arg;
          ss >> arg;
          table.play(arg);
          response = "PLAY command executed";
        } else if (command == "SEARCH-MEDIA") {
          std::string arg;
          ss >> arg;
          std::stringstream stream;
          table.searchAndDisplayMedia(arg, stream);
          response = stream.str();
        } else if (command == "SEARCH-GROUP") {
          std::string arg;
          ss >> arg;
          stringstream stream;
          table.searchAndDisplayGroup(arg, stream);
          response = stream.str();
        } else if (command == "CREATE") {
          string type;
          stringstream stream;
          ss >> type;
          if (type == "Photo"){
            string name, pathname;
            int longitude, latitude;
            try
            {
              ss >> name >> pathname  >> latitude >> longitude;
              PhotoPtr photo = table.createPhoto(name, pathname, latitude, longitude);
              photo->displayInfo(stream);
            }
            catch(const std::exception& e)
            {
              PhotoPtr photo = table.createPhoto();
              photo->displayInfo(stream);
            }
            response = "CREATE command done:\n"+ stream.str();
          } else if (type == "Video"){
            string name, pathname;
            int duration;
            try
            {
              ss >> name >> pathname  >> duration;
              VideoPtr video = table.createVideo(name, pathname, duration);
              video->displayInfo(stream);
            }
            catch(const std::exception& e)
            {
              VideoPtr video = table.createVideo();
              video->displayInfo(stream);
            }
            response = "CREATE command done:\n"+ stream.str();
          } else if (type == "Film"){
            string name, pathname;
            int* chapters = nullptr;
            int numberOfChapters = 0;
            int duration;
            try
            {
              ss >> name >> pathname  >> duration;
              FilmPtr film = table.createFilm(name, pathname, duration, chapters, numberOfChapters);
              film->displayInfo(stream);
            }
            catch(const std::exception& e)
            {
              FilmPtr film = table.createFilm();
              film->displayInfo(stream);

            }
            response = "CREATE command done:\n"+ stream.str();
          } else if (type == "Group"){
            string name;
            try
            {
              ss >> name;
              GroupPtr group = table.createGroup(name);
              group->displayInfo(stream);
            }
            catch(const std::exception& e)
            {
              GroupPtr group = table.createGroup();
              group->displayInfo(stream);
            }
            response = "CREATE command done:\n"+ stream.str();
          } else {
            response = "CREATE command with no correct type";
          }
        } else if (command == "QUIT") {
          response = "QUIT";
          // Returning false will close the connection with the client
          return false;
        } else {
          response = "Unrecognized command";
        }

        // Replace all '\n' with ';'
        response = replaceAll(response, "\n", ";");

        // return true to keep the connection with the client open
        return true;
      });

  // launch the server's infinite loop
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // in case of error
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}
