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



struct LineParts {
std::string first;
std::string second;
std::string third;
int val=0;
void add(std::string p) {
    if (val==0) first=p;
    if (val==1) second=p;
    if (val==2) third=p;
    val++;
    }
};


std::vector<std::string> getFilesFromDir(const std::string& pattern){
    glob_t dir_result;
    glob(pattern.c_str(),GLOB_TILDE,NULL,&dir_result);
    std::vector<std::string> files;
    for(unsigned int i=0;i<dir_result.gl_pathc;++i){
        files.push_back(std::string(dir_result.gl_pathv[i]));
    }
    globfree(&dir_result);
    return files;
}

Method * readFile(std::string name)
{
  std::vector<LineParts> lv;
  std::regex reg("\\s+");

  std::ifstream myfile(name);
  std::string line;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //std::cout << line << '\n';
      LineParts l;
      std::sregex_token_iterator iter(line.begin(), line.end(), reg, -1);
      std::sregex_token_iterator tend;

      std::vector<std::string> vec(iter, tend);
      for (auto a : vec)
          {
              //std::cout << a << std::endl;
              l.add(a);
          }
       lv.push_back(l);
    }
    myfile.close();
  }


  std::map<std::string,std::string> labels;
  std::list<std::string> vlabels;
  Method *m= new Method();
    bool isLabel=false;
    std::string lName;
    std::string sName;
    for (auto a : lv)
    {
      // std::cout << a.first<< std::endl;
       std::size_t found=a.first.find(':');
       if (found!=std::string::npos) {
            lName=a.first.substr(0,found);
            vlabels.push_back(lName);
            isLabel=true;
            //std::cout << "label "<<a.first<< std::endl;
       } else {
       if (isLabel) {
            while(vlabels.size()>0)
            {
                std::string c=vlabels.back();
                labels[c]=a.first;
            //std::cout << "label "<<c<<"="<<a.first<< std::endl;
            vlabels.pop_back();

            }
            isLabel=false;
       }
       }
    }
    std::string moduleName=lv.at(0).first;
    if (moduleName == "start:") {
        m->isStart=true;
        moduleName=lv.at(1).first;
    }
    std::size_t fcolon=moduleName.find(':');
    moduleName=moduleName.substr(0,fcolon);
    std::size_t underscore=moduleName.find('_');
    moduleName=moduleName.substr(0,underscore)+"."+moduleName.substr(underscore+1);

    m->name=moduleName;
 for (auto a : lv)
    {
     std::size_t found=a.first.find(':');
     if (found!=std::string::npos) {
           continue;
     }
     if (a.second == "goto") {
        std::string lName=a.third;
        a.third=labels[lName];
     }
     if (a.second == "iffalsegoto") {
             std::string lName=a.third;
             a.third=labels[lName];
          }
     m->instructions.push_back(new Instruction(a.first,a.second,a.third));
    }
  return m;
}

int main(int argc, char **argv)
{
  bool debug=false;
  if (argc == 1)
  {
      std::cout << argv[0] << " [-v] bitecode dir"<< std::endl;
      return 1;
  }
  std::string outdir=argv[1];
  if (outdir == "-v" ) {
     std::cout << " enable debug"<< std::endl;

    debug=true;
    if (argc == 2)
      {
          std::cout << argv[0] << " [-v] bitecode dir"<< std::endl;
          return 1;
      }
      outdir=argv[2];
  }
    //Method * m=readFile(argv[1]);
    //m->print();
    Program *p=new Program();
    p->debug=debug;

    std::vector<std::string> byteFiles=getFilesFromDir(outdir+"/*.byteCode");
    for (auto bFile : byteFiles)
    {
        //std::cout << "Byte file = " << bFile << std::endl;
        Method * m=readFile(bFile);
        m->debug=debug;
        p->methods[m->name]=m;
        if (m->isStart)
            p->startName=m->name;

        //std::cout << "Method name  = " << m->name << std::endl;
        //m->print();
    }

     Interpreter *interpreter= new Interpreter(p,debug);
        interpreter->execute();
        delete interpreter;
    return 0;
}