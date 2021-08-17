#include "branch.h"
#include <cstdlib>
#include <iostream>

Branch::Branch(Branch* parent): _parent(parent)
{
  

}

Branch* Branch::setChild()
{
    Branch* child = new Branch(this);
    children.push_back(child);
    return child;
}

Branch::~Branch()
{
    for(auto ptr : children)
        delete ptr;
}

void Branch::setAllNameElf()
{
    if(_parent != nullptr)
    {
        std::cout<<"Enter elf name: ";
        std::cin>>elfName;
    }  

    if(children.empty())
        return;

    for(auto ch : children)
    {
        ch->setAllNameElf();
    }
}

Branch* Branch::findElf(const std::string& name)
{
    if(name == elfName)
        return this;
    
    if(children.empty())
        return nullptr;
    
    for(auto ch : children)
    {
        Branch* elf = ch->findElf(name);
        if(elf != nullptr)
            return elf; 
    }
    return nullptr;
}

int Branch::countNeighbors()
{
    int col{0};

    if(children.empty())
    {
        if(_parent->elfName != "None")
            ++col;
        for(auto ch : _parent->children)
        {
            if(ch->elfName != "None")
                ++col;
        }
            
    }
    else
    {
        if(elfName != "None")
            ++col;
        for(auto ch : children)
        {
            if(ch->elfName != "None")
                ++col;
        }

    }
    return (static_cast<bool>(col))? --col : col;
}