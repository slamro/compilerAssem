#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include <stack>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "parser.cpp"
#include "productions.cpp"

//#include <string.h>

using namespace std;

int findFocus(string s, map<int, vector<string>> table);
// string nextWord(int pos, map<int, vector<string>> tokens);


int main(int argc, char *argv[])
{
    FILE *fp;
    fstream file;
    //regex reg("+|-|*|/|^|");
    char *line = NULL;
    size_t len = 0;
    string temp;
    string word;
    string type;
    string focus;
    int pos = 0;
    int prodNum = -1;
    vector<string> wrd;
    
    map<int, vector<string>> prods;
    map<tuple<string, string>, int> prodsTbl;
    map<int, vector<string>> stringTokens;
    stack<string> prodStack;
    
    size_t read;
    string fileName;
    //string dir = "/home/slamrow/projects/cs6820/compiler/assem_output/";
       

    // if (argc != 2)
    // {
    //     printf("Error: usage: %s sample_input/<inputBinary.s>\n", argv[0]);
    //     exit(1);
    // }

    //printf("Welcome to CS6610 MIPS Assembler\n\n");
    // fp = fopen(argv[1], "r");
    string invalid = "/home/slamrow/projects/cs6820/compiler2/compiler/input/ll1invalid-1.txt"; 
    string valid = "/home/slamrow/projects/cs6820/compiler2/compiler/input/ll1valid-1.txt";
    
    int i = 0;
    while(i<2)
    {
        string test = (i==0) ? "LL(1)Valid" : "LL(1)InValid";
        fileName = (i == 0) ? valid : invalid;

        file.open(fileName, ios::in); 

        cout << "\033[33mFile : " << test << "\033[0m\n" << endl;        

        if (fp == 0)
        {
            printf("Unable to open file [%s]\n", argv[1]);
            exit(1);
        }


        prods = createProduction();
        //prodsTbl = createProductionTbl();
        createProductionTbl(prods);
        parser();

        while (getline(file, temp))
        {

            pos = temp.find("\r");
            temp = temp.substr(0, pos);
            cout << temp;
            getTokens(temp);
            
            wrd = nextWord();
            word = wrd[1];

            prodStack.push("eof");
            prodStack.push("Goal");
            focus = prodStack.top();
            while(true)
            {
                if (word == " ")
                {
                    //cout << " ";
                }
                else if (focus.compare("eof") == 0 && word.compare("eof") == 0)
                {
                    prodStack.pop();
                    cout << "\t\t\tThis is \033[32mvalid\033[0m" << endl;
                    break;
                }
                else if (findFocus(focus, prods) == -1 || focus == "eof") //focus is terminal or eof
                {
                    // if (focus.compare(word) == 0 || focus.compare(v[1]) == 0)
                    // {
                        prodStack.pop();
                        // cout << word;
                        wrd = nextWord();
                        word = wrd[1];
                    // }
                    // else 
                    // {
                    //     cout << "Error looking for symbol at top of stack" << endl;
                    //     break;                    
                    // }
                }
                else // focus is non terminal
                {
                    
                    prodNum = getProduction(focus, wrd);
                    if (prodNum > -1)
                    {
                        prodStack.pop();
                        //map<int, vector<string>> prods;
                        vector<string>::reverse_iterator it = prods[prodNum].rbegin();
                        for (; it != prods[prodNum].rend() - 1; ++it)
                        {
                            if (*it != "£")
                            {
                                prodStack.push(*it);
                            }
                        }
                    }
                    else
                    {
                        while (prodStack.empty() == false)
                        {
                            prodStack.pop();
                        }
                        cout << "\t\t\t\033[31mInvalid\033[0m this is" << endl;
                        break;
                    }
                }
                if (prodStack.empty())
                {
                    cout << "\t\t\033[31mInvalid!!! \033[0mStack emptied before line finished." << endl;
                    break;
                }
                focus = prodStack.top();
            }

        }

        i++;
        cout << "\033[33m\n\nNext File" << "\033[0m" << endl;
        file.close();
    }
    
    return 0;
}

int findFocus(string s, map<int, vector<string>> table)
{
    int ret = -1;
    for (auto &it : table)
    {
        if (it.second[0] == s)
        {
            ret = 2;
        }
        
    }
    return ret;
}

