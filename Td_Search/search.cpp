// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "search.h"


// -- Variables static --------------------------------------------------------------------------- //

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

// -- Constructors ------------------------------------------------------------------------------- //

SearchingAlgorithm::SearchingAlgorithm(): numberComparisons(0){}


// -- Methodes ------------------------------------------------------------------------------- //



// -- Prints ------------------------------------------------------------------------------------ //

void SearchingAlgorithm::displaySearchResults(ostream& os, int results, int target) const{
    totalSearch++;
    if (results == -1){
        os << "Searching for the element " << target << " was not successful.";
    }
    else{
        totalComparisons += numberComparisons;
        averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
        os << "It took a total of " << numberComparisons << " comparisons to find the element "; 
        os << target << " on index " << results;
    }
    os << endl << endl;
}