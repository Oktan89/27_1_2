#include "branch.h"

Branch::Branch(Branch* branch)
{
    if(parent != this)
    {
        Branch* child = new Branch(this);
        children.push_back(child);
    }

}