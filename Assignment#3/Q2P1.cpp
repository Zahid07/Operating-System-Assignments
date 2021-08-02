#include <iostream>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

using namespace std;

int main()
{
    mkfifo("Student", 0777);

    char input[256];
    for (int i = 0; i < 256; i++)
    {
        input[i] = '\0';
    }
    srand(time(NULL));

    int fd = open("Student", O_WRONLY);
    if (fd == -1)
    {

        return 1;
    }
    string input1 = "";
    string ans = "";
    cout << "Enter Assesment total marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << "Enter Assesment obtained marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << endl;
    cout << "Enter Lab total marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << "Enter Lab obtained marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << endl;
    cout << "Enter Project total marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << "Enter Project obtained marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << endl;
    cout << "Enter Final total marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";
    cout << "Enter Final obtained marks = ";
    getline(cin, input1);
    ans += input1;
    ans += ',';
    input1 = "";

    strcpy(input, ans.c_str());
    write(fd, &input, sizeof(input));
    close(fd);

    return 0;
}