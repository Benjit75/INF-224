CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lboost_system

all: server client

server: server.o Table.o tcpserver.o ccsocket.o Media.o Film.o Group.o
	$(CXX) $^ -o $@ $(LDFLAGS)

client: client.o ccsocket.o Media.o Film.o Group.o
	$(CXX) $^ -o $@ $(LDFLAGS)

server.o: server.cpp Table.h tcpserver.h ccsocket.h
	$(CXX) $(CXXFLAGS) -c $<

client.o: client.cpp ccsocket.h
	$(CXX) $(CXXFLAGS) -c $<

Table.o: Table.cpp Table.h Media.h Photo.h Video.h Film.h Group.h
	$(CXX) $(CXXFLAGS) -c $<

tcpserver.o: tcpserver.cpp tcpserver.h ccsocket.h Table.h
	$(CXX) $(CXXFLAGS) -c $<

tcpclient.o: tcpclient.cpp ccsocket.h
	$(CXX) $(CXXFLAGS) -c $<

ccsocket.o: ccsocket.cpp ccsocket.h
	$(CXX) $(CXXFLAGS) -c $<

Media.o: Media.cpp Media.h
	$(CXX) $(CXXFLAGS) -c $<

Film.o: Film.cpp Film.h Video.h
	$(CXX) $(CXXFLAGS) -c $<

Group.o: Group.cpp Group.h Media.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o server client
