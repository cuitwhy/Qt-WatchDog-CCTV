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
    delete mediaRecorder1;
    delete camera2;
    delete viewfinder2;
    delete mediaRecorder2;
    delete camera3;
    delete viewfinder3;
    delete mediaRecorder3;
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
            camera1->setCaptureMode(QCamera::CaptureVideo);
            camera1->setViewfinder(viewfinder1);
            camera1->start();
            mediaRecorder1 = new QMediaRecorder(camera1);
            QAudioEncoderSettings audioSettings;
            audioSettings.setCodec("audio/amr");
            audioSettings.setQuality(QMultimedia::HighQuality);
            mediaRecorder1->setAudioSettings(audioSettings);
            QString fileName = "test.mp4";
            mediaRecorder1->setOutputLocation(QUrl::fromLocalFile(fileName));
            mediaRecorder1->record();
            ui->openButton1->setText(tr("Close_Cam_1"));
        }
    }
    else
    {
        camera1->stop();
        mediaRecorder1->stop();
        delete camera1;
        delete viewfinder1;
        delete mediaRecorder1;
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
            mediaRecorder2 = new QMediaRecorder(camera2);
            mediaRecorder2->setOutputLocation(QUrl("/cam2"));
            mediaRecorder2->record();
            ui->videoView2->addWidget(viewfinder2);
            camera2->setViewfinder(viewfinder2);
            camera2->start();
            ui->openButton2->setText(tr("Close_Cam_2"));
        }
    }
    else
    {
        camera2->stop();
        mediaRecorder2->stop();
        delete camera2;
        delete viewfinder2;
        delete mediaRecorder3;
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
            mediaRecorder3 = new QMediaRecorder(camera3);
            mediaRecorder3->setOutputLocation(QUrl("/cam3"));
            mediaRecorder3->record();
            ui->videoView3->addWidget(viewfinder3);
            camera3->setViewfinder(viewfinder3);
            camera3->start();
            ui->openButton3->setText(tr("Close_Cam_3"));
        }
    }
    else
    {
        camera3->stop();
        mediaRecorder3->stop();
        delete camera3;
        delete viewfinder3;
        delete mediaRecorder3;
        ui->openButton3->setText(tr("Open_Cam_3"));
    }
}
