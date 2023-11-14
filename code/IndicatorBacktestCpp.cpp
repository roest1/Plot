#include "IndicatorBacktestCpp.h"
// Constructor
IndicatorBacktestCpp::IndicatorBacktestCpp(const std::string& csvFilename, double initialCapital, double positionSize) {
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/Users/rileyoest/VS_Code/csc3380_proj/code')");
    
    PyObject *pName = PyUnicode_FromString("indicator_backtest"); // Module name
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        PyObject *pClass = PyObject_GetAttrString(pModule, "IndicatorBacktest");
        if (pClass != nullptr) {
            PyObject *pFilename = PyUnicode_FromString(csvFilename.c_str());
            pyIndicatorBacktest = PyObject_CallFunction(pClass, "Odd", pFilename, initialCapital, positionSize);
            Py_DECREF(pFilename);
            if (pyIndicatorBacktest == nullptr) {
                PyErr_Print();
            }
            Py_DECREF(pClass);
        } else {
            PyErr_Print();
        }
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
    }
}

// Destructor
IndicatorBacktestCpp::~IndicatorBacktestCpp() {
    Py_XDECREF(pyIndicatorBacktest);
}

void IndicatorBacktestCpp::resetState() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "reset_state", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}

void IndicatorBacktestCpp::plotBollingerBands() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "plot_bollinger_bands", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}

// Plot Dual Thrust method
void IndicatorBacktestCpp::plotDualThrust() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "plot_dual_thrust", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}
// Plot Heikin-Ashi
void IndicatorBacktestCpp::plotHeikinAshi() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "plot_heikin_ashi", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}

// Plot Awesome 
void IndicatorBacktestCpp::plotAwesome() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "plot_awesome", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}
// Plot MACD
void IndicatorBacktestCpp::plotMACD() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "plot_macd", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}
// Plot RSI
void IndicatorBacktestCpp::plotRSI() {
    if (pyIndicatorBacktest != nullptr) {
        PyObject_CallMethod(pyIndicatorBacktest, "plot_rsi", nullptr);
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
    }
}

