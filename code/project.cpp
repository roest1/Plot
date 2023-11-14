#include <Python.h>

#include <iostream>
#include <iomanip>

#include "IndicatorBacktestCpp.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    std::string csvFilename = "/Users/rileyoest/VS_Code/csc3380_proj/data/TSLA_indicators.csv";
    double initialCapital = 10000.0;
    double positionSize = 100.0;

    IndicatorBacktestCpp indicatorBacktest(csvFilename, initialCapital, positionSize);
    cout << "Indicator Backtest" << endl;

    indicatorBacktest.plotBollingerBands();
    indicatorBacktest.plotDualThrust();
    indicatorBacktest.plotHeikinAshi();
    indicatorBacktest.plotAwesome();
    indicatorBacktest.plotMACD();
    indicatorBacktest.plotRSI();
    
    Py_Finalize();

    return 0;
}