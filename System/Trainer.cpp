#include "Trainer.h"

Trainer::Trainer()
{
    dataSet = nullptr;
    targets = nullptr;
}

Trainer::~Trainer()
{
    clearDataSet();
    clearTargets();
}

void Trainer::setNeuro(Neuro *_neuro)
{
    neuro = _neuro;
}

void Trainer::setDataSet(const int _dataSetSize, float **_dataSet)
{
    clearDataSet();

    dataSetSize = _dataSetSize;

    dataSet = _dataSet;
}

void Trainer::setImage(const float values[], const float target)
{
    clearDataSet();
    clearTargets();

    dataSetSize = 1;

    dataSet = new float * [dataSetSize];
    dataSet[0] = new float[inputSize];

    for(int i=0; i<inputSize; i++)
    {
        dataSet[0][i] = values[i];
    }

    targets = new float[dataSetSize];
    targets[0] = target;
}

void Trainer::setTargets(const float *_targets)
{
    clearTargets();

    targets = new float[dataSetSize];

    for(int i=0; i<dataSetSize; i++)
    {
        targets[i] = _targets[i];
    }
}

void Trainer::train()
{
    bool isErr;
    int iterations = 0;
    do
    {
        isErr = false;
        for(int i=0; i<dataSetSize; i++)    //проход по датасету и корректировка в случае необходимости
        {
            neuro->setInputs(dataSet[i]);

            if( !(fabsf(neuro->getOutput() - targets[i]) < errMax) )
            {
                correct(dataSet[i], targets[i]);
                isErr = true;
            }
        }

        iterations++;
    }
    while (isErr); // обучение до тех пор, пока сеть не обучится
    qDebug() << "Neuro was training within " << iterations << "iterations.";
}

void Trainer::correct(const float inputs[], const float target)
{
    float out = neuro->getOutput();
#ifdef DEBUG_MODE
    qDebug() << "Target is" << target << ", OUT is" << neuro->getOutput();
#endif
    for(int i=0; i<inputSize; i++)  //проход по входам и изменение весов
    {
        if(TRAIN_MODE == Hab)
            neuro->setWeight(i, neuro->getWeight(i) + inputs[i]*target*trainSpeed);
        else if(TRAIN_MODE == Delta)
            neuro->setWeight(i, neuro->getWeight(i) + (target - out)*inputs[i]*trainSpeed);
    }
}

void Trainer::clearDataSet()
{
    if(dataSet != nullptr)
    {
        for(int i=0; i<dataSetSize; i++)
        {
            delete[] dataSet[i];
        }
        delete[] dataSet;
        dataSet = nullptr;
    }
}

void Trainer::clearTargets()
{
    if(targets != nullptr)
    {
        delete[] targets;
        targets = nullptr;
    }
}



