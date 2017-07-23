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
    delete camera2;
    delete viewfinder2;
    delete camera3;
    delete viewfinder3;
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
    if (ui->openButton2->text() == "Open_Cam_2")
    {
        if (video->m_vCameraNames.size() > 1)
        {
            camera2 = new QCamera(video->m_vCameraNames[1]);
            viewfinder2 = new QCameraViewfinder();
            ui->videoView2->addWidget(viewfinder2);
            camera2->setViewfinder(viewfinder2);
            camera2->start();
            ui->openButton2->setText(tr("Close_Cam_2"));
        }
    }
    else
    {
        camera2->stop();
        delete camera2;
        delete viewfinder2;
        ui->openButton2->setText(tr("Open_Cam_2"));
    }
}

void MainWindow::on_openButton3_clicked()
{
    if (ui->openButton3->text() == "Open_Cam_3")
    {
        if (video->m_vCameraNames.size() > 2)
        {
            camera3 = new QCamera(video->m_vCameraNames[2]);
            viewfinder3 = new QCameraViewfinder();
            ui->videoView3->addWidget(viewfinder3);
            camera3->setViewfinder(viewfinder3);
            camera3->start();
            ui->openButton3->setText(tr("Close_Cam_3"));
        }
    }
    else
    {
        camera3->stop();
        delete camera3;
        delete viewfinder3;
        ui->openButton3->setText(tr("Open_Cam_3"));
    }
}
