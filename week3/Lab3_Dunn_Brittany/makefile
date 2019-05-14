Lab3: LabMain.o Game.o Menu.o getInt.o Die.o Player.o LoadedDie.o
	g++ LabMain.o Game.o Menu.o getInt.o Die.o Player.o LoadedDie.o -std=c++0x -o Lab3

LabMain.o: LabMain.cpp
	g++ -std=c++0x -c LabMain.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++0x -c Game.cpp

Menu.o: Menu.hpp Menu.cpp
	g++ -std=c++0x -c Menu.cpp

getInt.o: getInt.cpp getInt.hpp
	g++ -std=c++0x -c getInt.cpp

Die.o: Die.cpp Die.hpp
	g++ -std=c++0x -c Die.cpp

Player.o: Player.cpp Player.hpp
	g++ -std=c++0x -c Player.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -std=c++0x -c LoadedDie.cpp

clean:
	rm *.o Lab3

