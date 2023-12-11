// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H


// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <vector>
#include "search.h"
using namespace std;

// -- Class ------------------------------------------------------------------------------------- //

class BinarySearch : public SearchingAlgorithm
{
    public:
        int search(const vector<int>&, int) override;                                              
};


// -- END --------------------------------------------------------------------------------------- //

#endif