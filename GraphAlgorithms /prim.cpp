//
// Created by fernando on 19/03/19.
//

#include "graph_adjacency_list.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <limits>
#define SIZE 50

int distance[SIZE], size, cost = 0;
int infinity = std::numeric_limits< int >::max();
bool processed[SIZE];
GraphAdjacencyList *graph, *mst;

std::priority_queue < std::pair< int, int* >,
std::vector< std::pair< int, int* > >, std::greater< std::pair< int, int* > > > pq;

int prim( void )
{
    for ( int i = 0; i < size; ++i )
    {
        distance[i] = infinity;
        processed[i] = false;
    }

    distance[0] = 0;
    int init = 0;
    pq.push( std::make_pair( 0, &init ) );

    while ( true )
    {
        int actual = -1;

        while ( !pq.empty() )
        {
            int temp = *pq.top().second;
            pq.pop();

            if ( !processed[temp] )
            {
                processed[temp] = true;
                actual = temp;
                break;
            }
        }

        if ( actual == -1 )
            break;

        for ( int i = 0; i < graph->adj[actual].size(); ++i )
        {

            if ( distance[graph->adj[actual][i].first] > graph->adj[actual][i].second  && !processed[graph->adj[actual][i].first] )
            {
                distance[graph->adj[actual][i].first] = graph->adj[actual][i].second;
                pq.push( std::make_pair( graph->adj[actual][i].second, &graph->adj[actual][i].first ) );
            }
        }

    }
    for(int i = 0;i < size;i++) cost += distance[i];

}

//void createMst( void )
//{
//    bool added[7] = { false, false, false, false, false, false, false };
//    bool processed[7] = { false, false, false, false, false, false, false };
//    pq.push( std::make_pair( 0, 1 ) );
//
//
//    while ( true )
//    {
//
//        int actual = -1;
//
//        while ( !pq.empty() )
//        {
//            int temp = pq.top().second;
//            pq.pop();
//
//            if ( !processed[temp] )
//            {
//                processed[temp] = true;
//                actual = temp;
//                break;
//            }
//        }
//
//        if ( actual == -1 )
//            break;
//
//        for ( int i = 0; i < graph->adj[actual].size(); ++i )
//        {
//
//            if ( !processed[graph->adj[actual][i].first] )
//            {
//                if ( distance[graph->adj[actual][i].first] == graph->adj[actual][i].second && !added[graph->adj[actual][i].first] )
//                {
//                    mst->addEdge( actual, graph->adj[actual][i].first, distance[graph->adj[actual][i].first]);
//                    added[graph->adj[actual][i].first] = true;
//                }
//                pq.push( std::make_pair( graph->adj[actual][i].second, graph->adj[actual][i].first ) );
//            }
//        }
//    }
//}

int main()
{
    freopen( "input/dij40.txt", "r", stdin );
    clock_t t = clock();
    int weight;
    std::cin >> size;
    graph = new GraphAdjacencyList( size );
    for ( int i = 0; i < size - 1; ++i )
    {
        for ( int j = i + 1; j < size; ++j )
        {
            std::cin >> weight;
            graph->addEdge( i, j, weight );
            graph->addEdge( j, i, weight );
        }
    }

    mst = new GraphAdjacencyList( size );
    prim();
    //createMst();
    for ( int i = 0; i < size; ++i )
    {
        for ( int j = 0; j < mst->adj[i].size(); ++j )
        {
            std::cout << i << mst->adj[i][j].first << std::endl;
        }
    }
    std::cout << cost << std::endl;
}

