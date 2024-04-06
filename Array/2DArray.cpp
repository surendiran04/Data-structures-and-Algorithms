#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};//it is fully in stack

    int *B[3]; //both B and C pointers are in Stack
    int **C;
    int i, j;

    B[0] = (int *)malloc(4 * sizeof(int)); //these memories are created in heap
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));
  
    //these memories are created in heap - It is fully in heap except **C 
    C = (int **)malloc(3 * sizeof(int *));  //new int*[3]
    C[0] = (int *)malloc(4 * sizeof(int));  //new int[4]
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}
