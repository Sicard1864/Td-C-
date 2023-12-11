// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef SEARCH_H
#define SEARCH_H


// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <vector>
using namespace std;

// -- Class ------------------------------------------------------------------------------------- //

class SearchingAlgorithm
{
    public:
        // attributs
        int numberComparisons;
        static int totalComparisons;
        static int totalSearch;
        static double averageComparisons;

        // constructors
        SearchingAlgorithm();

        // methodes
        virtual int search(const vector<int>&, int) = 0;

        // prints
        void displaySearchResults(ostream&, int, int) const;
};


// -- END --------------------------------------------------------------------------------------- //

#endif