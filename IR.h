#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>      //for function isalnum()
#include <cmath>      // for the power function

using namespace std;

typedef struct Intermediate_Representation
{
    string name;    // name of variable
    string type;    // num, ish, procedure
    string proceedType;
    string proceedName;

    stack<string> postStack;    // what will be processed
    string postFix;
    string result;  // processed result
} intRep;

void inToPost(string infix, map<int, vector<string>> tokens);
// string toPost(string infix, map<int, vector<string>> tokens);
int preced(char ch);
string processIR(intRep proc);

map<string, intRep> IRList;
unordered_set<string> mathBits = {"+", "-", "*", "/", "^"};
int proceed = -1;
