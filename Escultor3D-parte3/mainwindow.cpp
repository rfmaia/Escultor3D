#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogdim.h"
#include "dialogoff.h"
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    dimX = 1;
    dimY = 1;
    dimZ = 1;

    ui->horizontalSliderRed->setMaximum(255);
    ui->horizontalSliderGreen->setMaximum(255);
    ui->horizontalSliderBlue->setMaximum(255);
    ui->horizontalSliderAlpha->setMaximum(255);
    ui->horizontalSliderRed->setMinimum(0);
    ui->horizontalSliderGreen->setMinimum(0);
    ui->horizontalSliderBlue->setMinimum(0);
    ui->horizontalSliderAlpha->setMinimum(0);
    ui->horizontalSliderRed->setSliderPosition(0);
    ui->horizontalSliderGreen->setSliderPosition(0);
    ui->horizontalSliderBlue->setSliderPosition(0);
    ui->horizontalSliderAlpha->setSliderPosition(255);

    connect(ui->actionAbreDim,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abreDim()));

    connect(ui->actionAbreSaveOFF,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abreSaveOFF()));

    connect(ui->actionPutVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(putVoxel()));

    connect(ui->actionCutVoxel,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cutVoxel()));

    connect(ui->actionPutBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(putBox()));

    connect(ui->actionCutBox,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cutBox()));

    connect(ui->actionPutSphere,
            SIGNAL(triggered(bool)),
            this,
            SLOT(putSphere()));

    connect(ui->actionCutSphere,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cutSphere()));

    connect(ui->actionPutEllipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(putEllipsoid()));

    connect(ui->actionCutEllipsoid,
            SIGNAL(triggered(bool)),
            this,
            SLOT(cutEllipsoid()));

    connect(ui->actionExit,
            SIGNAL(triggered(bool)),
            this,
            SLOT(fechar()));

    // rgba no widgetColor
    connect(ui->horizontalSliderRed,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(setRed(int)));

    connect(ui->horizontalSliderGreen,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(setGreen(int)));

    connect(ui->horizontalSliderBlue,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(setBlue(int)));

    connect(ui->horizontalSliderAlpha,
            SIGNAL(valueChanged(int)),
            ui->widgetColor,
            SLOT(setAlpha(int)));

    // rgba no widgetPlotter
    connect(ui->horizontalSliderRed,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setRed(int)));

    connect(ui->horizontalSliderGreen,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setGreen(int)));

    connect(ui->horizontalSliderBlue,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setBlue(int)));

    connect(ui->horizontalSliderAlpha,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setAlpha(int)));

    // Mudar Eixo Z
    connect(ui->horizontalSliderAxisZ,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setAxisZ(int)));

    // Mudar Raio - esfera
    connect(ui->horizontalSliderSphereRadius,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setRadius(int)));

    // Mudar Raios - elipsoid
    connect(ui->horizontalSliderRX,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setRX(int)));

    connect(ui->horizontalSliderRY,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setRY(int)));

    connect(ui->horizontalSliderRZ,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setRZ(int)));

    // mudar x1, y1 e z1 - Caixa
    connect(ui->horizontalSliderZBox,
            SIGNAL(valueChanged(int)),
            ui->widgetPlotter,
            SLOT(setZ1(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abreDim(){
    DialogDim d;
    d.exec();
    dimX = d.getDimX();
    dimY = d.getDimY();
    dimZ = d.getDimZ();

    ui->horizontalSliderAxisZ->setMaximum(dimZ-1);

    ui->horizontalSliderZBox->setMaximum(dimZ-1);

    ui->horizontalSliderRX->setMaximum(dimX-1);
    ui->horizontalSliderRY->setMaximum(dimY-1);
    ui->horizontalSliderRZ->setMaximum(dimZ-1);

    ui->widgetPlotter->setGridSize(dimX, dimY, dimZ);
}

void MainWindow::abreSaveOFF(){
    DialogOFF save;
    save.exec();
    string nome = save.getNameOFF().toStdString();

    ui->widgetPlotter->writeOFF(nome);
}

void MainWindow::putVoxel(){
    ui->widgetPlotter->setMenu(1);
}

void MainWindow::cutVoxel(){
    ui->widgetPlotter->setMenu(2);
}

void MainWindow::putBox(){
    ui->widgetPlotter->setMenu(3);
}

void MainWindow::cutBox(){
    ui->widgetPlotter->setMenu(4);
}

void MainWindow::putSphere(){
    ui->widgetPlotter->setMenu(5);
}

void MainWindow::cutSphere(){
    ui->widgetPlotter->setMenu(6);
}

void MainWindow::putEllipsoid(){
    ui->widgetPlotter->setMenu(7);
}

void MainWindow::cutEllipsoid(){
    ui->widgetPlotter->setMenu(8);
}

void MainWindow::fechar(){
    exit(0);
}

