// #include <string>
// #include <iostream>
// #include <map>
// #include <unordered_set>
// #include <regex>
// #include <vector>

#include "parser.h"

void parser()
{
	//(?!\\s|\\+|-|\\*|\\/|\\^)
	typeReg = regex("return|int|;|[_]|[a-zA-Z][_a-zA-Z0-9]{0,30}*|[0-9]+\\.?[0-9]*|\\s|\\+|-|\\*|\\/|\\^|=|==|<=|>=|<|>|\\(|\\)|\\{|\\}|~|!|\\%|&&|\\&\\&|\\|\\||,");
	//numReg = regex("(?=\\s|\\+|-|\\*|\\/|\\^)?([0-9]+\\.?[0-9]*)(?=\\s|\\+|-|\\*|\\/|\\^)");
	vector<string> typeArr = {"return", "int", ";", "+", "-", "*", "/", " ", "^", "(", ")", "{", "}", "~", "!", "&&", "||", "<", ">", "<=", ">=", "==", "=", ",", "_"};
	// map<int, Token> tokenList;
	// std::map<int, Token>::iterator look;

	for (const auto& s : typeArr)
	{
		typeDict.insert(s);
	}
}
void getTokens(string line)
{
    tokenList.clear();
    string s = line;
	auto typeBegin = sregex_iterator(s.begin(), s.end(), typeReg);
	auto typeEnd = sregex_iterator();
	map<int, vector<string>> temp;
	string type;
	string val;
	int j = 0;
	vector<string> prev = {"~", "~"}; 
	
	
	for (sregex_iterator &i = typeBegin; i != typeEnd; i++)
    {
		smatch match = *i;
		//string t = i->str();
		
		val = match.str();
		
		if (typeDict.find(match.str()) != typeDict.end()) 
		{
			type = match.str();
		} 
		else 
		{
			char *c = new char[val.size() +1];
			strcpy(c, val.c_str());
			
			if (isdigit(c[0]) == 0){type = "name";}
			else {type = "num";}
			// type = "var";
		}

		if (val == "-")
		{
			if (prev[1] == "-")
			{
				temp.insert(temp.end(), {j-1, {"-", prev[1]}});
				type = "neg";
			}
			int findName = prev[0].find("name");
			int findNum = prev[0].find("num");
			if (findName != -1 || findNum != -1 || prev[1] == ")")
			{
				temp.insert(temp.end(), {j, {type, val}});
			}
			else if (prev[1] == "(" || prev[1] == "~")
			{
				type = "neg";
			}
			else if (prev[1] == " ")
			{
				val = prev[1] + val;
				type = "neg";
			}
			
		}
		else if (prev[0] == "neg")
		{
			if (type == "num" || type == "name")
			{
				val = prev[1] + val;
				type = prev[0] + type;

				if (prev[1].substr(0,1) == " ")
				{
					type = "space" + type;
				}
				
				temp.insert(temp.end(), {j, {type, val}});
			}
			else if (val == " ")
			{
				temp.insert(temp.end(), {j-1, {prev[1], prev[1]}});
				//temp.insert(temp.end(), {j, {type, val}});
			}
			else 
			{
				temp.insert(temp.end(), {j-1, {prev[1], prev[1]}});
				temp.insert(temp.end(), {j, {type, val}});
			}

		}
		else if (val == " ")
		{

		}
		else if (prev[1] == " ")
		{
			val = prev[1] + val;
			temp.insert(temp.end(), {j, {type, val}});
		}
		else
		{
			temp.insert(temp.end(), {j, {type, val}});
		}
		// tokenList.insert(tokenList.end(), {match.position(), {match.str()}});
		
		j++;
		prev = {type, val};
	}
	tokenList = temp;
	//tokenList.insert(tokenList.end(), {0, {"null", "null"}});
	
	// vector<string> cur;
	// prev = {"~", "~"};
	
	// for (auto &it : temp)
	// {
	// 	// map<int, vector<string>>::iterator it2 = &it;
	// 	// std::advance(it2, 1);
	// 	// next = it2.second;
	// 	cur = it.second;

	// 	if (cur[0].find("neg") != -1 && prev[1] == " ")
	// 	{
	// 		cur[0] = "space" + cur[0];
	// 	}

	// 	tokenList.insert(tokenList.end(), {it.first, cur});
		
	// 	prev = cur;
	// }
	
	look = tokenList.begin();
    // return tokenList;
}
vector<string> nextWord()
{
	vector<string> s;
	if (look == tokenList.end())
	{
		s = {"eof", "eof"};
	}
	else 
	{
		s = (*look).second;
		look++;
	}

    return s;  
}