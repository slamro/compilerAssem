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


using namespace std;

map<int, vector<string>> createProduction();
void createProductionTbl();
void createProductionTbl(map<int, vector<string>> myProds);
int getProduction(string focus, vector<string> word);

FILE *pro;
map<int, vector<string>> productions;
map<vector<string>, int> prodTbl;
//string pTbl;
map<string, set<string>> firstElem;
map<string, set<string>> followElem;
map<tuple<string, string>, set<string>> firstPlus;
set<string> terms;
set<string> nonTerms;