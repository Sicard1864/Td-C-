// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "sin_wave_generator.hpp"
#include <cmath>
#include <random>


// -- Constructors ------------------------------------------------------------------------------ //

SinWaveGenerator::SinWaveGenerator() :
    ampl(1.0),
    freq(1.0),
    phi(0.0)
{}

SinWaveGenerator::SinWaveGenerator(double _ampl, double _freq, double _phi) :
    ampl(_ampl),
    freq(_freq),
    phi(_phi)
{}


// -- Methodes ---------------------------------------------------------------------------------- //

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    double x;
    double value;
    vector<double> series;
    for(int i = 0; i < size; ++i) {
        x = (double)i;
        value = ampl * sin(freq * x + phi);
        series.push_back(value);
    }
    return series;
}