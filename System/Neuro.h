#pragma once

class Neuro{
private:
    float *weights;
    float *inputs;
    float output;

    int inputsCount;

public:
    Neuro(const int _inputsCount);
    ~Neuro();

    void setWeight(const int inputNum, const float weight);
    float getWeight(const int inputNum) const;

    void setInput(const int inputNum, const float input);
    void setInputs(const float *_inputs);

    float getOutput() const;

private:


};
