#ifndef THREE_ADDRESS_CODES_H
#define THREE_ADDRESS_CODES_H

#include <string>
#include <iostream>


class TAC {
    public:
        std::string result, left, operation, right;
        TAC(std::string result="", std::string left="", std::string operation="", std::string right="") : result(result), left(left), operation(operation), right(right) {
            printTAC();
        }
        void printTAC(){
            std::cout << result << " := " << left << " " << operation << " " << right << std::endl;
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
        NewExpression(std::string result, std::string operation) : TAC(result, "NEW", operation){} //x := ! y
    
};

class Assignment : public TAC {
    public:
        Assignment(std::string result, std::string left) : TAC(result, left){}
    
};


#endif