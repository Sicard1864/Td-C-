// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef GAUSSIAN_GENERATOR_HPP
#define GAUSSIAN_GENERATOR_HPP

#include <iostream>
#include <vector>
#include "time_series_generator.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class GaussianGenerator : public TimeSeriesGenerator
{
    public:
        // constructors
        GaussianGenerator();
        GaussianGenerator(int _seed, double _mean, double _stdDeviation);

        // methodes
        vector<double> generateTimeSeries(int size) override;

    private:
        double mean;
        double stdDeviation;
};


// -- END --------------------------------------------------------------------------------------- //

#endif