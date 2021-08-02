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

  char *binaryPath = "/bin/bash";
  //char *arg1 = "./Q1.sh";
 
  execl( binaryPath, binaryPath,"-c","ls /home >>output1.txt; grep -r 'output1.txt'  /home; export PATH=$PATH:/home", NULL);


}