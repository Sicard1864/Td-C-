// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H


// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <vector>
#include "search.h"
using namespace std;

// -- Class ------------------------------------------------------------------------------------- //

class JumpSearch : public SearchingAlgorithm
{
    public:
        int search(const vector<int>&, int) override;                                              
};


// -- END --------------------------------------------------------------------------------------- //

#endif