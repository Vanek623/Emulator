#pragma once

#include <QLabel>
#include <QObject>
#include <QTextEdit>
#include <QToolBar>
#include <QAction>
#include <QMainWindow>
#include <QHBoxLayout>

#include "consts.h"

#include "NumInput.h"
#include "Controls.h"

#include "Neuronet.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Controls *controls;
    NumInput *numInput;

    NeuroNet *net;

public:
    explicit MainWindow();
    ~MainWindow();

private slots:
    void aTrain();
    void mTrain();
    void recognize();

private:
    void setupUI();
    void setupNeuroNet();
};
