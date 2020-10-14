#include "NeuroNet.h"

NeuroNet::NeuroNet()
{
    layer = new QVector<Neuro*>();
    for(int i=0; i< neuroCount; i++)
    {
        layer->append(new Neuro(inputsCount));
    }

    trainer = new Trainer();
}

NeuroNet::~NeuroNet()
{
    QVector<Neuro*>::iterator it;
    for(it = layer->begin(); it != layer->end(); ++it)
    {
        delete *it;
    }

    delete layer;
    delete trainer;
}

void NeuroNet::autoTrain()
{
    float **dataSet = createDataSet();

    float targets[neuroCount];

    QVector<Neuro*>::iterator it;
    int n=0;
    for(it = layer->begin(); it != layer->end(); ++it)
    {
        qDebug() << "Train" << n << "neuro.";
        trainer->setNeuro(*it);
        trainer->setDataSet(neuroCount, dataSet);

        for(int i=0; i<neuroCount; i++)
        {
            if(n == i) targets[i] = 1;
            else targets[i] = -1;
        }

        trainer->setTargets(targets);
        trainer->train();

        n++;
    }

    restoreDataSet(dataSet);
}

void NeuroNet::manualTrain(const float values[], const int target)
{
    float targets[neuroCount];
    for(int i=0; i<neuroCount; i++)
    {
        if(target == i) targets[i] = 1;
        else targets[i] = -1;
    }

    QVector<Neuro*>::iterator it;
    int n = 0;
    for(it = layer->begin(); it != layer->end(); ++it)
    {
        qDebug() << "Train" << n << "neuro.";
        trainer->setNeuro(*it);
        trainer->setImage(values, targets[n]);
        trainer->train();

        n++;
    }
}

int NeuroNet::getRecognized() const
{
    int i = 0;
    QVector<Neuro*>::iterator it;
    for(it = layer->begin(); it != layer->end(); ++it)
    {
        if((*it)->getOutput() > 0) return i;
        i++;
    }

    return -1;
}

void NeuroNet::work(const float values[])
{
    int i = 0;
    QVector<Neuro*>::iterator it;
    for(it = layer->begin(); it != layer->end(); ++it)
    {
        (*it)->setInputs(values);
        qDebug() << i << ":" << (*it)->getOutput();
        i++;
    }
}

float **NeuroNet::createDataSet()
{
    float **dataSet;
    dataSet = new float*[neuroCount];

    if(TRAIN_MODE == Hab)
    {
        float tmp[][INPUT_SIZE] =
        {
            {
                1,1,1,
                1,-1,1,
                1,-1,1,//0
                1,-1,1,
                1,1,1
            },
            {
                -1,1,-1,
                1,1,-1,
                -1,1,-1,//1
                -1,1,-1,
                -1,1,-1
            },
            {
                1,1,1,
                -1,-1,1,
                1,1,1,  //2
                1,-1,-1,
                1,1,1
            },
            {
                1,1,1,
                -1,-1,1,
                1,1,1,  //3
                -1,-1,1,
                1,1,1
            },
            {
                1,-1,1,
                1,-1,1,
                1,1,1,  //4
                -1,-1,1,
                -1,-1,1
            },
            {
                1,1,1,
                1,-1,-1,
                1,1,1,
                -1,-1,1,//5
                1,1,1
            },
            {
                1,1,1,
                1,-1,-1,
                1,1,1,
                1,-1,1,//6
                1,1,1
            },
            {
                1,1,1,
                -1,-1,1,
                -1,1,-1,
                -1,1,-1,//7
                -1,1,-1
            },
            {
                1,1,1,
                1,-1,1,
                1,1,1,//8
                1,-1,1,
                1,1,1
            },
            {
                1,1,1,
                1,-1,1,
                1,1,1,//9
                -1,-1,1,
                1,1,1
            }
        };

        for(int i=0; i<neuroCount; i++)
        {
            dataSet[i] = new float[INPUT_SIZE];
            for(int j=0; j< INPUT_SIZE; j++)
            {
                dataSet[i][j] = tmp[i][j];
            }
        }
    }
    else
    {
        float tmp[][INPUT_SIZE] =
        {
            {
                -1,1,-1,
                1,-1,1,//A
                1,-1,1,
                1,1,1,
                1,-1,1
            },
            {
                1,1,1,
                1,-1,-1,
                1,1,-1,//Б
                1,-1,1,
                1,1,-1
            },
            {
                1,1,-1,
                1,-1,1,
                1,1,-1,//В
                1,-1,1,
                1,1,-1
            },
            {
                1,1,1,
                1,-1,-1,
                1,-1,-1,
                1,-1,-1,//Г
                1,-1,-1
            },
            {
                -1,1,-1,
                1,-1,1,
                1,1,1,//Д
                -1,1,-1,
                1,-1,1
            },
            {
                1,1,1,
                1,-1,-1,
                1,1,1,//Е
                1,-1,-1,
                1,1,1
            },
            {
                1,1,-1,
                -1,-1,1,
                1,1,-1,//З
                -1,-1,1,
                1,1,-1
            },
            {
                1,-1,1,
                1,-1,1,
                1,-1,1,//И
                1,-1,1,
                1,1,1
            },
            {
                1,-1,1,
                1,1,-1,
                1,-1,-1,//К
                1,1,-1,
                1,-1,1
            },
            {
                -1,1,-1,
                1,-1,1,
                1,-1,1,//Л
                1,-1,1,
                1,-1,1
            }
        };

        for(int i=0; i<neuroCount; i++)
        {
            dataSet[i] = new float[INPUT_SIZE];
            for(int j=0; j< INPUT_SIZE; j++)
            {
                dataSet[i][j] = tmp[i][j];
            }
        }
    }

    return dataSet;
}

void NeuroNet::restoreDataSet(float **dataSet)
{
    for(int i=0; i<neuroCount; i++)
    {
        delete[] dataSet[i];
    }

    delete[] dataSet;
}
