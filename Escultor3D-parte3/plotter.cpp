#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <cmath>
#include <vector>
#include <string>
#include "sculptor.h"
#include "mainwindow.h"

using namespace std;

Plotter::Plotter(QWidget *parent) : QWidget(parent){
    gridIsOn = false;
    r = 0;
    g = 0;
    b = 0;
    a = 255;
    dimX = 1;
    dimY = 1;
    dimZ = 1;
    axisZ = 0;
    menu = 1;
    radius = 0;
    rx = 0;
    ry = 0;
    rz = 0;
    x1 = 0;
    y1 = 0;
    z1 = 0;
}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255, 255, 255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(1);

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());

    sizeRectY = height()/dimY;
    sizeRectX = width()/dimX;

    if(gridIsOn){
    for(int i = 0; i < dimX; i++){
        for(int j = 0; j < dimY; j++){
            brush.setColor(QColor(255, 255, 255));
            painter.setBrush(brush);
            if(grid->isOn(i, j, axisZ)){
                vector<int> rgba = grid->getColor(i, j, axisZ);
                brush.setColor(QColor(rgba[0], rgba[1], rgba[2], rgba[3]));
                painter.setBrush(brush);
                painter.drawRect(sizeRectX*i, sizeRectY*j, sizeRectX,sizeRectY);
            }else{
                painter.drawRect(sizeRectX*i, sizeRectY*j, sizeRectX,sizeRectY);
            }
        }
    }
    }else{
        brush.setColor(QColor(255,255,255));
        painter.setBrush(brush);
        painter.drawRect(0,0,width(),height());
    }
}

void Plotter::mousePressEvent(QMouseEvent *event){
    mouseX = event->x()/sizeRectX;
    mouseY = event->y()/sizeRectY;
    switch (menu) {
    case 1:
        putVoxel();
        break;
    case 2:
        cutVoxel();
        break;
    default:
        break;
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event){
    mouseXRelease = event->x()/sizeRectX;
    mouseYRelease = event->y()/sizeRectY;
    switch (menu) {
    case 3:
        putBox(mouseXRelease, mouseYRelease, axisZ+z1);
        break;
    case 4:
        cutBox(mouseXRelease, mouseYRelease, axisZ+z1);
        break;
    case 5:
        putSphere(radius);
        break;
    case 6:
        cutSphere(radius);
        break;
    case 7:
        putEllipsoid(rx, ry, rz);
        break;
    case 8:
        cutEllipsoid(rx, ry, rz);
        break;
    default:
        break;
    }
}

void Plotter::setMenu(int num){
    menu = num;
    repaint();
}

void Plotter::setGridSize(int _dimX, int _dimY, int _dimZ){
    dimX = _dimX;
    dimY = _dimY;
    dimZ = _dimZ;
    grid = new Sculptor(dimX, dimY, dimZ);
    gridIsOn = true;
    repaint();
}

void Plotter::setRadius(int _radius){
    radius = _radius;
    repaint();
}

void Plotter::setRX(int _rx){
    rx = _rx;
    repaint();
}

void Plotter::setRY(int _ry){
    ry = _ry;
    repaint();
}

void Plotter::setRZ(int _rz){
    rz = _rz;
    repaint();
}

void Plotter::setX1(int _x1){
    x1 = _x1;
    repaint();
}

void Plotter::setY1(int _y1){
    y1 = _y1;
    repaint();
}

void Plotter::setZ1(int _z1){
    z1 = _z1;
    repaint();
}

void Plotter::putVoxel(){
    grid->setColor(r, g, b, a);
    grid->putVoxel(mouseX, mouseY, axisZ);
    repaint();
}

void Plotter::cutVoxel(){
    grid->cutVoxel(mouseX, mouseY, axisZ);
    repaint();
}

void Plotter::putBox(int x1, int y1, int z1){
    grid->setColor(r, g, b, a);
    grid->putBox(mouseX, x1, mouseY, y1, axisZ, z1);
    repaint();
}

void Plotter::cutBox(int x1, int y1, int z1){
    grid->cutBox(mouseX, x1, mouseY, y1, axisZ, z1);
    repaint();
}

void Plotter::putSphere(int _radius){
    grid->setColor(r, g, b, a);
    grid->putSphere(mouseX, mouseY, axisZ, _radius);
    repaint();
}

void Plotter::cutSphere(int _radius){
    grid->cutSphere(mouseX, mouseY, axisZ, _radius);
    repaint();
}

void Plotter::putEllipsoid(int rx, int ry, int rz){
    grid->setColor(r, g, b, a);
    grid->putEllipsoid(mouseX, mouseY, axisZ, rx, ry, rz);
    repaint();
}

void Plotter::cutEllipsoid(int rx, int ry, int rz){
    grid->cutEllipsoid(mouseX, mouseY, axisZ, rx, ry, rz);
    repaint();
}

void Plotter::writeOFF(string name){
    grid->writeOFF(name + ".off");
}

void Plotter::setRed(int _r){
    r = _r;
    repaint();
}

void Plotter::setGreen(int _g){
    g = _g;
    repaint();
}

void Plotter::setBlue(int _b){
    b = _b;
    repaint();
}

void Plotter::setAlpha(int _a){
    a = _a;
    repaint();
}

void Plotter::setAxisZ(int _axisZ){
    axisZ = _axisZ;
    repaint();
}
