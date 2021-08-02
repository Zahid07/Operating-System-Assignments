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
    cout<<"First Process"<<endl;
    string ans=argv[0];
    //cout<<"string is = "<<ans<<endl;
    int len=ans.length();
    cout<<"ans is = ";
    while (1)
    {
        cout<<ans[len];
        len-=1;
        if(len==0){
            cout<<ans[len];
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


cout<<endl;

    int child1=fork();
    if(child1==0){
             execl("./output2",args,NULL);
    }else{
        wait(NULL);
    }
    
return 0;

}