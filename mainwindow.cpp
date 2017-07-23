#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach(QCameraInfo cameraName, video->m_vCameraNames)
    {
        ui->DebugtextBrowser->append(cameraName.deviceName());
    }
}

MainWindow::~MainWindow()
{
    delete video;
    delete camera1;
    delete viewfinder1;
    delete ui;
}

void MainWindow::on_openButton1_clicked()
{
    if (ui->openButton1->text() == "Open_Cam_1")
    {
        if (video->m_vCameraNames.size() > 0)
        {
            camera1 = new QCamera(video->m_vCameraNames[0]);
            viewfinder1 = new QCameraViewfinder();
            ui->videoView1->addWidget(viewfinder1);
            camera1->setViewfinder(viewfinder1);
            camera1->start();
            ui->openButton1->setText(tr("Close_Cam_1"));
        }
    }
    else
    {
        camera1->stop();
        delete camera1;
        delete viewfinder1;
        ui->openButton1->setText(tr("Open_Cam_1"));
    }
}

void MainWindow::on_openButton2_clicked()
{

}

void MainWindow::on_openButton3_clicked()
{

}
