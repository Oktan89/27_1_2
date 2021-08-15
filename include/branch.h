#pragma once
#include <string>
#include <vector>

class Branch
{
    Branch* parent  = nullptr;
    std::vector<Branch*> children;
    std::string elfName = "None";
public:
    Branch(Branch* branch);
    ~Branch();

};