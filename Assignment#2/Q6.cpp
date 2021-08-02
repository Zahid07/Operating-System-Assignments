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
while(1){
  char *binaryPath = "/bin/bash";
  cout<<"Please enter commands = ";getline(cin,input);
  if(input=="EXIT" || input=="exit"){
    cout<<"Exiting"<<endl;;
    return 0;
  }
 int len=input.length();
 char *arg1 = new char[len];
 for(int i=0;i<len;i++){
     arg1[i]=input[i];
 }

int child1=fork();
      if(child1==0){
       execl( binaryPath, binaryPath,"-c",arg1, NULL);
      }else{
        wait(NULL);
      }

}

}