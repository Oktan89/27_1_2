#include <iostream>
#include <ctime>
#include <vector>
#include "branch.h"

int main()
{
    std::srand(std::time(nullptr));
    std::vector<Branch*> trees;
    for(int i = 0; i < 5; ++i)
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

    std::string name;
    std::cout<<"Enter name to find Elf:";
    std::cin>>name;
    Branch* brenchElf = trees[0]->findElf(name);
    std::cout<<"Elf "<<name<<" have "<<brenchElf->countNeighbors()<<" neighbors."<<std::endl;
    return 0;
}