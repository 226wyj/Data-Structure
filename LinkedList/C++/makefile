main: main.cpp LinkedList.o Node.o
	g++ -std=c++11 -o main main.cpp LinkedList.o Node.o

LinkedList.o: Node.o
	g++ -std=c++11 -c -o LinkedList.o LinkedList.cpp Node.o
	
Node.o:
	g++ -std=c++11 -c -o Node.o Node.cpp

clean:
	rm -f main *~, LinkedList *.o, Node *.o
