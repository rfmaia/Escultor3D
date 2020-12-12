#include "dialogdim.h"
#include "ui_dialogdim.h"

DialogDim::DialogDim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDim)
{
    ui->setupUi(this);
}

DialogDim::~DialogDim()
{
    delete ui;
}

int DialogDim::getDimX(){
    return ui->lineEditDimX->text().toInt();
}

int DialogDim::getDimY(){
    return ui->lineEditDimY->text().toInt();
}

int DialogDim::getDimZ(){
    return ui->lineEditDimZ->text().toInt();
}
