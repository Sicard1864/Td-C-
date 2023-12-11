// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "binary_search.h"

int BinarySearch::search(const vector<int>& arr, int target){
    numberComparisons = 0;
    int start = 0;
    //int end = static_cast<int>(arr.size()) - 1;       // conversion explicite
    int end = arr.size() - 1;
    int mid = (start + end)/2;
    while (start <= end) {
        numberComparisons++;
        if(arr[mid] == target){
            return mid;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    return -1;
}