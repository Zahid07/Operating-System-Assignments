#include<iostream>
#include<unistd.h>
#include<fstream>
#include<string>
#include<time.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<fcntl.h>

using namespace std;
int main(){
    string input="";
    cout<<"Please enter string = ";cin>>input;
    int len=input.length();
    
    char *args = new char[len+1];
    for(int i=0;i<len+1;i++){
        args[i]='\0';
    }

    for(int i=0;i<len;i++){
        args[i]=input[i];
    }
    //cout<<"Q7 pid is = "<<getpid()<<endl;
    int child1=fork();
    if(child1==0){
            //cout<<"Q7 child pid is = "<<getpid()<<endl;
             execl("./output1",args,NULL);
    }else{
        wait(NULL);
    }


    return 0;    


}