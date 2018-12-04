
#include <iostream>
#include <time.h>
//#include <cstdlib>
//#include <ctime>

using namespace std;

void selectionSort(int *vector, int size)
{
    int temp = vector[0], index;

    for (int i = 0; i < size - 1; i++) {
        temp = vector[i];

        for (int j = i+1; j < size; j++) {
            if (vector[j] < temp) {
                temp = vector[j];
                index = j;
            }
        }
        vector[index] = vector[i];
        vector[i] = temp;

    }

}

void insertionSort(int *vector, int size)
{	
    int temp;
    for (int i = 1; i < size; i++) {
        temp = vector[i];
        int j = i - 1;

        while (j >= 0 && temp < vector[j]) {
            vector[j+1] = vector[j];
            j--;
        }

        vector[j + 1] = temp;
    }
}

int main(int argc, char *argv[])
{	
	clock_t end,start;
	int size;
	freopen(argv[1], "r", stdin);
	freopen("out", "w", stdout);
	cin >> size;
	int vector[size], vector2[size];

	for (int i = 0; i < size; ++i) {
		std::cin >> vector[i];
		vector2[i] = vector[i];
		cout << vector[i] << " ";
	}
	cout << endl << endl;
	
	cout << "Sorting vector with Insertion Sort" << endl;

	start = clock();
    insertionSort( vector, size);
	end = clock();
   	printf("Processing time: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));

	cout << "Vector ordered with Insertion Sort" << endl;

	for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
	cout << endl << endl;

	cout << "Sorting vector with Selection Sort" << endl;

	start = clock();
    selectionSort( vector2, size);
	end = clock();
   	printf("Processing time: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));
	
	cout << "Vector ordered with Selection Sort" << endl;

    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }

    return 0;
}
