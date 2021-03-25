#ifndef THREE_ADDRESS_CODES_H
#define THREE_ADDRESS_CODES_H

#include <string>
#include <iostream>


class TAC {
    public:
        std::string result, left, operation, right;
        bool useEqual;
        TAC(std::string result="", std::string left="", std::string operation="", std::string right="", bool useEqual=true) : result(result), left(left), operation(operation), right(right), useEqual(useEqual) {
            printTAC();
        }
        void printTAC(){
            if (useEqual)
                std::cout << result << " := " << left << " " << operation << " " << right << std::endl;
            else
                std::cout << result << " " << left << " " << operation << " " << right << std::endl;
        }
};

class Expression : public TAC {
    public:
        Expression(std::string result, std::string left, std::string operation, std::string right) : TAC(result, left, operation, right){} //x := y op z    
};

class UnaryExpression : public TAC {
    public:
        UnaryExpression(std::string result, std::string left, std::string operation) : TAC(result, left, operation){} //x := ! y
};

class NewExpression : public TAC {
    public:
        NewExpression(std::string result, std::string operation) : TAC(result, "new", operation){} //x := new Y 
};

class NewArrayExpression : public TAC {
    public:
        NewArrayExpression(std::string result, std::string right) : TAC(result, "new", "INT,", right){} //x := new Y, Z
};

class LengthExpression : public TAC {
    public:
        LengthExpression(std::string result, std::string operation) : TAC(result, "length", operation){} //x := length y
};

class MethodCallExpression : public TAC {
    public:
        MethodCallExpression(std::string result, std::string operation, std::string right) : TAC(result, "call", operation, right){} //x := call y N
};

class ParameterExpression : public TAC {
    public:
        ParameterExpression(std::string left) : TAC("param", left, "", "", false){} //x := param y
};

class ReturnExpression : public TAC {
    public:
        ReturnExpression(std::string left) : TAC("return", left, "", "", false){}
    
};


class Assignment : public TAC {
    public:
        Assignment(std::string result, std::string left) : TAC(result, left){}
    
};

class ListAssignment : public TAC {
    public:
        ListAssignment(std::string result, std::string left, std::string operation) : TAC(result + "[" + left + "]", operation){}
    
};

class AssignmentList : public TAC {
    public:
        AssignmentList(std::string result, std::string left, std::string operation) : TAC(result, left + "[" + operation + "]"){}
    
};






#endif