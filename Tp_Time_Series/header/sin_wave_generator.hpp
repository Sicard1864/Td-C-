// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef SIN_WAVE_GENERATOR_HPP
#define SIN_WAVE_GENERATOR_HPP

#include <iostream>
#include <vector>
#include "time_series_generator.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class SinWaveGenerator : public TimeSeriesGenerator
{
    public:
        // constructors
        SinWaveGenerator();
        SinWaveGenerator(double _ampl, double _freq, double _phi);

        // methodes
        vector<double> generateTimeSeries(int size) override;
    
    private:
        // attributs
        double ampl;
        double freq;
        double phi;
};


// -- END --------------------------------------------------------------------------------------- //

#endif