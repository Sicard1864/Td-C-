// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef TIME_SERIES_DATASET_HPP
#define TIME_SERIES_DATASET_HPP

#include <iostream>
#include <vector>

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class TimeSeriesDataset
{
    public:
        // constructors
        TimeSeriesDataset();
        TimeSeriesDataset(bool _zNormalize, bool _isTrain);

        // methodes
        vector<double> getData() const;
        vector<int> getLabels() const;
        int getMaxLength() const;
        int getNumberOfSamples() const;
        void addTimeSeries(const vector<double>& series, int label);
        void addTimeSeries(const vector<double>& series);
    
    private:
        // attributs
        bool zNormalize;
        bool isTrain;
        vector<double> data;
        vector<int> labels;
        vector<double> mean;
        vector<double> stdDeviation;
        int maxLength;
        int numberOfSamples;

        // private functions
        void setMeanAndStdDeviation(const vector<double>& series);
        vector<double> caculeZNormalize(const vector<double>& series) const;
};


// -- END --------------------------------------------------------------------------------------- //

#endif