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
    if(convert==' '){
        return ' ';
    }
if(convert>=65 && convert<=90){
    return convert;
}else{
    return char(convert-32);
}
}


int main(int argc,char *argv[]){
cout<<"Fifth Process"<<endl;
    string ans=argv[0];
   int len=ans.length();  
    int i;
    for (i = 0; i < len; i++)
    {        
        cout<< convert_to_capital(ans[i]);        
    }
    exit(0);
return 0;
}