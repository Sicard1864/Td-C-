// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "knn.hpp"
#include <cmath>
#include <algorithm>
#include <limits>


// -- Constructors ------------------------------------------------------------------------------ //

KNN::KNN(int _k, const string& _similarityMeasure) :
    k(_k),
    similarityMeasure(_similarityMeasure)
{}


// -- Methodes ---------------------------------------------------------------------------------- //

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData,
                     const vector <int>& ground_truth) const {
    size_t size = ground_truth.size();
    vector<int> predictions = predict(trainData, testData, ground_truth);
    int nb = 0;

    for (size_t i = 0; i < size; ++i) {
        if (predictions[i] == ground_truth[i]) {
            ++nb;
        }
    }
    return static_cast<double>(nb) / size;
}

vector<int> KNN::predict(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData,
                         const vector<int>& ground_truth) const {
    vector<int> predictions;
    predictions.reserve(ground_truth.size());

    int sizeSeries = trainData.getMaxLength()/trainData.getNumberOfSamples();

    size_t nbTrainSeries = trainData.getNumberOfSamples();
    size_t nbTestSeries = testData.getNumberOfSamples();
    vector<double> trainSeries = trainData.getData();
    vector<double> testSeries = testData.getData();

    // cout << endl << "similarityMeasure k : " << similarityMeasure << " " << k;
    for (size_t i = 0; i < nbTestSeries; ++i) {
        vector<double> testSerie(testSeries.begin()+i, testSeries.begin()+i+sizeSeries);

        /*cout << endl << "testSerie " << i << " : ";
        for (double valueTest : testSerie) {
            cout << " " << valueTest;
        }*/

        vector<pair<double, int>> neighbors;                            // similarity - choosedClass
        for (size_t j = 0; j < nbTrainSeries; ++j) {
            vector<double> trainSerie(trainSeries.begin()+j, trainSeries.begin()+j+sizeSeries);

            /*cout << endl << "\ttrainSerie " << j << " : ";
            for (double valueTrain : trainSerie) {
                cout << " " << valueTrain;
            }*/
            double similarity;
            if (similarityMeasure == "euclidean_distance") {
                similarity = euclDistance(testSerie, trainSerie);
                //cout << "\tsimilarity: " << similarity << "\tlabel: " << trainData.getLabels()[j];
            } else if (similarityMeasure == "dtw") {
                similarity = dtwDistance(testSerie, trainSerie);
                //cout << "\tsimilarity: " << similarity << "\tlabel: " << trainData.getLabels()[j];
            } else {
                cout << endl << "ERROR";
            }
            neighbors.emplace_back(similarity, trainData.getLabels()[j]);
        }

        sort(neighbors.begin(), neighbors.end(), [](const auto& a, const auto& b) { 
            return a.first < b.first; 
        });

        // sélection des k plus proche voisin
        //cout << endl << "\tk neightbors selected : ";
        vector<int> nearestNeighbors;
        nearestNeighbors.reserve(k);
        for (int j = 0; j < k; ++j) {
            nearestNeighbors.push_back(neighbors[j].second);
            //cout << "(" << neighbors[j].second << ", " << neighbors[j].first << ") ";
        }

        // attribution de la classe
        int choosedClass = -1;
        int maxVotes = -1;
        unordered_map<int,int> votes;                                  // choosedClass - Nb de votes
        for (int neighbor : nearestNeighbors) {
            ++votes[neighbor];
            if (votes[neighbor] > maxVotes) {
                maxVotes = votes[neighbor];
                choosedClass = neighbor;
            }
        }
        predictions.push_back(choosedClass);
    }
    /*cout << endl << "predictions : ";
    for (auto v : predictions) {
        cout << " " << v;
    }
    cout << endl << "truth : ";
    for (auto v : ground_truth) {
        cout << " " << v;
    }
    cout << endl;*/

    return predictions;
}

double KNN::euclDistance(const vector<double>& x, const vector<double>& y) const {
    double sum = 0.0;
    double diff;
    for (size_t i = 0; i < x.size(); ++i) {
        diff = x[i] - y[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double KNN::dtwDistance(const vector<double>& x, const vector<double>& y) const {
    size_t L = x.size();
    vector<vector<double>> D(L + 1, vector<double>(L + 1, 0.0));
    for (size_t i = 1; i <= L; ++i) {
        D[i][0] = numeric_limits<double>::infinity();
        D[0][i] = numeric_limits<double>::infinity();
    }
    double diff;
    double insert;
    double deleteOp;
    double move;
    for (size_t i = 1; i <= L; ++i) {
        for (size_t j = 1; j <= L; ++j) {
            diff = pow(x[i - 1] - y[j - 1], 2);
            insert = D[i][j - 1];
            deleteOp = D[i - 1][j];
            move = D[i - 1][j - 1];
            D[i][j] = diff + min({insert, deleteOp, move});
        }
    }
    return sqrt(D[L][L]);
}