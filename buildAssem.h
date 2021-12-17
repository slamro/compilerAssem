#include <stdio.h>
#include <stdlib.h>
#include <vector>
// #include <string.h>
#include <string>
#include <ctype.h>
#include <map>

using namespace std;

void beginAssembly(string name);
void functionAssembly();
void dataAssembly(string name, string value);
void unInitDataAssembly(string name, string type);
void textAssem();
void bodyAssem(map<string, intRep> IRList);
string fullAssembly();
void endAssembly(string name);


string beginAsm;
string dataAsm = "\nsection .data\n";
vector<string, string> datavec;
string unInitDataAsm = "\nsection .bss\n";
string textAsm = "\nsection .text\n";
string funcAsm;
string mainAsm = "main:\n";
string endAsm;
bool initData = false;
string expr;
string temp;
string var;