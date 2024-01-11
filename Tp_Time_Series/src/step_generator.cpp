// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "step_generator.hpp"
#include <cmath>
#include <random>


// -- Constructors ------------------------------------------------------------------------------ //

StepGenerator::StepGenerator() {}

StepGenerator::StepGenerator(int _seed) :
    TimeSeriesGenerator(_seed)
{}


// -- Methodes ---------------------------------------------------------------------------------- //

vector<double> StepGenerator::generateTimeSeries(int size) {
    default_random_engine generator(++seed);
    bernoulli_distribution distributionBinary(0.5);
    uniform_int_distribution<int> distributionJump(0,100);
    vector<double> series;
    series.reserve(size);
    int currentValue = 0.0;
    for (int i = 1; i < size + 1; ++i) {
        series.push_back(currentValue);
        if(distributionBinary(generator) == 0) currentValue = distributionJump(generator);
    }
    return series;
}