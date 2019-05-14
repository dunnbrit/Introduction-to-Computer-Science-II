Lab7: LabMain.o QueueNode.o getInt.o Menu.o Queue.o
	g++ LabMain.o QueueNode.o getInt.o Menu.o Queue.o -std=c++0x -o Lab7

LabMain.o: LabMain.cpp
	g++ -std=c++0x -c LabMain.cpp

QueueNode.o: QueueNode.cpp QueueNode.hpp
	g++ -std=c++0x -c QueueNode.cpp

getInt.o: getInt.cpp getInt.hpp
	g++ -std=c++0x -c getInt.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -std=c++0x -c Queue.cpp

clean:
	rm *.o Lab7
