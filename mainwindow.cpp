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
    delete ui;
}

void MainWindow::on_openButton1_clicked()
{
    if (ui->openButton1->text() == "Open_Cam_1")
    {
        if (video->m_vCameraNames.size())
        {
            QCamera *camera1 = new QCamera(video->m_vCameraNames[0]);
            QCameraViewfinder *viewfinder1 = new QCameraViewfinder();
            ui->videoView1->addWidget(viewfinder1);
            camera1->setViewfinder(viewfinder1);
            camera1->start();
            ui->openButton1->setText(tr("Close_Cam_1"));
        }
    }
    else
    {
        ;
    }
}
