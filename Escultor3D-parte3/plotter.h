#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "sculptor.h"

class Plotter : public QWidget
{
    Q_OBJECT
private:
    Sculptor *grid;
    bool gridIsOn;
    int r, g, b, a;
    int dimX, dimY, dimZ;
    int radius;
    int rx, ry, rz;
    int x1, y1, z1;
    int sizeRectX, sizeRectY;
    int mouseX, mouseY, mouseXRelease, mouseYRelease;
    int menu;
    int axisZ;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setMenu(int num);
    void putVoxel();
    void cutVoxel();
    void putBox(int x1, int y1, int z1);
    void cutBox(int x1, int y1, int z1);
    void putSphere(int _radius);
    void cutSphere(int _radius);
    void putEllipsoid(int rx, int ry, int rz);
    void cutEllipsoid(int rx, int ry, int rz);
    void writeOFF(string name);
signals:
public slots:
    void setRed(int _r);
    void setGreen(int _g);
    void setBlue(int _b);
    void setAlpha(int _a);
    void setAxisZ(int _axisZ);
    void setGridSize(int _dimX,int _dimY,int _dimZ);
    void setRadius(int _radius);
    void setRX(int _rx);
    void setRY(int _ry);
    void setRZ(int _rz);
    void setX1(int _x1);
    void setY1(int _y1);
    void setZ1(int _z1);
};

#endif // PLOTTER_H
