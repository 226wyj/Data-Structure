main: main.cpp AdjacencyMatrix.o
	g++ -std=c++11 -o main main.cpp AdjacencyMatrix.o

AdjacencyMatrix.o:
	g++ -std=c++11 -c -o AdjacencyMatrix.o AdjacencyMatrix.cpp
	
clean:
	rm -f main *~, AdjacencyMatrix *.o
