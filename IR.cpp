#include "IR.h"


int preced(string ch) 
{
   if(ch == "+" || ch == "-") 
   {
      return 1;              //Precedence of + or - is 1
   }
   else if(ch == "*" || ch == "/") 
   {
      return 2;            //Precedence of * or / is 2
   }
   else if(ch == "^") 
   {
      return 3;            //Precedence of ^ is 3
   }
   else 
   {
      return 0;
   }
}

void inToPost(string infix, map<int, vector<string>> tokens) 
{
    stack<string> stk;
    stk.push("#");               //add some extra character to avoid underflow
    stack<string> postStk;
    postStk.push("#");
    string postfix = "";         //initially the postfix string is empty
    // string::iterator it;

    
    intRep temp;
    string tempName;
    string var;
    string typ;
    vector<string> typnum;
    string prev = "~";

    // for(it = infix.begin(); it!=infix.end(); it++) 
    for (auto &it : tokens)
    {
        typnum = it.second;
        var = typnum[1];
        typ = typnum[0];
        if (proceed == 2)
        {
            if (var == "}")
            {
                proceed = -1;
                cout << "Last part of the procedure. No need to process yet." << endl;
                return;
            }
            else 
            {
                cout << "Still in the procedure. No need to process yet." << endl;
                return;
            }
        }
        if (typ == "Key Word")
        {
            if (var == "procedure")
            {
                proceed = 2;
                cout << "This is a procedure. No need to process yet." << endl;
                return;
            }
            else if (var.find("print") == 0)
            {
                temp.type = "print";
                prev = "print";
                temp.proceedType = var;
            }
            else
            {
                temp.type = var;
                prev = typ;
            }
            
        }
        else if (prev == "Key Word" && typ == "name")
        {
            if (IRList.find(var) == IRList.end())
            {
                temp.name = var;
                tempName = var;
            }
            else
            {
                // cout << "\t\033[31mVariable already exists!!! \033[0mCan not have two variables with the same name." << endl;
                cout << "\t\033[31mVariable \033[35m" << var << "\033[31m can't be re-declared\033[33m!\033[36m!\033[35m! \033[0m" << endl;
                return;
            }
            prev = "~";
        }
        else if (prev == "procedure" && typ == "name")
        {
            temp.proceedName = var;
        }
        else if (prev == "print")
        {
            temp.name = "print" + var;
            temp.proceedName = var;
            temp.result = future;
        }
        else if (var == "=")
        {
            if (prev == "name")
            {
                tempName = postStk.top();
                if (IRList.find(tempName) != IRList.end())
                {
                    temp = IRList.at(tempName);
                }
                postStk.pop();
                postfix = "";
                prev = "~";
            }            
        }
        else
        {
            // int p = typ.find("name");
            if (typ.find("name") != -1)
            {
                if (IRList.find(var) == IRList.end())
                {
                    cout << "\t\033[31mVariable \033[35m" << var << "\033[31m hasn't been declared\033[33m!\033[36m!\033[35m! \033[0m" << endl;
                    return;
                }
                postfix += var;
                postStk.push(var);
                prev = "name";
            } 
            // p = typ.find("dig");
            else if (typ.find("dig") != -1)
            {
                postfix += var;      //add to postfix when character is letter or number
                postStk.push(var);
            }
            else if(var == "(")
            {
                stk.push("(");
            }
            else if(var == "^")
            {
                stk.push("^");
            }
            else if(var == ")") 
            {
                while(stk.top() != "#" && stk.top() != "(") 
                {
                    postfix += stk.top(); //store and pop until ( has found
                    postStk.push(stk.top());
                    stk.pop();
                }
                stk.pop();          //remove the "(" from stack
            }
            else if (var == "=")
            {
                postStk.push(var);
            }
            else 
            {
                if(preced(var) > preced(stk.top()))
                {
                    stk.push(var); //push if precedence is high
                }
                else 
                {
                    while(stk.top() != "#" && preced(var) <= preced(stk.top())) 
                    {
                    postfix += stk.top();        //store and pop until higher precedence is found
                    postStk.push(stk.top());
                    stk.pop();
                    }
                    stk.push(var);
                }
            }
        }
    }
    
    while(stk.top() != "#") 
    {
        postfix += stk.top();        //store and pop until stack is not empty.
        postStk.push(stk.top());
        stk.pop();
    }
    // stk.push("#");
    while (postStk.top() != "#")
    {
        if (postStk.top() == "=")
        {
            postStk.pop();
            if (postStk.top() != "#")
            {
                postStk.pop();
            }
        }
        stk.push(postStk.top());
        postStk.pop();
    }

    temp.postStack = stk;
    temp.postFix = postfix;
    string test = processIR(temp);
    temp.result = test;
    future = test;
    IRList.insert(IRList.end(), {tempName, temp});

    cout << "\tEvaluates to \033[36m" << test << "\033[0m" << endl;
    //return postfix;


}

string processIR(intRep proc)
{
    if (proc.type == "procedure")
    {
        return "This is a procedure. No need to process yet.\n";
    }
    if (proc.type == "print")
    {
        return "";
    }
    stack<string> expr = proc.postStack;
    string tempName = proc.name;
    stack<string> results;
    int pos = tempName.find("z");
    tempName = tempName.substr(0, pos);
    string var;
    string val1;
    string answer;
    string val2;
    intRep temp;
    float ishval1;
    float ishval2;
    float ishResult;
    int numval1;
    int numval2;
    int numResult;
    if (proc.type == "ish")
    {
        while (expr.top() != "#")
        {
            var = expr.top(); // expr.top();
            if (IRList.find(var) != IRList.end())
            {
                temp = IRList.at(var);
                results.push(temp.result);
                expr.pop();
            }
            
            else if (mathBits.find(var) == mathBits.end())
            {
                results.push(var);
                expr.pop();
            }
            else 
            {
                val1 = results.top();
                results.pop();
                val2 = results.top();
                results.pop();

                ishval1 = stof(val1);
                ishval2 = stof(val2);
                
                char ch = var[0];
                switch (ch)
                {
                    case '+': 
                        ishResult = ishval2 + ishval1; 
                        break;
                    case '-': 
                        ishResult = ishval2 - ishval1;
                        break;
                    case '*': 
                        ishResult = ishval2 * ishval1; 
                        break;
                    case '/': 
                        if (ishval1 == 0)
                        {
                            // cout << "\t\033[31mCan't divide by zero!!!" << endl;
                            return "\t\033[31mCan't divide by zero!!!";
                        }
                        ishResult = ishval2 / ishval1;
                        break;
                    case '^':
                        ishResult = pow(ishval2, ishval1);
                        break;
                    
                }
                answer = to_string(ishResult);
                results.push(answer);
                expr.pop();
            }
        }
    }
    if (proc.type == "num")
    {
        while (expr.top() != "#")
        {
            var = expr.top(); // expr.top();
            if (IRList.find(var) != IRList.end())
            {
                temp = IRList.at(var);
                results.push(temp.result);
                expr.pop();
            }
            
            else if (mathBits.find(var) == mathBits.end())
            {
                results.push(var);
                expr.pop();
            }
            else 
            {
                val1 = results.top();
                results.pop();
                val2 = results.top();
                results.pop();

                numval1 = stoi(val1);
                numval2 = stoi(val2);
                
                char ch = var[0];
                switch (ch)
                {
                    case '+': 
                        numResult = numval2 + numval1; 
                        break;
                    case '-': 
                        numResult = numval2 - numval1;
                        break;
                    case '*': 
                        numResult = numval2 * numval1; 
                        break;
                    case '/': 
                        if (numval1 == 0)
                        {
                            // cout << "\t\033[31mCan't divide by zero!!!" << endl;
                            return "\t\033[31mCan't divide by zero!!!";
                        }
                        numResult = numval2 / numval1;
                        break;
                    case '^':
                        numResult = pow(numval2, numval1);
                        break;
                }
                answer = to_string(numResult);
                results.push(answer);
                expr.pop();
                
            }
        }
    }

    answer = results.top();
    results.pop();
    // proc.result = answer;

    return answer;
}

map<string, intRep> getList()
{
    return IRList;
}
