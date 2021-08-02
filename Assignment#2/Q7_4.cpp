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

char convert_to_capital(char convert){
if(convert>=65 && convert<=90){
    return convert;
}else{
    return char(convert-32);
}
}


char convert_to_small(char convert){
if(convert>='a' && convert<='z'){
    return convert;
}else{
    return char(convert+32);
}
}


int main(int argc,char *argv[]){
cout<<"Fourth Process"<<endl;
    string ans=argv[0];
    int len=ans.length();
    while (1)
    {
        //cout<<ans[len];
        len-=1;
        if(len==0){
           // cout<<ans[len];
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



    int i, key, j;
    for (i = 1; i < len; i++)
    {
        
        key = ans[i];
        
        j = i - 1;
        while (j >= 0 && ans[j] > key)
        {
            ans[j + 1] = ans[j];
            j = j - 1;
        }
        ans[j + 1] = key;
    }

cout<<ans<<endl;

if(!fork()){
     execl("./output5",args,NULL);
}else{
        wait(NULL);
    }
return 0;

}