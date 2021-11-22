
#include "productions.h"

map<int, vector<string>> createProduction()
{
    // productions[0] = {"Goal", "Expr"};
    // productions[1] = {"Expr", "Term", "Expr`"};
    // productions[2] = {"Expr`", "+", "Term", "Expr`"};
    // productions[3] = {"Expr`", "-", "Term", "Expr`"};
    // productions[4] = {"Expr`", "£"};
    // productions[5] = {"Term", "Factor", "Term`"};
    // productions[6] = {"Term`", "*", "Factor", "Term`"};
    // productions[7] = {"Term`", "/", "Factor", "Term`"};
    // productions[8] = {"Term`", "£"};
    // productions[9] = {"Factor", "(", "Expr", ")"};
    // productions[10] = {"Factor", "num"};
    // productions[11] = {"Factor", "name"};

    productions[0] = {"Goal", "Expr"};
    productions[1] = {"Expr", "LTerm", "Expr`"};
    productions[2] = {"LTerm", "LFactor", "Term`"};
    productions[3] = {"RTerm", "RFactor", "Term`"};
    productions[4] = {"Expr`", "+", "RTerm", "Expr`"};
    productions[5] = {"Expr`", "-", "RTerm", "Expr`"};
    productions[6] = {"Expr`", "£"};
    productions[7] = {"Term`", "*", "RFactor", "Term`"};
    productions[8] = {"Term`", "/", "RFactor", "Term`"};
    productions[9] = {"Term`", "^", "RFactor", "Term`"};
    productions[10] = {"Term`", "£"};
    productions[11] = {"LFactor", "GFactor"};
    productions[12] = {"LFactor", "negnum"};
    productions[13] = {"LFactor", "negname"};
    productions[14] = {"RFactor", "GFactor"};
    productions[15] = {"GFactor", "(", "Expr", ")"};
    productions[16] = {"GFactor", "PosVal"};
    productions[17] = {"GFactor", "SpaceNegVal"};
    productions[18] = {"PosVal", "num"};
    productions[19] = {"PosVal", "name"};
    productions[20] = {"SpaceNegVal", "spacenegnum"};
    productions[21] = {"SpaceNegVal", "spacenegname"};
    

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
void createProductionTbl(map<int, vector<string>> myProds)
{
    
    vector<string> B;
    set<string> rhs;
    string start =  myProds.at(0)[0];
    string A;
    string elem;
    int colms;
    int rows;

    for (auto &it : myProds)
    {
        if (nonTerms.find(it.second[0]) == nonTerms.end())
        {
            nonTerms.insert(nonTerms.end(), it.second[0]);
            firstElem.insert(firstElem.end(), {it.second[0], {}});
            followElem.insert(followElem.end(), {it.second[0], {}});
        }
    }
    rows = nonTerms.size();

    for (auto &it : myProds)
    {
        if (nonTerms.find(it.second[1]) == nonTerms.end())
        {
            for (auto &t : it.second)
            {
                if (nonTerms.find(t) == nonTerms.end())
                terms.insert(terms.end(),{t});
                firstElem.insert(firstElem.end(), {t, {t}});
            }
        }
    }
    terms.insert(terms.end(), {"eof"});
    // terms.insert("£");
    firstElem.insert(firstElem.end(), {"eof", {"eof"}});
    //firstElem.insert("£", {"£"});
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
            if (rhs.find("£") != rhs.end())
            {
                rhs.erase("£");
            }
            
            int i = 1;
            while (firstElem[B[i]].find("£") != firstElem[B[i]].end() && i <= k-1)
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

            if (i == k && firstElem[B[k]].find("£") != firstElem[B[k]].end())
            {
                rhs.insert("£");
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
                if (nonTerms.find(elem) != nonTerms.end())
                {
                    for (auto &it : rhs)
                    {
                        if (followElem[elem].find(it) == followElem[elem].end())
                        {
                            followElem[elem].insert(it);
                        }
                    }
                    if (firstElem[elem].find("£") != firstElem[elem].end())
                    {
                        for (auto &it : firstElem[elem])
                        {
                            if (rhs.find(it) == rhs.end())
                            {
                                rhs.insert(it);
                            }
                        }
                        rhs.erase("£");
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
        if (rhs.find("£") == rhs.end())
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
        }
    }
    
    // {
    //     B = it.first;
    //     cout << "[" << B[0] << ", " << B[1] << "] -> " << it.second << endl;
    // }
    //return pTbl;
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
