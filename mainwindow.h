#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtvideo.h>
#include <string>

using namespace std;

class QtVideo;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QtVideo *video = new QtVideo();
    QCamera *camera1;
    QCameraViewfinder *viewfinder1;
    QMediaRecorder *mediaRecorder1;
    QCamera *camera2;
    QCameraViewfinder *viewfinder2;
    QMediaRecorder *mediaRecorder2;
    QCamera *camera3;
    QCameraViewfinder *viewfinder3;
    QMediaRecorder *mediaRecorder3;


private slots:
    void on_openButton1_clicked();

    void on_openButton2_clicked();

    void on_openButton3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
