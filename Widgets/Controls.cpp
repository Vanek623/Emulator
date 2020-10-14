#include "Controls.h"

Controls::Controls()
{
    setupUI();
}

void Controls::setRecognized(QString sim)
{
    recognizedVal->setText(sim);
}

int Controls::getTrainedValue()
{
    const QRegExp errSims("\\D");
    int input = trainField->text().remove(errSims).toInt();

    if(input >= 0 && input <= 9) return input;
    return -1;
}

void Controls::setupUI()
{
    QVBoxLayout *vLayout = new QVBoxLayout();

    QHBoxLayout *trainLayout = new QHBoxLayout();
    trainField = new QLineEdit();
    trainLayout->addWidget(trainField);

    QPushButton *mTrainBtn = new QPushButton("Тренировать");
    connect(mTrainBtn, SIGNAL(clicked()), this, SIGNAL(mTrain()));
    trainLayout->addWidget(mTrainBtn);

    QPushButton *aTrainBtn = new QPushButton("Авто тренировка");
    connect(aTrainBtn, SIGNAL(clicked()), this, SIGNAL(aTrain()));
    trainLayout->addWidget(aTrainBtn);

    QHBoxLayout *recLayout = new QHBoxLayout();
    recognizedVal = new QLabel("-");
    recognizedVal->setFont(QFont("Times", 20));
    recognizedVal->setStyleSheet("border 1px solid;");
    recLayout->addWidget(recognizedVal);

    QPushButton *recBtn = new QPushButton("Распознать");
    connect(recBtn, SIGNAL(clicked()), this, SIGNAL(recognize()));
    recLayout->addWidget(recBtn);

    vLayout->addItem(trainLayout);
    vLayout->addItem(recLayout);

    setLayout(vLayout);
}
