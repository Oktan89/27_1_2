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