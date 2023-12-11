// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "linear_search.h"

int LinearSearch::search(const vector<int>& arr, int target){
    numberComparisons = 0;
    for(unsigned int i = 0; i < arr.size(); ++i){
        numberComparisons++;
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}



/* boucle for basé sur une plage
Elle rend plus concis et plus lisible le code   !=  plus plus explicite
Elle est particulièrement utile lorsque vous n'avez pas besoin de l'indice lui-même.

int LinearSearch::search(const vector<int>& arr, int target){
    numberComparisons = 0;
    int i = 0;
    for(auto& v : arr){
        numberComparisons++;
        if(v == target){
            return i;
        }
        i++;
    }
    return -1;
}
*/