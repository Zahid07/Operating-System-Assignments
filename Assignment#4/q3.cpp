#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
struct matrices
{
    int **matrix1;
    int **matrix2;

    int **res_matrix;
};
int ptr = -1;
int *curr_ii = new int[9];
int *curr_jj = new int[9];
int *curr_ptr = new int[9];

void *multiply(void *arg)
{
    struct matrices *obj = (struct matrices *)arg;
    int j = 0;
    ptr += 1;

    for (int i = 0; i < 3; i++)
    {
        obj->res_matrix[curr_ii[curr_ptr[ptr]]][curr_jj[curr_ptr[ptr]]] += obj->matrix1[curr_ii[curr_ptr[ptr]]][i] * obj->matrix2[i][curr_jj[curr_ptr[ptr]]];
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    matrices obj;
    obj.matrix1 = new int *[3];
    obj.matrix2 = new int *[3];
    obj.res_matrix = new int *[3];

    // Making Matrices
    for (int i = 0; i < 3; i++)
    {
        obj.matrix1[i] = new int[3];
        obj.matrix2[i] = new int[3];
        obj.res_matrix[i] = new int[3];
    }

    //Initializing matrices
    int num = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            obj.matrix2[i][j] = num;
            obj.matrix1[i][j] = num;
            obj.res_matrix[i][j] = 0;
            num += 1;
        }
    }

    pthread_t thread_2[9];

    int curr_i = 0;
    int curr_j = 0;

    for (int i = 0; i <= 8; i++)
    {
        curr_ii[i] = curr_i;
        curr_jj[i] = curr_j;
        if (curr_j == 2)
        {
            curr_j = 0;
            curr_i += 1;
        }
        else
        {
            curr_j += 1;
        }
    }

    for (int i = 0; i <= 8; i++)
    {
        curr_ptr[i] = i;
        int k = pthread_create(&thread_2[i], NULL, multiply, (void *)&obj);
    }

    for (int j = 0; j <= 8; j++)
    {
        pthread_join(thread_2[j], NULL);
    }
    cout << "Matrix is = " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << obj.res_matrix[i][j] << ' ';
        }
        cout << endl;
    }

    pthread_exit(NULL);
    return 0;
}