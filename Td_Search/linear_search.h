// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H


// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <vector>
#include "search.h"
using namespace std;

// -- Class ------------------------------------------------------------------------------------- //

class LinearSearch : public SearchingAlgorithm
{
    public:
        int search(const vector<int>&, int) override;                                              
};


// -- END --------------------------------------------------------------------------------------- //

#endif