#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void abreDim(void);
    void abreSaveOFF(void);
    void putVoxel(void);
    void cutVoxel(void);
    void putBox(void);
    void cutBox(void);
    void putSphere(void);
    void cutSphere(void);
    void putEllipsoid(void);
    void cutEllipsoid(void);
    void fechar(void);

private:
    Ui::MainWindow *ui;
    int dimX, dimY, dimZ;
};
#endif // MAINWINDOW_H
