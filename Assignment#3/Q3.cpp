#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <cstring>
#include <list>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{

    int status;

    int fd[2];
    int fd1[2];
    int fd2[2];
    pipe(fd);
    pipe(fd1);
    pipe(fd2);

    int n1 = fork();

    int n2 = fork();

    if (n1 > 0 && n2 > 0)
    {
        //cout<<"parent"<<endl;;
        close(fd[0]);

        dup2(fd[1], 1);
        close(fd[1]);
        execl("/bin/bash", "/bin/bash", "-c", "grep a *.*");
    }
    else if (n1 == 0 && n2 > 0)
    {
        //cout<<"First child"<<endl;;
        dup2(fd[0], 0);
        dup2(fd1[1], 1);

        close(fd1[0]);
        close(fd1[1]);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);

        execl("/bin/bash", "/bin/bash", "-c", "sort");
    }
    else if (n1 > 0 && n2 == 0)
    {
        dup2(fd1[0], 0);
        dup2(fd2[1], 1);

        close(fd1[0]);
        close(fd1[1]);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);

        execl("/bin/bash", "/bin/bash", "-c", "sum");
    }
    else
    {
        dup2(fd2[0], 0);
        close(fd1[0]);
        close(fd1[1]);
        close(fd[0]);
        close(fd[1]);
        close(fd2[0]);
        close(fd2[1]);
        cout << endl;
        execl("/bin/bash", "/bin/bash", "-c", "wc");
    }
}