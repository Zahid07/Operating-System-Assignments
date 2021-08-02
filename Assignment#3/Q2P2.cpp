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

string grades(float marks)
{
    if (marks >= 90)
    {
        return "A+";
    }
    else if (marks >= 86)
    {
        return "A";
    }
    else if (marks >= 82)
    {
        return "A-";
    }
    else if (marks >= 78)
    {
        return "B+";
    }
    else if (marks >= 74)
    {
        return "B";
    }
    else if (marks >= 70)
    {
        return "B-";
    }
    else if (marks >= 66)
    {
        return "C+";
    }
    else if (marks >= 62)
    {
        return "C";
    }
    else if (marks >= 58)
    {
        return "C-";
    }
    else if (marks >= 54)
    {
        return "D+";
    }
    else if (marks >= 50)
    {
        return "D";
    }
    else
    {
        return "F";
    }
}

int main()
{

    vector<int> total;
    vector<int> obtained;
    vector<float> weightage;
    vector<int> weights;
    weights.push_back(15);
    weights.push_back(30);
    weights.push_back(15);
    weights.push_back(40);

    char str[256];
    for (int i = 0; i < 256; i++)
    {
        str[i] = '\0';
    }
    int fd = open("Student", O_RDONLY);
    if (fd == -1)
    {
        return 1;
    }

    read(fd, str, sizeof(str));
    string answer = str;
    answer = answer.substr(0, answer.length() - 1);
    std::stringstream ss(answer);
    string token;
    int i = 0;
    while (std::getline(ss, token, ','))
    {
        if (i % 2 == 0)
        {
            total.push_back(stoi(token));
        }
        else
        {
            obtained.push_back(stoi(token));
        }

        i += 1;
    }
    cout << endl;
    cout << "Students Marks = " << endl;
    float total_abs = 0;
    for (int j = 0; j < obtained.size(); j++)
    {
        weightage.push_back((float(obtained[j]) / float(total[j])) * weights[j]);
        cout << weightage[j] << "/" << weights[j] << endl;
        total_abs += weightage[j];
    }
    cout << "Total absolutes are = " << total_abs << endl;
    string grade = grades(total_abs);
    cout << "Grade is = " << grade << endl;

    close(fd);
}