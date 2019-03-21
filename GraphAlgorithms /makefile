CC = g++
all: kruskal dijkstra prim clean

prim:prim.cpp graph_adjacency_list.cpp
	$(CC) -o prim prim.cpp graph_adjacency_list.cpp -I.

dijkstra:dijkstra.cpp graph_adjacency_list.cpp
	$(CC) -o dijkstra dijkstra.cpp graph_adjacency_list.cpp -I.

kruskal:kruskal.cpp graph_adjacency_matrix.cpp
	$(CC) -o kruskal kruskal.cpp graph_adjacency_matrix.cpp -I.

clean:
	rm -rf *.o

mrproper: clean
	rm -rf kruskal dijkstra prim
