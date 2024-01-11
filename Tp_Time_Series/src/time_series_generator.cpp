// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "time_series_generator.hpp"


// -- Constructors ------------------------------------------------------------------------------ //

TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}
TimeSeriesGenerator::TimeSeriesGenerator(int _seed) : seed(_seed) {}


// -- Methodes ---------------------------------------------------------------------------------- //

void TimeSeriesGenerator::printTimeSeries(const vector<double>& series) {
    for (double value : series) {
        cout << value;
    }
}