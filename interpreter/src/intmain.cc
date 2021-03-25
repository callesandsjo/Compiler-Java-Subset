#include <glob.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include "Method.h"
#include "Program.h"
#include "Interpreter.h"

struct LineParts
{
    // element in instruction line, ex on instruction: 1 iload num
    std::string first;
    std::string second;
    std::string third;
    int val = 0;
    void add(std::string p)
    {
        if (val == 0)
            first = p;
        if (val == 1)
            second = p;
        if (val == 2)
            third = p;
        val++;
    }
};

// pattern = which files to match
std::vector<std::string> getFilesFromDir(const std::string &pattern)
{
    // adding all matched files to vector
    glob_t dir_result;
    glob(pattern.c_str(), GLOB_TILDE, NULL, &dir_result);
    std::vector<std::string> files;
    for (unsigned int i = 0; i < dir_result.gl_pathc; ++i)
    {
        files.push_back(std::string(dir_result.gl_pathv[i]));
    }
    globfree(&dir_result);
    return files;
}

//ex on instruction: 1 iload num 
Method *readFile(std::string name)
{
    std::vector<LineParts> lv;
    std::regex reg("\\s+"); //delimiter for instructions

    std::ifstream myfile(name);
    std::string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //std::cout << line << '\n';
            LineParts l; // struct of instruction parts
            std::sregex_token_iterator iter(line.begin(), line.end(), reg, -1);
            std::sregex_token_iterator tend;

            std::vector<std::string> vec(iter, tend); // vector of instruction
            for (auto a : vec)
            {
                //std::cout << a << std::endl;
                l.add(a);
            }
            lv.push_back(l);
        }
        myfile.close();
    }

    // labels ex block_21:
    // map contains label name and instruction numer (first instruction part)
    std::map<std::string, std::string> labels; 
    std::list<std::string> vlabels;
    Method *m = new Method();
    bool isLabel = false;
    std::string lName;
    std::string sName;
    for (auto a : lv)
    {
        // std::cout << a.first<< std::endl;
        std::size_t found = a.first.find(':');
        if (found != std::string::npos) // for removing the : from label
        {
            lName = a.first.substr(0, found);
            vlabels.push_back(lName);
            isLabel = true;
            //std::cout << "label "<<a.first<< std::endl;
        }
        else
        {
            /*
             check if we have seen any label
             EXAMPLE
             start:
             Bar_main:
             0 iconst 50001 <-- current
             =
             both labels gets the value 0
             */
            if (isLabel)
            {
                while (vlabels.size() > 0)
                {
                    std::string c = vlabels.back();
                    labels[c] = a.first; // maps label with instruction program counter
                    //std::cout << "label "<<c<<"="<<a.first<< std::endl;
                    vlabels.pop_back();
                }
                isLabel = false;
            }
        }
    }
    std::string moduleName = lv.at(0).first; // file name will be first label 
    if (moduleName == "start:")
    {
        m->isStart = true;
        moduleName = lv.at(1).first;
    }
    std::size_t fcolon = moduleName.find(':');
    moduleName = moduleName.substr(0, fcolon); // removes ':' form file name
    std::size_t underscore = moduleName.find('_');
    moduleName = moduleName.substr(0, underscore) + "." + moduleName.substr(underscore + 1); // replace _ with .

    m->name = moduleName;
    for (auto a : lv)
    {
        std::size_t found = a.first.find(':');
        if (found != std::string::npos) // skip if label
        {
            continue;
        }
        if (a.second == "goto")
        {
            std::string lName = a.third;
            a.third = labels[lName]; // replace labelname with instruction counter
        }
        if (a.second == "iffalsegoto") // replace labelname with instruction counter
        {
            std::string lName = a.third;
            a.third = labels[lName];
        }
        m->instructions.push_back(new Instruction(a.first, a.second, a.third));
    }
    return m;
}

int main(int argc, char **argv)
{
    bool debug = false;
    if (argc == 1)
    {
        std::cout << argv[0] << " [-v] bitecode dir" << std::endl;
        return 1;
    }
    std::string outdir = argv[1];

    // checking debug flag 
    if (outdir == "-v")
    {
        std::cout << " enable debug" << std::endl;

        debug = true;
        if (argc == 2)
        {
            std::cout << argv[0] << " [-v] bitecode dir" << std::endl;
            return 1;
        }
        outdir = argv[2];
    }
    
    Program *p = new Program();
    p->debug = debug;

    std::vector<std::string> byteFiles = getFilesFromDir(outdir + "/*.byteCode"); // vector with matched byte code filename
    for (auto bFile : byteFiles)
    {
        Method *m = readFile(bFile);
        m->debug = debug;
        p->methods[m->name] = m; // contains all method file names
        if (m->isStart)
            p->startName = m->name; // program start name
    }

    Interpreter *interpreter = new Interpreter(p, debug);
    interpreter->execute();
    delete interpreter;
    return 0;
}