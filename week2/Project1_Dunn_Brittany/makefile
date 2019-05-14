
Project1: Project1Main.o Menu.o startGame.o getInt.o Ant.o
	g++ Project1Main.o Menu.o startGame.o getInt.o Ant.o -std=c++0x -o Project1

Project1Main.o: Project1Main.cpp
	g++ -c Project1Main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

startGame.o: startGame.cpp startGame.hpp
	g++ -c startGame.cpp

getInt.o: getInt.cpp getInt.hpp
	g++ -std=c++0x -c getInt.cpp

Ant.o: Ant.cpp Ant.cpp
	g++ -c Ant.cpp

clean:
	rm *.o Project1
