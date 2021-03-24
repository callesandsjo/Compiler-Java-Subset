#include "ST.h"

bool ST::findInScope(string name, string inScope)
{

    if (scope == inScope)
    {
        string name_to_find=inScope + "__Id__" + name;
        //cout << "CHECKING ST: " << name_to_find << ":" << inScope << endl;
        if(identif_map.find(name_to_find) == identif_map.end()){
        return false;
        } else {
        return true;
        }
    }
    else
    {
      for (auto const &elem : method_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return true;
        }
      }
      for (auto const &elem : class_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return true;
        }
      }
    }
    return false;
}

string ST::getType(string name, string inScope)
{

    if (scope == inScope)
    {
        string name_to_find=inScope + "__Id__" + name;
        //cout << "CHECKING ST: " << name_to_find << ":" << inScope << endl;
        if(identif_map.find(name_to_find) == identif_map.end()){
        return "NONE";
        } else {
        return identif_map[name_to_find];
        }
    }
    else
    {
      for (auto const &elem : method_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return elem.second->getType( name,  inScope);
        }
      }
      for (auto const &elem : class_map)
      {
        if (elem.second->findInScope( name,  inScope))
        {
          return elem.second->getType( name,  inScope);
        }
      }
    }
    return "NONE";
}
void ST::print()
{

    for (auto const &elem : identif_map)
    {
      cout << elem.first << ":" << elem.second << endl;
    }
    for (auto const &elem : method_map)
    {
      elem.second->print();
    }
    for (auto const &elem : class_map)
    {
      elem.second->print();
    }
}

ST *ST::check_node(Node *n)
{
    std::list<std::string>::iterator it = std::find(listOfStrs.begin(), listOfStrs.end(), n->type);
    if (it != listOfStrs.end())
    {
      cout << "ADD ST: " << n->value << ":" << n->type << endl;
      if (n->type == "Identifier")
      {
        if (n->parent->type == "VarDeclaration")
        {
          identif_map.insert({this->scope + "__Id__" + n->value, n->parent->children.front()->value});
          return this;
        }
        else if (n->parent->type == "MethodDeclaration")
        {
          identif_map.insert({this->scope + "__Id__" + n->value, n->parent->children.front()->value});
          return this;
        }
        else if (n->parent->type == "ClassDeclaration")
        {
          identif_map.insert({this->scope + "__Id__" + n->value, this->scope + "__Id__" + n->value});
          return this;
        }
        else if (n->parent->type == "MainClass")
        {
          if (n->parent->children.front()->value == n->value)
          {
            identif_map.insert({this->scope + "__Id__" + n->value, this->scope + "__Id__" + n->value});
          }
          else
          {
            identif_map.insert({this->scope + "__Id__" + n->value, "String[]"});
          }
          return this;
        }
        else if (n->parent->type == "Arguments")
        {
          std::string my_type = "";
          for (auto i = n->parent->children.begin(); i != n->parent->children.end(); i++)
          {
            if ((*i)->value == n->value)
            {
              break;
            }
            my_type = (*i)->value;
          }
          identif_map.insert({this->scope + "__Id__" + n->value, my_type});
          return this;
        }

        //identif_map.insert({this->scope+"__Id__"+n->value, n->type});
        return this;
      }
      else if (n->type == "MainClass")
      {
        ST *s = new ST(this->scope + "__Main__" + n->value, this);
        class_map.insert({n->value, s});
        return s;
      }
      else if (n->type == "ClassDeclaration")
      {
        ST *s = new ST(this->scope + "__Class__" + n->value, this);
        class_map.insert({n->value, s});
        return s;
      }
      else if (n->type == "MethodDeclaration")
      {
        ST *s = new ST(this->scope + "__Method__" + n->value, this);
        method_map.insert({n->value, s});
        return s;
      }
      else
      {
        cout << "Not supposed to be here!" << endl;
        return this;
      }
    }
    return this;
  }