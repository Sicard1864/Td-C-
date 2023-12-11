// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include <cmath>
#include "jump_search.h"

int JumpSearch::search(const vector<int>& arr, int target){
    numberComparisons = 0;
    int x = sqrt(arr.size());
    int i0 = arr.size()%x;
    cout << x << endl << i0 << endl << arr.size() << endl;
    for(int i = 0; i < x; ++i){
        numberComparisons++;
        if(target < arr[i*x]){
            for(int j = 0; j < x; ++j){
                numberComparisons++;
                if(arr[i*(x-1)+j] == target){
                    return i*(x-1)+j;
                }
            }
        }
    }
    for(int i = 0; i < i0; ++i){
        if(arr[x*i+i] == target){
            numberComparisons++;
            return i;
        }
    }
    return -1;
}