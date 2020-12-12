#ifndef DIALOGOFF_H
#define DIALOGOFF_H

#include <QDialog>
#include <QString>

namespace Ui {
class DialogOFF;
}

class DialogOFF : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOFF(QWidget *parent = nullptr);
    ~DialogOFF();
    QString getNameOFF();

private:
    Ui::DialogOFF *ui;
};

#endif // DIALOGOFF_H
