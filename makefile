run:
	g++ -std=c++11 Server/*.cpp Client.cpp -o client.out -pthread
	g++ -std=c++11 Server/*.cpp server.cpp -o server.out -pthread
clean:
	rm -rf *.out
