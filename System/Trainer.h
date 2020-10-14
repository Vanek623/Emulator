#pragma once

//#define DEBUG_MODE

#include "consts.h"

#include "Neuro.h"
#include <cmath>
#include <QDebug>

const int INPUT_SIZE = 15;

class Trainer
{

private:
    const static int inputSize = 15;
    const float trainSpeed = 0.5f;
    const float errMax = 0.0001;

    Neuro *neuro;
    float **dataSet;
    float *targets;
    int dataSetSize = 10;

public:
    Trainer();
    ~Trainer();

    void setNeuro(Neuro *_neuro);
    void setDataSet(const int _dataSetSize, float **_dataSet);
    void setImage(const float values[], const float target);
    void setTargets(const float *_targets);

    void train();

private:
    void correct(const float inputs[], const float target);
    void clearDataSet();
    void clearTargets();
};
