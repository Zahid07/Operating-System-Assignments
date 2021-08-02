#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
string filename="";

void *file1(void *arg)
{
    char *current_char_count = (char *)arg;
    int n = 0;
    int count=0;
    cout<<*current_char_count<<"  and   "<<char(*current_char_count-32)<<endl;

     ifstream  fin(filename);
        char ch;
        int i, c=0, sp=0;
        while(fin)
        {
                fin.get(ch);
                i=ch;
                if(i==*current_char_count  ||  i==char(*current_char_count-32))
                        count+=1;
             
        }
    int *answer=new int;
    *answer=count;
   
   
    pthread_exit(answer);
}



int main(int argc, char *argv[])
{
    
    void *ans1;
    filename = argv[1];
    int *characters=new int[26];
    for(int i=0;i<26;i++){
        characters[i]=0;
    }

    cout << "Going to count characters of file 1" << endl;
    pthread_t thread_2[26];
    int current_count = 0;
    char current_char_count='a';
    int total_count=0;

    while(current_count!=26){
    int i = pthread_create(thread_2+current_count, NULL, file1, &current_char_count);
    pthread_join(*(thread_2+current_count), &ans1);
    total_count+=*(int *)ans1;
    current_char_count+=1;
    current_count+=1;
    }



    cout << "Character count of file 1 is = " << total_count << endl;
    cout << endl;
    cout << endl;

 

    pthread_exit(NULL);
    return 0;
}