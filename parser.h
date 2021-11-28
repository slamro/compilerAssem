#include <string>
#include <iostream>
#include <map>
#include <unordered_set>
#include <regex>
#include <vector>
// #include <iterator>


using namespace std;

struct Token {
	string type;
	string value;
	int pos;
	Token(string _type, string _value, int _pos) : 
		type(_type), value(_value), pos(_pos) {}
    Token(){};		
};

regex typeReg;
regex numReg;
// map<int, Token> tokenList;
map<int, vector<string>> tokenList;
unordered_set<string> typeDict;
unordered_set<string> ilglDict;
unordered_set<string> keysDict;
unordered_set<string> numNames;
unordered_set<string> ishNames;
unordered_set<string> procNames;
std::map<int, vector<string>>::iterator look;

void parser();
void getTokens(string line);
vector<string> nextWord();
map<int, vector<string>> getTokenList();

// typeReg = regex("return|int|;|+|-|*|/|^|\\(|\\)|\\{|\\}|[_a-zA-Z][_a-zA-Z0-9]{0,30}*|~|!|&&|,");
// numReg = regex("[0-9]+");