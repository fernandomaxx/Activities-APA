//
// Created by fernando on 19/03/19.
//

#include "graph_adjacency_matrix.h"

GraphAdjacencyMatrix::GraphAdjacencyMatrix( int size ) :
        size { size }
{
    matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }
    num_edges = 0;
}

GraphAdjacencyMatrix::~GraphAdjacencyMatrix( void )
{
    std::cout << "oi" << std::endl;
    for(int i = 0; i < size; ++i) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void GraphAdjacencyMatrix::addEdge( int v1, int v2, int weight )
{
    matrix[v1][v2] = weight;
    num_edges++;
}

bool GraphAdjacencyMatrix::isAdjacent( int v1, int v2 )
{
    return false;
}

void GraphAdjacencyMatrix::showGraph( void )
{
    int sum_weight = 0;
    for ( int i = 0; i < size; i++ )
    {
        for (int j = 0; j < size; ++j)
        {
            if ( matrix[i][j] > 0)
            {
                std::cout << i << j;
                sum_weight += matrix[i][j];
            }
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "The SUM WEIGHT is: " << sum_weight << std::endl;
}

int GraphAdjacencyMatrix::getNum_edges( void ) const
{
    return num_edges;
}
