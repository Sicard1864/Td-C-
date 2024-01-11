// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef KNN_HPP
#define KNN_HPP

#include <iostream>
#include <vector>
#include <string>
#include "time_series_dataset.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class KNN
{
    public:
        // constructors
        KNN(int _k, const string& _similarityMeasure);

        // methodes
        double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData,
                        const vector <int>& ground_truth) const;

    private:
        // attributs
        int k;
        string similarityMeasure;

        // private functions
        vector<int> predict(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData,
                                 const vector<int>& ground_truth) const;

        double euclDistance(const vector<double>& series1, const vector<double>& series2) const;
        double dtwDistance(const vector<double>& series1, const vector<double>& series2) const;
};


// -- END --------------------------------------------------------------------------------------- //

#endif