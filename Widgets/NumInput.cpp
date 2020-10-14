#include "NumInput.h"

NumInput::NumInput()
{
    setupUI();
    neuroData = new float[width*height];
}

NumInput::~NumInput()
{
    for(int i=0;i<width; i++)
    {
        delete[] pushed[i];
    }

    delete[] pushed;
    delete[] neuroData;
}

float *NumInput::getPushed() const
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            neuroData[j+i*width] = static_cast<float>(pushed[j][i]);
        }
    }

    return neuroData;
}

void NumInput::paintEvent(QPaintEvent *)
{
    drawGrid();
    drawCells();
}

void NumInput::mousePressEvent(QMouseEvent *event)
{
    updateNum(event->x(), event->y());

    //qDebug() << event->x() << ", " << event->y();
}

void NumInput::setupUI()
{
    pushed = new int *[width];

    for(int i=0; i<width; i++)
    {
        pushed[i] = new int [height];

        for(int j=0; j<height; j++){
            pushed[i][j] = -1;
        }
    }
}

void NumInput::updateNum(const int x, const int y)
{
    int row = y*height / this->size().height();
    int col = x*width / this->size().width();

    if(pushed[col][row] < 0)
    {
        pushed[col][row] = 1;
    }
    else
    {
        pushed[col][row] = -1;
    }

    this->repaint();
}

void NumInput::drawGrid()
{
    QPainter painter;

    painter.begin(this);

    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    painter.setPen(QPen(Qt::NoPen));
    painter.drawRect(0, 0, size().width(), size().height());

    painter.setPen(QPen(Qt::gray, 2, Qt::SolidLine));
    for(int i=0; i<=width; i++)
    {
        int x1 = i*this->size().width()/width;
        painter.drawLine(x1, 0, x1, this->size().height());
    }

    for(int i=0; i<=height; i++)
    {
        int y1 = i*this->size().height()/height;
        painter.drawLine(0, y1, this->size().width(), y1);
    }
}

void NumInput::drawCells()
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(QPen(Qt::NoPen));

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            int h = size().height() / height;
            int w = size().width() / width;

            if(pushed[i][j] > 0)
            {
                painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
                painter.drawRect(i*w, j*h, w, h);
            }
        }
    }
}


