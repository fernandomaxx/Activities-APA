#include "simpleQuickSort.h"

void troca(int *p, int *q)
{
    int aux = *p;
    *p = *q;
    *q = aux;
}

void quickSort(int ar[], int inf, int sup)
{
    int i, j, pivo;
    if (inf >= sup)
        return;

    pivo = inf;

    for (i = inf, j = sup; i < j;) {

        while (ar[i] <= ar[pivo] && i < sup)
            ++i;

        while (ar[j] > ar[pivo])
            --j;

        if (i < j)
            troca(ar + i, ar + j);
    }
    troca(ar + pivo, ar + j);
    quickSort(ar, inf, j - 1);
    quickSort(ar, j + 1, sup);
}