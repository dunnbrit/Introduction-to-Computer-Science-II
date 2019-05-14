
Lab2: Lab2Main.o countLetters.o outputLetters.o
	g++ Lab2Main.o countLetters.o outputLetters.o -std=c++0x -o Lab2 

Lab2Main.o: Lab2Main.cpp
	g++ -std=c++0x -c Lab2Main.cpp

countLetters.o: countLetters.cpp countLetters.hpp
	g++ -std=c++0x -c countLetters.cpp

outputLetters.o: outputLetters.cpp outputLetters.hpp
	g++ -std=c++0x -c outputLetters.cpp

clean:
	rm *.o Lab2
