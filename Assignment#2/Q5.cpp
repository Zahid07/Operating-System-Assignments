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

    char *binaryPath = "/bin/cat";
    string name="";
    cout<<"Please enter file name = ";cin>>name;
    int len=name.length();
    
    char *arg1 = new char[len+1];
    for(int i=0;i<len+1;i++){
        arg1[i]='\0';
    }

    for(int i=0;i<len;i++){
        arg1[i]=name[i];
    }


 
    int child1=fork();
    if(child1==0){
    execl( binaryPath, binaryPath,arg1, NULL);
    cout<<"Error Ocurred";
    return 0;
    }else if(child1>0){
        wait(NULL);
        cout<<"child_1 Terminated correctly"<<endl;
        int child2=fork();
        if(child2==0){
            char *binaryPath = "/bin/wc";
            cout<<endl;
            execl( binaryPath, binaryPath,arg1, NULL);
            cout<<"Error Ocurred";
    return 0;
        }else if(child2>0){
            wait(NULL);
            cout<<"child_2 Terminated correctly"<<endl;
            cout<<"All has gone well!"<<endl;
        }



    }


}