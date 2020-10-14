#include "MainWindow.h"

MainWindow::MainWindow()
{
    setupUI();
    setupNeuroNet();
}

MainWindow::~MainWindow()
{
    delete net;
}

void MainWindow::aTrain()
{
    net->autoTrain();
}

void MainWindow::mTrain()
{
    int val = controls->getTrainedValue();
    if(val >0)
    {
        net->manualTrain(numInput->getPushed(), static_cast<float>(val));
    }
}

void MainWindow::recognize()
{
    net->work(numInput->getPushed());
    if(TRAIN_MODE == Hab)
        controls->setRecognized(QString::number(net->getRecognized()));
    else if(TRAIN_MODE == Delta)
    {
        QStringList letters;

        letters.append(QString('-'));

        char letter = 'A';
        for(int i=0; i<10; i++)
        {
            letters.append(QString(letter));
            letter++;
            qDebug() << letter;
        }

        controls->setRecognized(letters.at(net->getRecognized() + 1));
    }
}

void MainWindow::setupUI(){
    setMinimumSize(800, 600);
    //setFixedSize(800,600);
    setWindowTitle("Neuro net 1.0");

    this->setCentralWidget(new QWidget());
    QHBoxLayout *layoutH = new QHBoxLayout();

    numInput = new NumInput();
    numInput->setMinimumWidth(400);
    layoutH->addWidget(numInput);
    //numInput->setSizePolicy(QSizePolicy::);

    controls = new Controls();
    controls->setMinimumWidth(400);
    layoutH->addWidget(controls);

    connect(controls, SIGNAL(aTrain()), this, SLOT(aTrain()));
    connect(controls, SIGNAL(mTrain()), this, SLOT(mTrain()));
    connect(controls, SIGNAL(recognize()), this, SLOT(recognize()));

    this->centralWidget()->setLayout(layoutH);
}

void MainWindow::setupNeuroNet()
{
    net = new NeuroNet();
}
