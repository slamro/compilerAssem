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
	typeReg = regex("return|num|ish|procedure|if|for|printNum|printIsh|readNum|readIsh|,|;|\"[_a-zA-Z0-9]*\"|[_a-zA-Z][_a-zA-Z0-9]{0,30}*|[0-9]+\\.?[0-9]*|\\s|\\+|\\+\\+|\\+-|\\+=|--|-|\\*|\\/|\\/\\/|\\^|=|==|<=|>=|<|>|\\(|\\)|\\{|\\}|~|!|\\%|&&|\\&\\&|\\|\\||,");
	//numReg = regex("(?=\\s|\\+|-|\\*|\\/|\\^)?([0-9]+\\.?[0-9]*)(?=\\s|\\+|-|\\*|\\/|\\^)");
	vector<string> typeArr = {";", "+", "-", "*", "/", " ", "^", "(", ")", "{", "}", "~", "!", "&&", "||", "<", ">", "<=", ">=", "==", "=", ",", "_"};
	vector<string> typeIlgl = {"+-", "--"};
	vector<string> typeKeys = {"ish", "return", "num", "procedure", "for", "printNum", "printIsh", "readNum", "readIsh", "if"};
	// map<int, Token> tokenList;
	// std::map<int, Token>::iterator look;

	for (const auto& s : typeArr)
	{
		typeDict.insert(s);
	}
	for (const auto& s : typeIlgl)
	{
		ilglDict.insert(s);
	}
	for (const auto& s : typeKeys)
	{
		keysDict.insert(s);
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
	int t = 0;
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
		else if (ilglDict.find(match.str()) != ilglDict.end())
		{
			type = "Illegal";
		}
		else if (keysDict.find(match.str()) != keysDict.end())
		{
			type = "Key Word";
			if (val == "num")
			{
				t = 1;
			}
			else if (val == "ish")
			{
				t = 2;
			}
			else if (val == "procedure")
			{
				t = 3;
			}
		}
		else 
		{
			char *c = new char[val.size() +1];
			strcpy(c, val.c_str());
			
			type = "dig";
			if (isdigit(c[0]) == 0)
			{
				type = "name";
				if (t == 1)
				{
					if (numNames.find(val) == numNames.end())
					{
						numNames.insert(numNames.end(), val);
					}
				}
				else if (t == 2)
				{
					if (ishNames.find(val) == ishNames.end())
					{
						ishNames.insert(ishNames.end(), val);
					}
				}
				else if (t == 3)
				{
					if (procNames.find(val) == procNames.end())
					{
						procNames.insert(procNames.end(), val);
					}
				}
				t = 0;
			}
			
			// type = "var";
		}

		if (val == "-")
		{
			// if (prev[1] == "-")
			// {
			// 	temp.insert(temp.end(), {j-1, {"-", prev[1]}});
			// 	type = "neg";
			// }
			int findName = prev[0].find("name");
			int findNum = prev[0].find("dig");
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
				type = "spaceneg";
			}
			
		}
		else if (prev[0] == "neg")
		{
			if (type == "dig" || type == "name")
			{
				val = prev[1] + val;
				type = prev[0] + type;

				// if (prev[1].substr(0,1) == " ")
				// {
				// 	type = "space" + type;
				// }
				
				temp.insert(temp.end(), {j, {type, val}});
			}
			else if (val == " ")
			{
				temp.insert(temp.end(), {j-1, {"-", "-"}});
				//temp.insert(temp.end(), {j, {type, val}});
			}
			else 
			{
				temp.insert(temp.end(), {j-1, {prev[1], prev[1]}});
				temp.insert(temp.end(), {j, {type, val}});
			}

		}
		else if (prev[0] == "spaceneg")
		{
			if (type == "dig" || type == "name")
			{
				val = prev[1] + val;
				type = prev[0] + type;

				temp.insert(temp.end(), {j, {type, val}});
			}
			else if (val == " ")
			{
				temp.insert(temp.end(), {j-1, {"-", "-"}});
			}
			else 
			{
				temp.insert(temp.end(), {j-1, {"-", "-"}});
				temp.insert(temp.end(), {j, {type, val}});
			}
		}
			
		else if (val == " ")
		{

		}
		else if (prev[1] == " ")
		{
			//val = prev[1] + val;
			temp.insert(temp.end(), {j, {type, val}});
		}
		else if (val == "//")
		{
			break;
		}
		else
		{
			temp.insert(temp.end(), {j, {type, val}});
		}
		// tokenList.insert(tokenList.end(), {match.position(), {match.str()}});

		//{"ish", "return", "num", "procedure", "for", "if"}
		


		j++;
		prev = {type, val};
	}
	tokenList = temp;
	
	
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

map<int, vector<string>> getTokenList()
{
	return tokenList;
}