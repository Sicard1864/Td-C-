// ---------------------------------------------------------------------------------------------- //
//  Arthur SICARD - 2A IR Alt
//
//      g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o prog && ./prog
//
//
// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <vector>
#include <sstream>
#include "search.h"
#include "linear_search.h"
#include "jump_search.h"
#include "binary_search.h"
using namespace std;


// -- Main -------------------------------------------------------------------------------------- //

int main()
{
    // vector<int> arr = {-10, -5, 0, 2, 11, 22, 25, 34, 64, 90};
    vector<int> arr = {-132, -106, -98, -95, -92, -89, -87, -82, -71, -68, -62, -59, -58, -52, -51, -44, -43, -36, -32, -31, -30, -29, -26, -23, -16, -13, -9, -9, -8, -7, -4, -3, -2, 2, 5, 8, 9, 12, 14, 15, 16, 17, 18, 20, 23, 25, 30, 34, 37, 40, 41, 41, 43, 44, 47, 50, 52, 55, 56, 60, 61, 62, 64, 67, 70, 71, 74, 75, 77, 79, 80, 81, 82, 84, 87, 88, 89, 92, 97, 98, 101, 104, 107, 111, 113, 116, 117, 121, 124, 127, 130, 134, 136, 138, 140, 142, 144, 147, 150, 155, 159, 162, 167, 171, 174, 178, 182, 185, 188};
    int target = 107;

    //SearchingAlgorithm* algorithms[] = {new LinearSearch(), new BinarySearch()};
    SearchingAlgorithm* algorithms[] = {new LinearSearch(), new JumpSearch(), new BinarySearch()};

    ostringstream os;

    for (const auto algorithm : algorithms) {
        os << "Searching for " << target << " using ";
        if (dynamic_cast<LinearSearch*>(algorithm)) {
            os << "Linear Search:" << std::endl;
        } else if (dynamic_cast<JumpSearch*>(algorithm)) {
            os << "Jump Search:" << std::endl;
        } else if (dynamic_cast<BinarySearch*>(algorithm)) {
            os << "Binary Search:" << std::endl;
        }
        
        
        int result = algorithm->search(arr, target);
        algorithm->displaySearchResults(os, result, target);
    }

    os << "Total searches: " << SearchingAlgorithm::totalSearch << endl;
    os << "Total comparisons across all searches: " << SearchingAlgorithm::totalComparisons << endl;
    os << "Average comparisons per search: " << SearchingAlgorithm::averageComparisons << endl;

    cout << os.str();
}