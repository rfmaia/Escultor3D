#include "color.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Color::Color(QWidget *parent) : QWidget(parent){
    r = 0;
    g = 0;
    b = 0;
    a = 255;
}

void Color::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(r, g, b, a));
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);
    painter.drawRect(0, 0, width(), height());
}

void Color::setRed(int _r){
    r = _r;
    repaint();
}

void Color::setGreen(int _g){
    g = _g;
    repaint();
}

void Color::setBlue(int _b){
    b = _b;
    repaint();
}

void Color::setAlpha(int _a){
    a = _a;
    repaint();
}
