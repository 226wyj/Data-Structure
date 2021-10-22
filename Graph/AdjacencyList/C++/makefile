main: main.cpp AdjacencyList.o
	g++ -std=c++11 -o main main.cpp AdjacencyList.o

AdjacencyList.o:
	g++ -std=c++11 -c -o AdjacencyList.o AdjacencyList.cpp
	
clean:
	rm -f main *~, AdjacencyList *.o
