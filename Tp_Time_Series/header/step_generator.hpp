// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef STEP_GENERATOR_HPP
#define STEP_GENERATOR_HPP

#include <iostream>
#include <vector>
#include "time_series_generator.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class StepGenerator : public TimeSeriesGenerator
{
    public:
        // constructors
        StepGenerator();
        StepGenerator(int _seed);

        // methodes
        vector<double> generateTimeSeries(int size) override;
};


// -- END --------------------------------------------------------------------------------------- //

#endif