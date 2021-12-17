#include <iostream>
#include <iomanip>
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
#include "IR.cpp"
#include "buildAssem.cpp"

//#include <string.h>

using namespace std;

int findFocus(string s, map<int, vector<string>> table);
void Assemble(string dir, string fileName);
// string nextWord(int pos, map<int, vector<string>> tokens);


int main(int argc, char *argv[])
{
    FILE *fp;
    fstream file;
    ofstream ptbl ("/home/slamrow/projects/cs6820/compiler3/compilerIR/output/irassignment.txt");
    //regex reg("+|-|*|/|^|");
    string dir = "/home/slamrow/projects/cs6820/compiler4/compilerIR/assem_output";
    char *line = NULL;
    size_t len = 0;
    string temp;
    string word;
    string type;
    string focus;
    int pos = 0;
    int prodNum = -1;
    vector<string> wrd;
    string output;
    
    map<int, vector<string>> prods;
    map<vector<string>, int> prodsTbl;
    map<int, vector<string>> tempTokens;
    stack<string> prodStack;
    
    size_t read;
    string fileName = "assembly-1";
    
    string invalid = "/home/slamrow/projects/cs6820/compiler3/compilerIR/input/assembly-1.txt"; 
    
    file.open(invalid, ios::in); 

    //cout << "\033[33mFile : " << test << "\033[0m\n" << endl;        

    // if (fp == 0)
    // {
    //     printf("Unable to open file [%s]\n", argv[1]);
    //     exit(1);
    // }


    prods = createProduction();
    //prodsTbl = createProductionTbl();
    output = createProductionTbl(prods);
    // ptbl.open("/home/slamrow/projects/cs6820/compiler3/compilerIR/output/irassignment.txt", ios::out);
    // for (auto &el : prodsTbl)
    // {
    //     ptbl << el.first[0] << ", " << el.first[1] << ", " << el.second << endl; 
    // }
    ptbl << output;

    parser();
    //unordered_set keys = parser::keysDict; 

    while (getline(file, temp))
    {

        pos = temp.find("\r");
        temp = temp.substr(0, pos);
        cout << left << setw(40) << temp;
        if (temp.find("//") == 0 || temp == "")
        {
            cout << endl;
            continue;
        }
        getTokens(temp);

        tempTokens = getTokenList();
                
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
                cout << left << setw(20) << "\tThis is \033[32mvalid\033[0m";
                // do some IR stuff here???
                inToPost(temp, tempTokens);
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
                        if (*it != "ϵ")
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
                    cout << "\t\033[31mInvalid\033[0m this is" << endl;
                    break;
                }
            }
            if (prodStack.empty())
            {
                cout << "\t\033[31mInvalid!!! \033[0mStack emptied before line finished." << endl;
                break;
            }
            focus = prodStack.top();
        }

        // Do IR stuff here ???

    }

    Assemble(dir, fileName);
    
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

void Assemble(string dir, string fileName)
{
     fstream file;
    string assem;
    string err;
    string data;
    string bss;
    string assembly;
    assem = dir + fileName + ".asm";
    ofstream fa(assem);
    err = dir + fileName + ".err";
    ofstream fe(err);
    fa.close();
    fe.close();
    map<string, intRep> AssembleList;
    AssembleList = getList();

    beginAssembly(fileName);
    endAssembly(fileName);
    bodyAssem(AssembleList);
    assembly = fullAssembly();
    file.open(assem.c_str(), ios_base::app);
    file << assembly << endl;
    file.close();

}

