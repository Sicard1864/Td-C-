// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "time_series_dataset.hpp"
#include <cmath>


// -- Constructors ------------------------------------------------------------------------------ //

TimeSeriesDataset::TimeSeriesDataset() :
    zNormalize(false), 
    isTrain(false), 
    maxLength(0),
    numberOfSamples(0)
{}

TimeSeriesDataset::TimeSeriesDataset(bool _zNormalize, bool _isTrain) :
    zNormalize(_zNormalize), 
    isTrain(_isTrain), 
    maxLength(0), 
    numberOfSamples(0)
{}


// -- Methodes ---------------------------------------------------------------------------------- //

vector<double> TimeSeriesDataset::getData() const {
    return data;
}

vector<int> TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series, int label) {
    setMeanAndStdDeviation(series);
    if (zNormalize) {
        for (double value : caculeZNormalize(series)) {
            ++maxLength;
            data.push_back(value);
        }
    } else {
        for (double value : series) {
            ++maxLength;
            data.push_back(value);
        }
    }
    labels.push_back(label);
    ++numberOfSamples;
}

void TimeSeriesDataset::addTimeSeries(const vector<double>& series) {
    setMeanAndStdDeviation(series);
    if (zNormalize) {
        for (double value : caculeZNormalize(series)) {
            ++maxLength;
            data.push_back(value);
        }
    } else {
        for (double value : series) {
            ++maxLength;
            data.push_back(value);
        }
    }
    ++numberOfSamples;
}

void TimeSeriesDataset::setMeanAndStdDeviation(const vector<double>& series) {
    int n = series.size();
    double sum = 0.0;
    double sumSquared = 0.0;
    for (double value : series) {
        sum += value;
        sumSquared += value * value;
    }
    double meanValue = sum / n;
    double stdDevValue = sqrt((sumSquared / n) - (meanValue * meanValue));
    mean.push_back(meanValue);
    stdDeviation.push_back(stdDevValue);
}

vector<double> TimeSeriesDataset::caculeZNormalize(const vector<double>& series) const {
    int n = series.size();
    vector<double> zNormalizeSeries;
    zNormalizeSeries.reserve(series.size());
    for (int i = 0; i < n; ++i) {
        double zNormalizeValue = (series[i] - mean[i]) / stdDeviation[i];
        zNormalizeSeries.push_back(zNormalizeValue);
    }
    return zNormalizeSeries;
}