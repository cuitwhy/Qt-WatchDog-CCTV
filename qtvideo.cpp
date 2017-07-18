#include "qtvideo.h"

QtVideo::QtVideo()
{
    QList<QCameraInfo>cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo cameraInfo, cameras)
    {
        m_vCameraNames.push_back(cameraInfo);
    }
}

QtVideo::~QtVideo()
{
    ;
}

bool QtVideo::openCamera(QString)
{
    return false;
}

