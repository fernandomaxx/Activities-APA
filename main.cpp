
#include <iostream>
#include <time.h>
//#include <cstdlib>
//#include <ctime>
#define FATHER( POS ) ( (POS - 1) / 2 )
#define S_LEFT( POS ) ( POS * 2 + 1 )
#define S_RITGH( POS ) ( POS * 2 + 2 )
#define SIZE 100

using namespace std;

typedef struct {
    int size;
    int heap_item[SIZE];
}tHeap;

void build( int pos, int vec[], int size )
{
    int aux = vec[pos], temp = pos;

    if ( S_LEFT( pos ) < size && aux < vec[S_LEFT( pos )] )
    {
        temp = S_LEFT( pos );
        aux = vec[temp];
    }

    if ( S_RITGH( pos ) < size && aux < vec[S_RITGH( pos )] )
    {
        temp = S_RITGH( pos );
        aux = vec[temp];
    }

    if ( pos != temp )
    {
        vec[temp] = vec[pos];
        vec[pos] = aux;
        build( temp, vec, size );
    }
}

void buildHeap( int vec[], int size )
{
    for ( int i = (size - 2) / 2; i >= 0; --i ) 
	{
        build( i, vec, size );
    }

}

void heapSort( int vec[], int size )
{
    int aux;
    while ( size > 1 )
    {
        aux = vec[size - 1];
        vec[size - 1] = vec[0];
        vec[0] = aux;
        build( 0, vec, --size );
    }
}

void selectionSort(int *vector, int size) {
    int temp = vector[0], index;

    for (int i = 0; i < size - 1; i++) {
        temp = vector[i];

        for (int j = i + 1; j < size; j++) {
            if (vector[j] < temp) {
                temp = vector[j];
                index = j;
            }
        }
        vector[index] = vector[i];
        vector[i] = temp;

    }

}

void insertionSort(int *vector, int size) {
    int temp;
    for (int i = 1; i < size; i++) {
        temp = vector[i];
        int j = i - 1;

        while (j >= 0 && temp < vector[j]) {
            vector[j + 1] = vector[j];
            j--;
        }

        vector[j + 1] = temp;
    }
}

void countSort(int *vector, int size) {
    int temp = vector[0];
    for (int i = 1; i < size; ++i) {
        if (temp < vector[i])
            temp = vector[i];
    }
    int aux[temp+1] = {0};
    int sort[size];

    for (int i = 0; i < size; ++i) {
        aux[vector[i]]++;
    }

    for (int i = 1; i < temp+1; ++i) {
        aux[i] += aux[i - 1];
    }

    for (int i = 0; i < size; ++i) {
        sort[aux[vector[i]] - 1] = vector[i];
        aux[vector[i]]--;
    }

    for (int i = 0; i < size; ++i) {
        vector[i] = sort[i];
    }
}

void countSort(int *vector, int size, int exp) {
    int aux[10] = {0};
    int out[size];

    for (int i = 0; i < size; ++i) {
        aux[(vector[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        aux[i] += aux[i - 1];
    }

    for (int i = size-1; i >= 0 ; ++i) {
        out[aux[(vector[i] / exp) % 10]] = vector[i];
    }

    for (int i = 0; i < size; ++i) {
        vector[i] = out[i];
    }


}

void radixSort(int *vector, int size) {
    int temp = vector[0];
    for (int i = 1; i < size; ++i) {
        if (temp < vector[i])
            temp = vector[i];
    }

    for (int exp = 1; temp/exp > 0 ; exp *= 10) {
        countSort(vector, size, exp);
    }

}

int main(int argc, char *argv[]) {
    clock_t end, start;
    int size;
    freopen("input.in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> size;
    int vector[size], vector_2[size], vector_3[size];

    for (int i = 0; i < size; ++i) {
        std::cin >> vector[i];
        vector_2[i] = vector[i];
        vector_3[i] = vector[i];
        cout << vector[i] << " ";
    }
    cout << endl << endl;

    cout << "Sorting vector with Insertion Sort" << endl;

    start = clock();
    insertionSort(vector, size);
    end = clock();
    printf("Processing time: %4.0f ms\n\n", 1000 * (double) (end - start) / (double) (CLOCKS_PER_SEC));

    cout << "Vector ordered with Insertion Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
    cout << endl << endl;

    cout << "Sorting vector with Selection Sort" << endl;

    start = clock();
    selectionSort(vector_2, size);
    end = clock();
    printf("Processing time: %4.0f ms\n\n", 1000 * (double) (end - start) / (double) (CLOCKS_PER_SEC));

    cout << "Vector ordered with Selection Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << vector_2[i] << " ";
    }
    cout << endl;

    cout << "Sorting vector with Count Sort" << endl;

    start = clock();
    countSort(vector_3, size);
    end = clock();
    printf("Processing time: %4.0f ms\n\n", 1000 * (double) (end - start) / (double) (CLOCKS_PER_SEC));

    cout << "Vector ordered with Count Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << vector_3[i] << " ";
    }
    cout << endl;

    cout << "Sorting vector with Radix Sort" << endl;

    start = clock();
    countSort(vector_3, size);
    end = clock();
    printf("Processing time: %4.0f ms\n\n", 1000 * (double) (end - start) / (double) (CLOCKS_PER_SEC));

    cout << "Vector ordered with Radix Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << vector_3[i] << " ";
    }

    return 0;
}

/*
int main()
{
    tHeap heap;
    heap.size = 20;
    int j = 0;
    for ( int i = heap.size - 1; i >= 0; --i )
    {
        heap.heap_item[i] = rand() % 100;
    }

    for ( int i = 0; i < heap.size; ++i )
    {
        std::cout << heap.heap_item[i] << " ";
    }
    std::cout << std::endl;

    buildHeap( heap.heap_item, heap.size );
    for ( int i = 0; i < heap.size; ++i )
    {
        std::cout << heap.heap_item[i] << " ";
    }
    std::cout << std::endl;
    heapSort( heap.heap_item, heap.size );

    for ( int i = 0; i < heap.size; ++i )
    {
        std::cout << heap.heap_item[i] << " ";
    }
    std::cout << std::endl;
}
*/