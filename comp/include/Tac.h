#ifndef TAC_H
#define TAC_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
class Tac
{
private:
    std::string op, lns, rns, result;

public:
    Tac(): op(""), lns(""), rns(""), result("") {}
	Tac(std::string _op, std::string _lns, std::string _rns, std::string _result) : op(_op), lns(_lns), rns(_rns), result(_result) {}
    virtual void dump() {printf("%s := %s %s %s\n", result.c_str(), lns.c_str(), op.c_str(), rns.c_str());}
    virtual void dump( std::ofstream *outStream) 
    {
        *outStream <<" "<<result<<" := "<<lns<<" "<<op<<" "<<rns<<"\\n";
    }

    void setOp(std::string s)
    {
        op = s;
    }
    
    std::string getOp()
    {
        return op;
    }

    void setLns(std::string s)
    {
        lns = s;
    }
    
    std::string getLns()
    {
        return lns;
    }

    void setRns(std::string s)
    {
        rns = s;
    }
    
    std::string getRns()
    {
        return rns;
    }

    void setResult(std::string s)
    {
        result = s;
    }

    std::string getResult()
    {
        return result;
    }
};

#endif