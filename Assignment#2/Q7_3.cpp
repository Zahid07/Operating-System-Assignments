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
int main(int argc,char *argv[]){

    string ans=argv[0];
    cout<<"Third Process"<<endl;
    int len=ans.length();
    while (1)
    {
        len-=1;
        if(len==0){
            break;
        }
    }
    len=ans.length();
      char *args = new char[len+1];
    for(int i=0;i<len;i++){
        args[i]='\0';
    }

    for(int i=0;i<len;i++){
        args[i]=ans[i];
    }

    int len1=0;
    while(ans[len1]!='\0'){
        cout<<char(ans[len1]+2);
        len1+=1;
    }cout<<endl;

     if(!fork()){
             execl("./output4",args,NULL);
    }else{
        wait(NULL);
    }
return 0;

}