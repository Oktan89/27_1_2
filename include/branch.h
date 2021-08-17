#pragma once
#include <string>
#include <vector>

class Branch
{
    Branch* _parent  = nullptr;
    std::vector<Branch*> children;
    std::string elfName = "None";
    
public:
    Branch();
    Branch(Branch* parent);
    Branch* setChild();
    void setAllNameElf();
    Branch* findElf(const std::string& name);
    int countNeighbors();
    ~Branch();

};