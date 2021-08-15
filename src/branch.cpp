#include "branch.h"

Branch::Branch(Branch* branch): parent(branch)
{
    if(parent == nullptr)
    {
        Branch* child;
        for(int i = 0; i < 5; ++i)
        {
            child = new Branch(this);
            children.push_back(child);
            child = nullptr;
        }
        
    }

}

Branch::~Branch()
{
    for(auto ptr : children)
        delete ptr;
}