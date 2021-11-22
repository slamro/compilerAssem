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
std::map<int, vector<string>>::iterator look;

void parser();
void getTokens(string line);
vector<string> nextWord();

// typeReg = regex("return|int|;|+|-|*|/|^|\\(|\\)|\\{|\\}|[_a-zA-Z][_a-zA-Z0-9]{0,30}*|~|!|&&|,");
// numReg = regex("[0-9]+");