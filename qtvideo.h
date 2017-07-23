/**************************
 *Class Video
 *By:Why
 *2017.07.15
 *************************/
#ifndef QTVIDEO_H
#define QTVIDEO_H

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QVideoWidget>
#include <QFileDialog>

#include <QList>
#include <vector>
#include <string>

using namespace std;

class QtVideo
{
public:
    QtVideo();
    ~QtVideo();

    std::vector<QCameraInfo> m_vCameraNames;
    bool openCamera(QString);

};

#endif // QTVIDEO_H
