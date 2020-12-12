#ifndef DIALOGDIM_H
#define DIALOGDIM_H

#include <QDialog>

namespace Ui {
class DialogDim;
}

class DialogDim : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDim(QWidget *parent = nullptr);
    ~DialogDim();
    int getDimX();
    int getDimY();
    int getDimZ();

private:
    Ui::DialogDim *ui;
};

#endif // DIALOGDIM_H
