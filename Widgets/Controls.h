#ifndef CONTROLS_H
#define CONTROLS_H

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegExp>

class Controls : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *trainField;
    QLabel *recognizedVal;

public:
    Controls();
    void setRecognized(QString sim);
    int getTrainedValue();

signals:
    void mTrain();  //ручная тренировка
    void aTrain();  //автоматическая тренировка
    void recognize();

private:
    void setupUI();
};

#endif // CONTROLS_H
