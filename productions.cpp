
#include "productions.h"

map<int, vector<string>> createProduction()
{
    // Books productions
    // productions[0] = {"Goal", "Expr"};
    // productions[1] = {"Expr", "Term", "Expr`"};
    // productions[2] = {"Expr`", "+", "Term", "Expr`"};
    // productions[3] = {"Expr`", "-", "Term", "Expr`"};
    // productions[4] = {"Expr`", "ϵ"};
    // productions[5] = {"Term", "Factor", "Term`"};
    // productions[6] = {"Term`", "*", "Factor", "Term`"};
    // productions[7] = {"Term`", "/", "Factor", "Term`"};
    // productions[8] = {"Term`", "ϵ"};
    // productions[9] = {"Factor", "(", "Expr", ")"};
    // productions[10] = {"Factor", "num"};
    // productions[11] = {"Factor", "name"};

    // Brad's Useless productions
    // productions[0] = {"Goal", "Expr"};
    // productions[1] = {"Expr", "LTerm", "Expr`"};
    // productions[2] = {"LTerm", "LFactor", "Term`"};
    // productions[3] = {"RTerm", "RFactor", "Term`"};
    // productions[4] = {"Expr`", "+", "RTerm", "Expr`"};
    // productions[5] = {"Expr`", "-", "RTerm", "Expr`"};
    // productions[6] = {"Expr`", "ϵ"};
    // productions[7] = {"Term`", "*", "RFactor", "Term`"};
    // productions[8] = {"Term`", "/", "RFactor", "Term`"};
    // productions[9] = {"Term`", "^", "RFactor", "Term`"};
    // productions[10] = {"Term`", "ϵ"};
    // productions[11] = {"LFactor", "GFactor"};
    // productions[12] = {"LFactor", "negnum"};
    // productions[13] = {"LFactor", "negname"};
    // productions[14] = {"RFactor", "GFactor"};
    // productions[15] = {"GFactor", "(", "Expr", ")"};
    // productions[16] = {"GFactor", "PosVal"};
    // productions[17] = {"GFactor", "SpaceNegVal"};
    // productions[18] = {"PosVal", "num"};
    // productions[19] = {"PosVal", "name"};
    // productions[20] = {"SpaceNegVal", "spacenegnum"};
    // productions[21] = {"SpaceNegVal", "spacenegname"};

    // Next Productions      Term`", "ϵ
    // productions[0] = {"Goal", "LineFull"};
    // productions[1] = {"LineFull", "VarType", "VarTypeAfter"};
    // productions[2] = {"LineFull", "LineVarName"};
    // productions[3] = {"LineFull", "negdig", "Power'", "MultDiv'", "AddSub'"};
    // productions[4] = {"LineFull", "Parens", "Power'", "MultDiv'", "AddSub'"};
    // productions[5] = {"LineFull", "return", "GTerm"};
    // productions[6] = {"LineFull", "}"};
    // productions[7] = {"VarTypeAfter", "LineVarName"};
    // productions[8] = {"VarTypeAfter", "procedure", "name", "ProcedureParams", "{"};
    // productions[9] = {"LineVarName", "name", "LineVarNameRemaining"};
    // productions[10] = {"LineVarNameRemaining", "=", "Expr"};
    // productions[11] = {"LineVarNameRemaining", "PowerAndRightOp", "MultDiv'", "AddSub'"};
    // productions[12] = {"LineVarNameRemaining", "MultAndRightOp", "AddSub'"};
    // productions[13] = {"LineVarNameRemaining", "DivAndRightOp", "AddSub'"};
    // productions[14] = {"LineVarNameRemaining", "AddSub'"};
    // productions[15] = {"ProcedureParams", "(", "Params", ")"};
    // productions[16] = {"Params", "VarType", "name", "MoreParams"};
    // productions[17] = {"Params", "ϵ"};
    // productions[18] = {"MoreParams", ",", "VarType", "name", "MoreParams"};
    // productions[19] = {"MoreParams", "ϵ"};
    // productions[20] = {"VarType", "num"};
    // productions[21] = {"VarType", "ish"};
    // productions[22] = {"Expr", "LTermAddSub", "AddSub'"};
    // productions[23] = {"LTermAddSub", "LTermMultDiv", "MultDiv'"};
    // productions[24] = {"LTermMultDiv", "LTermPower", "Power'"};
    // productions[25] = {"RTermAddSub", "RTermMultDiv", "MultDiv'"};
    // productions[26] = {"RTermMultDiv", "RTermPower", "Power'"};
    // productions[27] = {"AddSub'", "+", "RTermAddSub", "AddSub'"};
    // productions[28] = {"AddSub'", "-", "RTermAddSub", "AddSub'"};
    // productions[29] = {"AddSub'", "ϵ"};
    // productions[30] = {"MultDiv'", "MultAndRightOp"};
    // productions[31] = {"MultDiv'", "DivAndRightOp"};
    // productions[32] = {"MultDiv'", "ϵ"};
    // productions[33] = {"MultAndRightOp", "*", "RTermMultDiv", "MultDiv'"};
    // productions[34] = {"DivAndRightOp", "/", "RTermMultDiv", "MultDiv'"};
    // productions[35] = {"Power'", "PowerAndRightOp"};
    // productions[36] = {"Power'", "ϵ"};
    // productions[37] = {"PowerAndRightOp", "^", "RTermPower", "Power'"};
    // productions[38] = {"LTermPower", "GTerm"};
    // productions[39] = {"LTermPower", "negdig"};
    // productions[40] = {"LTermPower", "negname"};
    // productions[41] = {"RTermPower", "GTerm"};
    // productions[42] = {"GTerm", "Parens"};
    // productions[43] = {"GTerm", "PosVal"};
    // productions[44] = {"GTerm", "SpaceNegVal"};
    // productions[45] = {"Parens", "(", "Expr", ")"};
    // productions[46] = {"PosVal", "dig"};
    // productions[47] = {"PosVal", "name"};
    // productions[48] = {"SpaceNegVal", "spacenegdig"};
    // productions[49] = {"SpaceNegVal", "spacenegname"};

    productions[0] = {"Goal", "LineFull"};
    productions[1] = {"LineFull", "VarType", "VarTypeAfter"};
    productions[2] = {"LineFull", "LineVarName"};
    productions[3] = {"LineFull", "negdig", "Power'", "MultDiv'", "AddSub'"};
    productions[50] = {"LineFull", "dig", "Power'", "MultDiv'", "AddSub'"};
    productions[4] = {"LineFull", "Parens", "Power'", "MultDiv'", "AddSub'"};
    productions[5] = {"LineFull", "return", "GTerm"};
    productions[6] = {"LineFull", "}"};
    productions[51] = {"LineFull", "printNum", "name"};
    productions[52] = {"LineFull", "printIsh", "name"};
    productions[53] = {"LineFull", "readNum", "name"};
    productions[54] = {"LineFull", "readIsh", "name"};
    productions[55] = {"LineFull", "printString", "\"any text in here\""};
    productions[7] = {"VarTypeAfter", "LineVarName"};
    productions[8] = {"VarTypeAfter", "procedure", "name", "ProcedureParams", "{"};
    productions[9] = {"LineVarName", "name", "LineVarNameRemaining"};
    productions[10] = {"LineVarNameRemaining", "=", "Expr"};
    productions[11] = {"LineVarNameRemaining", "PowerAndRightOp", "MultDiv'", "AddSub'"};
    productions[12] = {"LineVarNameRemaining", "MultAndRightOp", "AddSub'"};
    productions[13] = {"LineVarNameRemaining", "DivAndRightOp", "AddSub'"};
    productions[14] = {"LineVarNameRemaining", "AddSub'"};
    productions[15] = {"ProcedureParams", "(", "Params", ")"};
    productions[16] = {"Params", "VarType", "name", "MoreParams"};
    productions[17] = {"Params", "ϵ"};
    productions[18] = {"MoreParams", ",", "VarType", "name", "MoreParams"};
    productions[19] = {"MoreParams", "ϵ"};
    productions[20] = {"VarType", "num"};
    productions[21] = {"VarType", "ish"};
    productions[22] = {"Expr", "LTermAddSub", "AddSub'"};
    productions[23] = {"LTermAddSub", "LTermMultDiv", "MultDiv'"};
    productions[24] = {"LTermMultDiv", "LTermPower", "Power'"};
    productions[25] = {"RTermAddSub", "RTermMultDiv", "MultDiv'"};
    productions[26] = {"RTermMultDiv", "RTermPower", "Power'"};
    productions[27] = {"AddSub'", "+", "RTermAddSub", "AddSub'"};
    productions[28] = {"AddSub'", "-", "RTermAddSub", "AddSub'"};
    productions[29] = {"AddSub'", "ϵ"};
    productions[30] = {"MultDiv'", "MultAndRightOp"};
    productions[31] = {"MultDiv'", "DivAndRightOp"};
    productions[32] = {"MultDiv'", "ϵ"};
    productions[33] = {"MultAndRightOp", "*", "RTermMultDiv", "MultDiv'"};
    productions[34] = {"DivAndRightOp", "/", "RTermMultDiv", "MultDiv'"};
    productions[35] = {"Power'", "PowerAndRightOp"};
    productions[36] = {"Power'", "ϵ"};
    productions[37] = {"PowerAndRightOp", "^", "RTermPower", "Power'"};
    productions[38] = {"LTermPower", "GTerm"};
    productions[39] = {"LTermPower", "negdig"};
    productions[40] = {"LTermPower", "negname"};
    productions[41] = {"RTermPower", "GTerm"};
    productions[42] = {"GTerm", "Parens"};
    productions[43] = {"GTerm", "PosVal"};
    productions[44] = {"GTerm", "SpaceNegVal"};
    productions[56] = {"GTerm", "NameOrProcedure"};
    productions[45] = {"Parens", "(", "Expr", ")"};
    productions[57] = {"NameOrProcedure", "name", "Arguments"};
    productions[58] = {"Arguments", "(", "Expr", "MoreArguments"};
    productions[59] = {"Arguments", "ϵ"};
    productions[60] = {"MoreArguments", ",", "Expr", "MoreArguments"};
    productions[61] = {"MoreArguments", "ϵ"};
    productions[46] = {"PosVal", "dig"};
    productions[47] = {"PosVal", "name"};
    productions[48] = {"SpaceNegVal", "spacenegdig"};
    productions[49] = {"SpaceNegVal", "spacenegname"};
    
    // ", "
    return productions;
}

void createProductionTbl()
{
    prodTbl.clear();

    prodTbl.insert(prodTbl.end(), {{"Goal", "("}, 0});
    prodTbl.insert(prodTbl.end(), {{"Goal", "num"}, 0});
    prodTbl.insert(prodTbl.end(), {{"Goal", "name"}, 0});
    prodTbl.insert(prodTbl.end(), {{"Expr", "("}, 1});
    prodTbl.insert(prodTbl.end(), {{"Expr", "num"}, 1});
    prodTbl.insert(prodTbl.end(), {{"Expr", "name"}, 1});
    prodTbl.insert(prodTbl.end(), {{"Expr`", "eof"}, 4});
    prodTbl.insert(prodTbl.end(), {{"Expr`", "+"}, 2});
    prodTbl.insert(prodTbl.end(), {{"Expr`", "-"}, 3});
    prodTbl.insert(prodTbl.end(), {{"Expr`", ")"}, 4});
    prodTbl.insert(prodTbl.end(), {{"Term", "("}, 5});
    prodTbl.insert(prodTbl.end(), {{"Term", "num"}, 5});
    prodTbl.insert(prodTbl.end(), {{"Term", "name"}, 5});
    prodTbl.insert(prodTbl.end(), {{"Term`", "eof"}, 8});
    prodTbl.insert(prodTbl.end(), {{"Term`", "+"}, 8});
    prodTbl.insert(prodTbl.end(), {{"Term`", "-"}, 8});
    prodTbl.insert(prodTbl.end(), {{"Term`", "*"}, 6});
    prodTbl.insert(prodTbl.end(), {{"Term`", "/"}, 7});
    prodTbl.insert(prodTbl.end(), {{"Term`", ")"}, 8});
    prodTbl.insert(prodTbl.end(), {{"Factor", "("}, 9});
    prodTbl.insert(prodTbl.end(), {{"Factor", "num"}, 10});
    prodTbl.insert(prodTbl.end(), {{"Factor", "name"}, 11});

    //return prodTbl;
}

// map<vector<string>, int> createProductionTbl(map<int, vector<string>> myProds)
string createProductionTbl(map<int, vector<string>> myProds)
{
    
    vector<string> B;
    set<string> rhs;
    string start =  myProds.at(0)[0];
    string A;
    string elem;
    int colms;
    int rows;
    string output;

    for (auto &it : myProds)
    {
        if (find(nonTerms.begin(), nonTerms.end(), it.second[0]) == nonTerms.end())
        {
            nonTerms.insert(nonTerms.end(), it.second[0]);
            firstElem.insert(firstElem.end(), {it.second[0], {}});
            followElem.insert(followElem.end(), {it.second[0], {}});
        }
    }
    rows = nonTerms.size();

    for (auto &it : myProds)
    {
        if (find(nonTerms.begin(), nonTerms.end(), it.second[1]) == nonTerms.end())
        {
            for (auto &t : it.second)
            {
                if (find(nonTerms.begin(), nonTerms.end(), t) == nonTerms.end())
                {
                    if (find(terms.begin(), terms.end(), t) == terms.end())
                    {
                        terms.insert(terms.end(),t);
                        firstElem.insert(firstElem.end(), {t, {t}});
                    }
                }
            }
        }
    }
    terms.insert(terms.end(), {"eof"});
    // terms.insert("ϵ");
    firstElem.insert(firstElem.end(), {"eof", {"eof"}});
    //firstElem.insert("ϵ", {"ϵ"});
    colms = terms.size();

    //gnereate first
    map<string, set<string>> temp;
    while (firstElem != temp)
    {
        temp = firstElem;
        for (auto &it : myProds)
        {
            int k = it.second.size() - 1;
            B = it.second;
            A = B[0];
            elem = B[1];

            rhs = firstElem[elem];
            if (rhs.find("ϵ") != rhs.end())
            {
                rhs.erase("ϵ");
            }
            
            int i = 1;
            while (firstElem[B[i]].find("ϵ") != firstElem[B[i]].end() && i <= k-1)
            {
                for (auto &el : firstElem[B[i+1]])
                {
                    if (rhs.find(el) == rhs.end())
                    {
                        rhs.insert(el);
                    }
                }
                i++;
            }

            if (i == k && firstElem[B[k]].find("ϵ") != firstElem[B[k]].end())
            {
                rhs.insert("ϵ");
            }
            for (auto &el : rhs)
            {
                if (firstElem[A].find(el) == firstElem[A].end())
                {
                    firstElem[A].insert(el);
                }
            }
        }
    }


    //generate follow
    temp.clear();
    followElem[start].insert("eof");
    
    while (followElem != temp)
    {
        temp = followElem;
        for (auto &it : myProds)
        {
            int k = it.second.size() - 1;
            B = it.second;
            A = B[0];
            elem = B[1];

            rhs = followElem[A];
            for (int i = k; i >= 1; i--)
            {
                elem = B[i];
                //expr -> term expr`
                if (find(nonTerms.begin(), nonTerms.end(), elem) != nonTerms.end())
                {
                    for (auto &it : rhs)
                    {
                        if (followElem[elem].find(it) == followElem[elem].end())
                        {
                            followElem[elem].insert(it);
                        }
                    }
                    if (firstElem[elem].find("ϵ") != firstElem[elem].end())
                    {
                        for (auto &it : firstElem[elem])
                        {
                            if (rhs.find(it) == rhs.end())
                            {
                                rhs.insert(it);
                            }
                        }
                        rhs.erase("ϵ");
                    }
                    else 
                    {
                        rhs = firstElem[elem];
                    }
                }
                else
                {
                    rhs = firstElem[elem];
                }
            }

        }
    }

    tuple<string, string> AB;
    // generate first+
    for (auto &it : myProds)
    {
        B = it.second;
        A = B[0];
        elem = B[1];
        AB = make_tuple(A, elem);

        rhs = firstElem[elem];
        if (rhs.find("ϵ") == rhs.end())
        {
            firstPlus[AB] = rhs;
        }
        else
        {
            for (auto &it : followElem[A])
            {
                if (rhs.find(it) == rhs.end())
                {
                    rhs.insert(it);
                }
            }
            firstPlus[AB] = rhs;
        }
    }

    //generate production table
    
    prodTbl.clear();
    
    for (auto &NT : nonTerms)
    {
        for (auto &T : terms)
        {
            prodTbl.insert(prodTbl.end(), {{NT, T}, -1});
        }        
    }
    
    
    //tuple<string, string> Aw;
    for (auto &it : myProds)
    {
        B = it.second;
        A = B[0];
        elem = B[1];
        AB = make_tuple(A, elem);

        for (auto &el : firstPlus[AB])
        {
            //string w = el;
            prodTbl.at({A, el}) = it.first;
            //std::cout << A << ", " << el << ", " << it.first << endl;
        }
    }

    for (auto &pr : prodTbl)
    {
        A = pr.first[0];
        elem = pr.first[1];
        string val = to_string(pr.second);
        
        output += A + "~ " + elem + "~ " + val + "\n";
    }
    
    return output;
}

int getProduction(string focus, vector<string> word)
{
    int ret = -1;
    string type = word[0];
    string val = word[1];

    if (type.substr(0,1) == " ")
    {
        type = type.substr(1);
    }
    
    if (prodTbl.find({focus, val}) != prodTbl.end())
    {
        ret = prodTbl.at({focus, val});
    }
    else if (prodTbl.find({focus, type}) != prodTbl.end())
    {
        ret = prodTbl.at({focus, type});
    }
    
    

    return ret;
}
