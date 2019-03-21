#include <iostream>

#include <cstring>

#include "graph_adjacency_matrix.h"

struct t_edge{
    int weight;
    int v1, v2;
};

void insertionSort(t_edge *edges, int size)
{
    t_edge temp;
    for ( int i = 1; i < size; i++ )
    {
        temp = edges[i];
        int j = i - 1;

        while ( j >= 0 && temp.weight < edges[j].weight )
        {
            edges[j + 1] = edges[j];
            j--;
        }

        edges[j + 1] = temp;
    }
}

void showEdges( t_edge *edges, int size )
{
    for ( int i = 0; i < size; ++i )
    {
        std::cout << "Edge of " << edges[i].v1 << " for "<< edges[i].v2
                  << " with weight " << edges[i].weight << std::endl;

    }
}

/*** Algorithm union-find to search for cycles in the graph ***/
int *father;

int find( int x )
{
    //std::cout << x << std::endl;
    return ( father[x] == -1 ) ? x : find( father[x] );
}

void union_( int v1, int v2 )
{
    int father_v1 = find( v1 );
    int father_v2 = find( v2 );

    if ( father_v1 == father_v2 )
        return;

    father[father_v1] = v2;
}

int main()
{
    freopen( "input/dij40.txt", "r", stdin );
    clock_t t = clock();
    int size, weight;
    std::cin >> size;
    father = new int[size];
    memset( father, -1, sizeof(int[size]) );

    GraphAdjacencyMatrix graph( size ), mst( size );
    for ( int i = 0; i < size - 1; ++i )
    {
        for ( int j = i + 1; j < size; ++j )
        {
            std::cin >> weight;
            graph.addEdge( i, j, weight );
        }
    }

    //graph.showGraph();
    int num_edges = graph.getNum_edges(), count = 0;
    t_edge edges[num_edges];

    for ( int i = 0; i < size - 1; i++)
    {
        for ( int j = i + 1; j < size; j++ )
        {
            edges[count].v1 = i;
            edges[count].v2 = j;
            edges[count++].weight = graph.matrix[i][j];
        }
    }

    insertionSort( edges, num_edges );


    //showEdges( edges, num_edges );
    for ( int i = 0; i < num_edges; i++ )
    {
        if ( find( edges[i].v1 ) != find( edges[i].v2 ))
        {
            union_( edges[i].v1, edges[i].v2 );
            mst.addEdge( edges[i].v1, edges[i].v2, edges[i].weight );
        }
    }

    mst.showGraph();
    clock_t t2 = clock();
    clock_t final = t2 - t;
    //std::cout << "Processing Time is " << final << std::endl;



}
