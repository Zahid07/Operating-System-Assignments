#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <cstring>
#include <iostream>
#include <sys/wait.h>
#include <fstream>
using namespace std;
//https://www.geeksforgeeks.org/merge-sort/  Merge sort function taken from here
struct array
{
    int *merg_array;
    int part;
    int threads;
    int length;
};

// merge function for merging two parts
void merge(int low, int mid, int high, int *&arr)
{
    int *left = new int[mid - low + 1];
    int *right = new int[high - mid];

    int n1 = mid - low + 1, n2 = high - mid, i, j;

    for (i = 0; i < n1; i++)
        left[i] = arr[i + low];

    for (i = 0; i < n2; i++)
        right[i] = arr[i + mid + 1];

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
    {
        arr[k++] = left[i++];
    }

    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void merge_sort(int low, int high, int *&arr)
{

    int mid = low + (high - low) / 2;
    if (low < high)
    {

        merge_sort(low, mid, arr);

        merge_sort(mid + 1, high, arr);

        merge(low, mid, high, arr);
    }
}

// thread function for multi-threading
void *merge_sort(void *arg)
{
    struct array *obj = (struct array *)arg;
    int thread_part = obj->part++;

    int low = thread_part * (obj->length / 4);
    int high = (thread_part + 1) * (obj->length / 4) - 1;

    int mid = low + (high - low) / 2;
    if (low < high)
    {
        merge_sort(low, mid, obj->merg_array);
        merge_sort(mid + 1, high, obj->merg_array);
        merge(low, mid, high, obj->merg_array);
    }
cout<<"Displaying the sorted chunk"<<endl;
    for(int i=low;i<high;i++){
        cout<<obj->merg_array[i]<<"  ";
    }
    cout<<endl;
}

int main(int argc, char *argv[])
{
    int id=fork();

    if(id==0){
        cout<<"Printing Mac address"<<endl;
            string str2 = "ip addr"; 
            const char *command2 = str2.c_str();
            system(command2);

            char *binaryPath = "/bin/sh";
            char *arg1 = "grep -m 1 'cpu cores' /proc/cpuinfo";
            execl( binaryPath, binaryPath,"-c",arg1, NULL);

    }else if(id>0){
        wait(NULL);
            array obj;
            obj.length = 20;
            obj.threads = 4;
            obj.part = 0;
            obj.merg_array = new int[obj.length];

                cout<<"Selected array is = ";
            for (int i = 0; i < obj.length; i++){
                obj.merg_array[i] = rand() % 256;
                cout<<obj.merg_array[i]<<"  ";
            }
        
        cout<<endl;
                


            pthread_t thread_2[obj.threads];

            for (int i = 0; i < obj.threads; i++){
                pthread_create(&thread_2[i], NULL, merge_sort,(void *)&obj);
            }

            for (int i = 0; i < 4; i++){
                pthread_join(thread_2[i], NULL);
            }

            // merging the final 4 parts
            merge(0, (obj.length / 2 - 1) / 2, obj.length / 2 - 1, obj.merg_array);
            merge(obj.length / 2, obj.length / 2 + (obj.length - 1 - obj.length / 2) / 2, obj.length - 1, obj.merg_array);
            merge(0, (obj.length - 1) / 2, obj.length - 1, obj.merg_array);

            cout << "Array after merge sort = ";
            for (int i = 0; i < obj.length; i++)
            {
                cout << obj.merg_array[i] << " ";
            }

            cout << endl;

            pthread_exit(NULL);
    }
    return 0;
}