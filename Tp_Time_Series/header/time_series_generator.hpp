// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef TIME_SERIES_GENERATOR_HPP
#define TIME_SERIES_GENERATOR_HPP

#include <iostream>
#include <vector>

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class TimeSeriesGenerator
{
    public:
        // constructors
        TimeSeriesGenerator();
        TimeSeriesGenerator(int _seed);

        // methodes
        virtual vector<double> generateTimeSeries(int size) = 0;
        static void printTimeSeries(const vector<double>& series);

    protected:
        int seed;
};


// -- END --------------------------------------------------------------------------------------- //

#endif