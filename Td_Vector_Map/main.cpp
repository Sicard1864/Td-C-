// ---------------------------------------------------------------------------------------------- //
//  Arthur SICARD - 2A IR Alt
//
//      g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o prog && ./prog
//
//
// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;


// -- Prototype --------------------------------------------------------------------------------- //

void countFrequencyBruteForce(const vector<int>& numbers);
map<int,int> countFrequencyOptimal(const vector<int>& numbers);
vector<int> twoSumBruteForce(const vector<int>& nums, int target);
vector<int> twoSumOptimal(const vector <int>& nums, int target);


// -- Main -------------------------------------------------------------------------------------- //

int main ( ) 
{
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << endl << "Frequency (Brute Force) : ";
    countFrequencyBruteForce(numbers);

    cout << endl << "\nFrequency (Optimal) : ";
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << endl << entry.first << " : " << entry.second << " times";
    }

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << endl << endl
        << "Brute Force Solution: [" << indicesBruteForce[0] << ", "
        << indicesBruteForce[1] << "]";

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << endl << endl 
        << "Optimal Solution: [" << indicesOptimal[0] << ", "
        << indicesOptimal[1] << "]";

    cout << endl << endl;
    return 0;
}


// -- Local function ---------------------------------------------------------------------------- //

void countFrequencyBruteForce(const vector<int>& numbers) {
    bool shouldSkip;
    int freq;
    for (unsigned int i = 0; i < numbers.size() ; ++i) {
        shouldSkip = false;
        for (unsigned int k = 0; k < i; ++k) {
            if (numbers[k] == numbers[i]) {
                shouldSkip = true;
                break;
            }
        }
        if (shouldSkip) continue;
        freq = 1;
        for (unsigned int j = i+1; j < numbers.size() ; ++j) {
            if (numbers[j] == numbers[i]) freq++;
        }
    cout << endl << i << " : " << freq;
    }
}

map<int,int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int,int> freq;
    for (int num : numbers) freq[num]++;
    return freq;
}

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (unsigned int i = 0; i < nums.size(); ++i){
        for (unsigned int j = i+1; j < nums.size(); ++i) {
            if (nums[i] + nums[j] == target) return {static_cast<int>(i), static_cast<int>(j)};
        }
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(const vector <int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (unsigned int i = 0; i < nums.size(); ++i) {
        if (numMap.find(target - nums[i]) != numMap.end()) 
            return {numMap[target - nums[i]], static_cast<int>(i)};
        numMap[nums[i]] = static_cast<int>(i);
    }
    return {-1, -1};
}