// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "gaussian_generator.hpp"
#include <cmath>
#include <random>


// -- Constructors ------------------------------------------------------------------------------ //

GaussianGenerator::GaussianGenerator() :
    mean(0.0),
    stdDeviation(1.0)
{}

GaussianGenerator::GaussianGenerator(int _seed, double _mean, double _stdDeviation) :
    TimeSeriesGenerator(_seed),
    mean(_mean),
    stdDeviation(_stdDeviation)
{}


// -- Methodes ---------------------------------------------------------------------------------- //

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    default_random_engine generator(++seed);
    normal_distribution<double> distribution(mean, stdDeviation);
    vector<double> series;
    series.reserve(size);   // alloue de la mémoire sans l'initialiser --> optimise perf
    for (int i = 0; i < size; ++i) {
        series.push_back(distribution(generator));
    }
    return series;
}