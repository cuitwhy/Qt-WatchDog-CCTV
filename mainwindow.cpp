#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (string &cameraname, video->m_vCameraNames)
    {
        ui->DebugtextBrowser->append(cameraname);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
