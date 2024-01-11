// ---------------------------------------------------------------------------------------------- //
//  Arthur SICARD - 2A IR Alt
//
//      g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o prog && ./prog
//
//
// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <string>

#include "time_series_generator.hpp"
#include "gaussian_generator.hpp"
#include "step_generator.hpp"
#include "sin_wave_generator.hpp"
#include "time_series_dataset.hpp"
#include "knn.hpp"

using namespace std;


// -- Main -------------------------------------------------------------------------------------- //

int main()
{
    /* gaussian generator exemple

    for(int i = 1; i<10; ++i){
        cout << endl;
        GaussianGenerator gauss_serie(i, 0.0, 1.0);
        TimeSeriesGenerator::printTimeSeries(gauss_serie.generateTimeSeries(10));
    }*/

    /* step generator exemple

    for(int i = 0; i<10; ++i){
        cout << endl;
        StepGenerator step_serie(i);
        TimeSeriesGenerator::printTimeSeries(step_serie.generateTimeSeries(10));
    }*/

    /* sin wave generator exemple

    cout << endl;
    SinWaveGenerator sin_serie(1.0, 1.0, 0.0);
    TimeSeriesGenerator::printTimeSeries(sin_serie.generateTimeSeries(10));
    */

    TimeSeriesDataset trainData(false, true), testData(false, false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    int size = 50; //50

    vector<double> gaussian1 = gsg.generateTimeSeries(size);
    trainData.addTimeSeries(gaussian1, 0);
    vector<double> gaussian2 = gsg.generateTimeSeries(size);
    trainData.addTimeSeries(gaussian2, 0);

    vector<double> sin1 = swg.generateTimeSeries(size);
    trainData.addTimeSeries(sin1, 1);
    vector<double> sin2 = swg.generateTimeSeries(size);
    trainData.addTimeSeries(sin2, 1);

    vector<double> step1 = stg.generateTimeSeries(size);
    trainData.addTimeSeries(step1, 2);
    vector<double> step2 = stg.generateTimeSeries(size);
    trainData.addTimeSeries(step2, 2);

    vector<int> ground_truth;

    vector<double> gaussianTest = gsg.generateTimeSeries(size);
    testData.addTimeSeries(gaussianTest);
    ground_truth.push_back(0);

    vector<double> sinTest = swg.generateTimeSeries(size);
    testData.addTimeSeries(sinTest);
    ground_truth.push_back(1);

    vector<double> stepTest = stg.generateTimeSeries(size);
    testData.addTimeSeries(stepTest);
    ground_truth.push_back(2);

    KNN knn_1(1, "dtw");
    cout << endl << "dtw 1 : " << knn_1.evaluate(trainData, testData, ground_truth);

    KNN knn_2(1, "euclidean_distance");
    cout << endl << "euc 1 : " << knn_2.evaluate(trainData, testData, ground_truth);

    KNN knn_3(10*size/100, "dtw");
    cout << endl << "dtw 10% : " << knn_3.evaluate(trainData, testData, ground_truth);

    KNN knn_4(10*size/100, "euclidean_distance");
    cout << endl << "euc 10% : " << knn_4.evaluate(trainData, testData, ground_truth);

    KNN knn_5(33*size/100, "dtw");
    cout << endl << "dtw 33% : " << knn_5.evaluate(trainData, testData, ground_truth);

    KNN knn_6(33*size/100, "euclidean_distance");
    cout << endl << "euc 33% : " << knn_6.evaluate(trainData, testData, ground_truth);
    
    cout << endl << endl;
    return 0;
}