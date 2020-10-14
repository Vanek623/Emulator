#pragma once

#include <QWidget>
#include <QtWidgets>
#include <QPainter>
#include <QVector>
#include <QDebug>

class NumInput : public QWidget
{
    Q_OBJECT
private:
    int **pushed;

    const int width = 3;
    const int height = 5;

    float *neuroData;

public:
    NumInput();
    ~NumInput();

    float *getPushed() const;

protected:
    void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    void setupUI();
    void updateNum(const int x, const int y);

    void drawGrid();
    void drawCells();
};
