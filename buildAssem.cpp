#include "buildAssem.h"



void beginAssembly(string name)
{
    string initial = ";--------------\n;Program Name: " + name + "\n;--------------\n\n";
    beginAsm += initial;
    functionAssembly();
}
void functionAssembly()
{
    string printInt = "printInt:\n\n";
    string pushStack = "\tpush \trbp \n\tpush \trax \n\tpush \trcx\n\n";
    string movPrint = "\tmov \trdi, fmtuint\n \tmov \trsi, rax\n \txor \trax, rax\n\n";
    string movString = "\tmov \trdi, fmtstr\n \tmov \trsi, rax\n \txor \trax, rax\n\n";
    string callPrint = "\tcall    [rel printf wrt ..got]\n";
    string popStack = "\tpop \trcx \n\tpop \trax \n\tpop \trbp \n\tret\n\n";
    string printString = "printString:\n";  

    printInt = printInt + pushStack + movPrint + callPrint + popStack;
    printString = printString + pushStack + movString + callPrint + popStack; 
    funcAsm = printInt + printString; 
    textAssem();
}
void dataAssembly(string name, string value)
{
    // string name;
    // string value;
    if (initData == false)
    {
        string initial = "\tfmtstr   db \"%s\",0 \n\tfmtuint   db \"%d\",10,0 \n\tfmtfloat      db \"%f\", 0\n";
        dataAsm = dataAsm + initial;
        initData = true;
    }

    dataAsm = dataAsm + "\t" + name + "\tdw   " + value + "\n";
    
}
void unInitDataAssembly(string name, string type)
{
    unInitDataAsm = unInitDataAsm + "\t" + name + "\tresb\t1\t;an " + type + "\n";
}
void textAssem()
{
    textAsm += "GLOBAL main\n \nextern printf\nextern scanf\nextern exit \n";
}
void bodyAssem(map<string, intRep> IRList)
{
    mainAsm = "main:\n";
    intRep IRtemp;
    for (auto &el : IRList)
    {
        IRtemp = el.second;
        if (IRtemp.type == "print")
        {
            var = IRtemp.result;
            mainAsm += "push rbp\n\n";
            if (IRtemp.proceedType == "printNum")
            {
                temp = "; print integer back out \nlea rdi, [fmtuint] \nmov rsi, [" + var + "] \nxor rax, rax \ncall printf\n\n";
            }
            if (IRtemp.proceedType == "printIsh")
            {
                temp = "; print float \nlea rdi, [fmtfloat] \nmovss xmm0, [" + var + "] \ncvtss2sd xmm0, xmm0 \nmov rax, 1 \ncall printf \ncall printf\n\n";
            }
        }
        if (IRtemp.type == "procedure")
        {

        }
        else
        {
            temp = "; " + IRtemp.postFix + " = " + IRtemp.result + "\n";
            dataAssembly(IRtemp.name, IRtemp.result);
        }
        mainAsm += temp;
        unInitDataAssembly("Brad is ", "great\n");
    }
}
string fullAssembly()
{  
    temp = beginAsm + dataAsm + unInitDataAsm + textAsm + funcAsm + mainAsm + endAsm;
    return temp;
}
void endAssembly(string name)
{
    endAsm = "my_exit: \n\tmov \trax, 60 \n\txor \trdi, rdi \n\tsyscall";
}
