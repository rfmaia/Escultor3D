#ifndef COLOR_H
#define COLOR_H

#include <QWidget>

class Color : public QWidget
{
    Q_OBJECT
private:
    int r,g,b,a;
public:
    explicit Color(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void setRed(int _r);
    void setGreen(int _g);
    void setBlue(int _b);
    void setAlpha(int _a);
};

#endif // COLOR_H
