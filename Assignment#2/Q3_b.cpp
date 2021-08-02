#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
using namespace std;
int main(void)
{

    int sum = 0;
    int sum2 = 0;
    int status = 0;
    int child1 = fork();
    if (child1 == 0)
    {

        int child3 = fork();
        if (child3 == 0)
        {
            cout << "NODE Z: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('Z') << endl;
            exit(int('Z'));
        }
        else
        {
            wait(&status);
            sum += status / 255;
            //cout << "Sum is: " << sum << endl;
            //cout<<"status is = "<<char(status/254)<<endl;
        }

        int child4 = fork();

        if (child4 == 0)
        {
            if (fork() == 0)
            {
                cout << "NODE M: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('M') << endl;
                exit(int('M'));
            }
            else
            {
                wait(&status);
                sum += status / 255;
              //  cout << "Sum is: " << sum << endl;
                //cout<<"status is = "<<char(status/254)<<endl;
            }
            cout << "NODE M: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('M') << " and my child is M" << endl;
            exit(sum + int('M'));
        }
        else
        {
            wait(&status);
            sum = status / 255;
            //cout << "Sum is: " << sum << endl;
            //cout<<"status is = "<<char(status/254)<<endl;
        }

        cout << "NODE U: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('U') << " and my child are M and Z" << endl;
        exit(sum + int('U'));
    }
    else
    {
        wait(&status);
        sum = WEXITSTATUS(status) + 256;
        //cout << "Sum is: " << sum << endl;
        //cout<<"status is = "<<char(status/254)<<endl;
    }
    int child2 = fork();

    if (child2 == 0)
    {
        cout << endl;
        if (fork() == 0)
        {
            if (fork() == 0)
            {
                cout << "NODE I: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('I') << endl;
                exit('I');
            }
            else
            {
                wait(&status);
                sum2 = status / 255;
              //  cout << "Sum is: " << sum2 << endl;
            }
            cout << "NODE H: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('H') << " and my child is I" << endl;
            exit(sum2 + 'H');
        }
        else
        {
            wait(&status);
            sum2 = status / 255;
            //cout << "Sum is: " << sum2 << endl;
        }

        if (fork() == 0)
        {
            if (fork() == 0)
            {

                if (fork() == 0)
                {
                    if (fork() == 0)
                    {
                        cout << "NODE D: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('D') << endl;
                        exit(sum2+'D');
                    }
                    else
                    {
                        wait(&status);
                        sum2 = status / 255;
                  //      cout << "Sum is: " << sum2 << endl;
                        //cout<<"status is = "<<char(status/254)<<endl;
                    }

                    if (fork() == 0)
                    {
                        cout << "NODE A: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('A') << endl;
                        exit(sum2 + 'A');
                    }
                    else
                    {
                        wait(&status);
                        sum2 = WEXITSTATUS(status) + 256;
                //        cout << "Sum is: " << sum2 << endl;
                        //cout<<"status is = "<<char(status/254)<<endl;
                    }

                    cout << "NODE D: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('D') << " and my child are A and D" << endl;
                    exit(sum2 + 'D');
                }
                else
                {
                    wait(&status);
                    sum2 = WEXITSTATUS(status) + 256;
              //      cout << "Sum is: " << sum2 << endl;
                    //cout<<"status is = "<<char(status/254)<<endl;
                }

                cout << "NODE A: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('A') << " and my child is D" << endl;
                exit(sum2 + 'A');
            }
            else
            {
                wait(&status);
                sum2 = WEXITSTATUS(status) + 256;;
            //    cout << "Sum is: " << sum2 << endl;
                //cout<<"status is = "<<char(status/254)<<endl;
            }
            cout << "NODE A: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('A') << " and my child is A" << endl;
            exit(sum2 + 'A');
        }
        else
        {
            wait(&status);
            sum2 = WEXITSTATUS(status) + 256;
          //  cout << "Sum is: " << sum2 << endl;
            //cout<<"status is = "<<char(status/254)<<endl;
        }

        cout << "NODE H: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('H') << endl;
        //cout << sum2+'H' << endl;
        exit(sum2+'H');
    }
    else
    {
        wait(&status);
        //cout << "Status: " << << endl;
        sum2 = WEXITSTATUS(status) + 256*2;
        //cout << "Sum is: " << sum2 << endl;
        cout << endl;
        cout << "NODE M: PPID : " << getppid() << " PID: " << getpid() << " and ASCII: " << int('M') << " My childs are H and U" << endl;
        //cout << "Total SUM: " << sum+sum2+int('M') << endl;
    }
    
}