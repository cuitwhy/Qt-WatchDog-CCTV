#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach(QString cameraName, video->m_vCameraNames)
    {
        ui->DebugtextBrowser->append(cameraName);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
