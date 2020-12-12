#include "dialogoff.h"
#include "ui_dialogoff.h"

DialogOFF::DialogOFF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOFF)
{
    ui->setupUi(this);
}

DialogOFF::~DialogOFF()
{
    delete ui;
}

QString DialogOFF::getNameOFF(){
    return ui->lineEditOFF->text();
}
