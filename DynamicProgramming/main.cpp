#include <iostream>
#include <vector>
#define DEBUG 0

std::pair< int, int> greater( int a, int b )
{
    if ( a >= b )
        return std::make_pair( a, 0 );

    return std::make_pair( b, 1 );
}

int main()
{
    freopen( "mochila02.txt.txt", "r", stdin );
    int size, capacity, *weight, *value, *X;
    std::cin >> size;
    std::cin >> capacity;
    weight = new int[size + 1];
    value = new int[size + 1];
    X = new int[size + 1];
    typedef std::pair< int, int> pair_int;
    pair_int mem[capacity + 1][size + 1];

    for ( int i = 1; i <= size; ++i )
    {
        std::cin >> weight[i];
        std::cin >> value[i];
        X[i] = 0;
    }

    for ( int i = capacity; i >= 0; --i )
    {
        mem[i][4].first = 0;
        mem[i][4].second = -1;
    }

    for ( int i = size - 1; i >= 0 ; --i )
    {
        for ( int y = 0; y <= capacity ; ++y )
        {
            int sub = y - weight[i + 1];
            if ( sub >= 0 )
                mem[y][i] = greater( mem[y][i + 1].first, mem[sub][i + 1].first + value[i + 1] );
            else
                mem[y][i] = std::make_pair( mem[y][i + 1].first, 0 );
        }
    }

    std::cout << mem[capacity][0].first << std::endl;
    int aux = capacity;

    for ( int i = capacity; i >= 0; --i )
    {
        for ( int j = 0; j <= size; ++j )
        {
            if ( mem[i][j].second == 1 )
            {
                aux -= weight[j + 1];
                i = aux;
                X[j + 1] = 1;
                std::cout << j + 1 << " ";
            }
        }
    }

#if DEBUG

    std::cout << " ";

    for ( int i = 0; i <= size; ++i )
    {
        printf("   %d  ", i);
    }
    std::cout << std::endl;

    for ( int i = 0; i <= capacity; ++i )
    {
        std::cout << i << " ";
        for ( int j = 0; j <= size; ++j )
        {
            printf("%d - %d ", mem[i][j].first, mem[i][j].second);
        }
        std::cout << std::endl;
    }
#endif
}


