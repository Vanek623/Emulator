#include "Neuro.h"

Neuro::Neuro(const int _inputsCount)
{
    inputsCount = _inputsCount;

    weights = new float[inputsCount];
    inputs = new float[inputsCount];
    output = 0;

    for(int i=0; i<inputsCount; i++)
    {
        weights[i] = 0.1f;
        inputs[i] = 0;
    }

}

Neuro::~Neuro()
{
    delete[] weights;
    delete[] inputs;
}

void Neuro::setWeight(const int inputNum, const float weight)
{
    if(inputNum < inputsCount)
    {
        weights[inputNum] = weight;
    }
}

float Neuro::getWeight(const int inputNum) const
{
    if(inputNum < inputsCount)
    {
        return weights[inputNum];
    }
    else
    {
        return 0;
    }
}

void Neuro::setInput(const int inputNum, const float input)
{
    if(inputNum < inputsCount)
    {
        inputs[inputNum] = input;
    }
}

void Neuro::setInputs(const float *_inputs)
{
    for(int i=0; i<inputsCount; i++)
    {
        inputs[i] = _inputs[i];
    }
}

float Neuro::getOutput() const
{
    float result = 0;
    for(int i=0; i<inputsCount; i++)
    {
        result += weights[i]*inputs[i];
    }

    if(result >= 0) return 1;
    else return -1;
}
