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

string remove_string(string line, string remove)
{
    string ans = "";
    std::istringstream ss(remove);
    std::string token;

    std::istringstream ss1(line);
    std::string token1;

    vector<string> temp_remove;
    vector<string> temp_line;

    while (std::getline(ss, token, ','))
    {
        if (token[0] == ' ')
        {
            token = token.substr(1, token.length());
        }
        temp_remove.push_back(token);
    }

    while (std::getline(ss1, token1, ','))
    {
        if (token1[0] == ' ')
        {
            token1 = token1.substr(1, token1.length());
        }
        temp_line.push_back(token1);
    }

    for (int i = 0; i < temp_remove.size(); i++)
    {
        std::vector<string>::iterator it;
        it = std::find(temp_line.begin(), temp_line.end(), temp_remove[i]);
        if (it == temp_line.end())
        {
            return line;
            break;
        }
    }

    for (int i = 0; i < temp_remove.size(); i++)
    {
        temp_line.erase(std::remove(temp_line.begin(), temp_line.end(), temp_remove[i]), temp_line.end());
    }

    for (int i = 0; i < temp_line.size(); i++)
    {
        ans += temp_line[i];
        ans += ',';
        ans += ' ';
    }
    ans = ans.substr(0, ans.length() - 2);
    return ans;
}

int main(int argc, char *argv[])
{

    int fd[2];
    ;
    int fd1[2];
    ;
    pipe(fd);
    pipe(fd1);
    char buff[1024];

    vector<string> file_items;

    int child1 = fork();
    if (child1 == 0)
    {
        vector<string> items;
        vector<string> found;
        vector<int> countiterations;

        char answer[2048];
        int threshold = 0;
        read(fd[0], &answer, 2048);

        string stringanswer = answer;
        std::istringstream ss(stringanswer);
        std::string token;
        bool threshold_found = false;
        while (std::getline(ss, token, '\n'))
        {
            if (threshold_found == false)
            {
                threshold = stoi(token);
                threshold_found = true;
            }
            else
            {
                file_items.push_back(token);
                std::istringstream ss1(token);
                std::string token1;
                while (std::getline(ss1, token1, ','))
                {
                    if (token1[0] == ' ')
                    {
                        token1 = token1.substr(1, token1.length());
                    }
                    items.push_back(token1);
                }
            }
        }
        cout << "Frequencies of all items are." << endl;
        cout << endl;
        int counts = 0;
        while (!items.empty())
        {
            string search = items.front();
            found.push_back(search);
            int count1 = count(items.begin(), items.end(), search);
            cout << search << setw(10 - search.length()) << " = " << count1 << endl;
            ;
            countiterations.push_back(count1);
            if (count1 >= threshold)
                counts += 1;
            items.erase(std::remove(items.begin(), items.end(), search), items.end());
        }
        cout << endl;
        cout << "Frequencies of all items are with threshold = " << threshold << endl;
        cout << endl;

        string stringanswer1 = "";
        stringanswer1 += to_string(threshold);
        stringanswer1 += '\n';
        stringanswer1 += to_string(counts);
        stringanswer1 += '\n';

        for (int i = 0; i < found.size(); ++i)
        {
            if (countiterations[i] >= threshold)
            {
                cout << found[i] << setw(10 - found[i].length()) << " = " << countiterations[i] << endl;
                ;
                stringanswer1 += found[i];
                stringanswer1 += to_string(countiterations[i]);
                stringanswer1 += '\n';
            }
            else
            {
                for (int j = 0; j < found.size(); j++)
                {
                    file_items[j] = remove_string(file_items[j], found[i]);
                }
            }
        }

        stringanswer1 += '\0';
        int n = stringanswer1.length();
        char char_array[n + 1];
        strcpy(char_array, stringanswer1.c_str());
        write(fd1[1], char_array, n);

        int child2 = fork();
        if (child2 == 0)
        {

            vector<string> temp_item;
            vector<string> answer1;
            ;
            vector<int> countiterations;
            char answer[2048];
            int threshold = 0;
            read(fd1[0], &answer, 2048);
            string stringanswer = answer;

            std::stringstream ss1(answer);
            std::string token1;
            while (std::getline(ss1, token1, '\n'))
            {
                threshold = stoi(token1);
                break;
            }

            for (int i = 0; i < file_items.size(); i++)
            {
                std::stringstream ss(file_items[i]);
                std::string token;
                while (std::getline(ss, token, ','))
                {
                    if (token[0] == ' ')
                    {
                        token = token.substr(1, token.length());
                    }
                    temp_item.push_back(token);
                }

                for (int i = 0; i < temp_item.size(); i++)
                {
                    for (int j = i + 1; j < temp_item.size(); j++)
                    {
                        string original = temp_item[i];
                        original += ',';
                        original += ' ';
                        string append = temp_item[j];
                        original += append;
                        answer1.push_back(original);
                    }
                }
                temp_item.clear();
            }

            cout << "Frequencies of all items are." << endl;
            cout << endl;
            int counts = 0;
            while (!answer1.empty())
            {
                string search = answer1.front();
                temp_item.push_back(search);
                int count1 = count(answer1.begin(), answer1.end(), search);
                cout << search << setw(20 - search.length()) << " = " << count1 << endl;
                ;
                countiterations.push_back(count1);
                if (count1 >= threshold)
                    counts += 1;
                answer1.erase(std::remove(answer1.begin(), answer1.end(), search), answer1.end());
            }
            string stringanswer1 = "";
            stringanswer1 += to_string(threshold);
            stringanswer1 += '\n';
            stringanswer1 += to_string(counts);
            stringanswer1 += '\n';
            cout << "Frequencies of all items are with threshold = " << threshold << endl;
            cout << endl;
            cout << endl;
            for (int i = 0; i < temp_item.size(); ++i)
            {
                if (countiterations[i] >= threshold)
                {
                    cout << temp_item[i] << setw(20 - temp_item[i].length()) << " = " << countiterations[i] << endl;
                    ;
                    stringanswer1 += temp_item[i];
                    stringanswer1 += to_string(countiterations[i]);
                    stringanswer1 += '\n';
                }
                else
                {
                    for (int j = 0; j < found.size(); j++)
                    {
                        file_items[j] = remove_string(file_items[j], temp_item[i]);
                    }
                }
            }

            cout << endl;
            cout << endl;

            stringanswer1 += '\0';
            int n = stringanswer1.length();
            char char_array[n + 1];
            strcpy(char_array, stringanswer1.c_str());
            write(fd1[1], char_array, n);

            int child3 = fork();
            if (child3 == 0)
            {

                vector<string> temp_item;
                vector<string> answer1;
                ;
                vector<int> countiterations;
                char answer[2048];
                int threshold = 0;
                read(fd1[0], &answer, 2048);
                string stringanswer = answer;

                std::stringstream ss1(answer);
                std::string token1;
                while (std::getline(ss1, token1, '\n'))
                {
                    threshold = stoi(token1);
                    break;
                }

                for (int i = 0; i < file_items.size(); i++)
                {
                    std::stringstream ss(file_items[i]);
                    std::string token;
                    while (std::getline(ss, token, ','))
                    {
                        if (token[0] == ' ')
                        {
                            token = token.substr(1, token.length());
                        }
                        temp_item.push_back(token);
                    }

                    for (int i = 0; i < temp_item.size(); i++)
                    {
                        for (int j = i + 1; j < temp_item.size(); j++)
                        {
                            string original = temp_item[i];
                            original += ',';
                            original += ' ';
                            string append = temp_item[j];
                            original += append;
                            for (int k = j + 1; k < temp_item.size(); k++)
                            {
                                string append2 = temp_item[k];
                                original += ',';
                                original += ' ';
                                original += append2;
                                answer1.push_back(original);
                            }
                        }
                    }
                    temp_item.clear();
                }

                cout << "Frequencies of all items are." << endl;
                cout << endl;
                int counts = 0;
                while (!answer1.empty())
                {
                    string search = answer1.front();
                    temp_item.push_back(search);
                    int count1 = count(answer1.begin(), answer1.end(), search);
                    cout << search << setw(20 - search.length()) << " = " << count1 << endl;
                    ;
                    countiterations.push_back(count1);
                    if (count1 >= threshold)
                        counts += 1;
                    answer1.erase(std::remove(answer1.begin(), answer1.end(), search), answer1.end());
                }
                string stringanswer1 = "";

                cout << endl;
                cout << "Frequencies of all items are with threshold = " << threshold << endl;
                cout << endl;

                for (int i = 0; i < temp_item.size(); ++i)
                {
                    if (countiterations[i] >= threshold)
                    {
                        cout << temp_item[i] << setw(20 - temp_item[i].length()) << " = " << countiterations[i] << endl;
                        ;
                        stringanswer1 += temp_item[i];
                        stringanswer1 += "  =  ";
                        stringanswer1 += to_string(countiterations[i]);
                        stringanswer1 += '\n';
                    }
                    else
                    {
                        for (int j = 0; j < found.size(); j++)
                        {
                            file_items[j] = remove_string(file_items[j], temp_item[i]);
                        }
                    }
                }
                int file_desc = open("output.txt", O_WRONLY | O_CREAT, 0666);
                int n = stringanswer1.length();
                char char_array[n + 1];
                strcpy(char_array, stringanswer1.c_str());
                write(file_desc, char_array, n + 1);
            }
            else if (child3 > 0)
            {
                wait(NULL);
            }
        }
        else if (child2 > 0)
        {
            wait(NULL);
        }
    }
    else if (child1 > 0)
    {

        int tran = 0;
        string total = "";

        cout << "Program name is = file name input" << endl;
        cout << argv[1] << endl;
        ;
        int len = 0;
        while (argv[1][len] != '\0')
        {
            len += 1;
        }

        len += 1;
        char *input = new char[len];
        for (int i = 0; i < len; i++)
        {
            input[i] = argv[1][i];
        }

        float s_threshold = 0;
        int no_of_trans = 0;
        string line;
        ifstream myfile(input);
        if (myfile.is_open())
        {
            int i = 0;
            while (getline(myfile, line))
            {
                if (i > 1)
                {

                    line += '\n';
                    total += line;
                }
                else
                {
                    if (i == 0)
                    {
                        s_threshold = stof(line);
                    }
                    else if (i == 1)
                    {
                        no_of_trans = stoi(line);
                        tran = no_of_trans * s_threshold;
                        line = to_string(tran);
                        line += '\n';
                        total += line;
                    }
                }
                i++;
            }

            myfile.close();
        }
        total += '\0';
        int n = total.length();
        char char_array[n + 1];
        strcpy(char_array, total.c_str());

        write(fd[1], char_array, n);

        wait(NULL);
    }
}