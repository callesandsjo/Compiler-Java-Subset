#ifndef THREE_ADDRESS_CODES_H
#define THREE_ADDRESS_CODES_H

#include <string>
#include <iostream>


class TAC {
    private:
        std::string result, left, operation, right;
    public:
        TAC(std::string result, std::string left, std::string operation, std::string right) : result(result), left(left), operation(operation), right(right) {}
        void printTAC(){
            std::cout << result << " := " << left << " " << operation << " " << right << std::endl;
        }
};

class Expression : public TAC {
    public:
        Expression(std::string result, std::string left, std::string operation, std::string right) : TAC(result, left, operation, right){}
    
};


#endif