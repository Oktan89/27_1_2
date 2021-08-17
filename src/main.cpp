#include <iostream>
#include <ctime>
#include <vector>
#include "branch.h"

int main()
{
    std::srand(std::time(nullptr));
    std::vector<Branch*> trees;
    for(int i = 0; i < 1; ++i)
    {
        Branch* tree = new Branch(nullptr);
        trees.push_back(tree);

        int branchBig  = std::rand()%3 + 3;
        for (int j = 0; j < branchBig; ++j)
        {
            Branch* branch = tree->setChild();

            int branchMidl = std::rand()%2 + 2;
            for( int k = 0; k < branchMidl; ++k )
            {
                branch->setChild();
            }
        }
    }
    for(auto tree : trees)
    {
        tree->setAllNameElf();
    }
    
    return 0;
}