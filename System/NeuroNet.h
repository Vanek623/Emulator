#pragma once

#include <QVector>
#include <QDebug>

#include "Neuro.h"
#include "Trainer.h"
#include "consts.h"

class NeuroNet{

private:
    QVector<Neuro*> *layer;
    Trainer *trainer;

    const int neuroCount = 10;
    const int inputsCount = 15;

public:
    NeuroNet();
    ~NeuroNet();

    void autoTrain();
    void manualTrain(const float values[], const int target);
    int getRecognized() const;

    void work(const float values[]);

    float **createDataSet();
    void restoreDataSet(float **dataSet);

};
