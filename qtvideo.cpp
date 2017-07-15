#include "qtvideo.h"

QtVideo::QtVideo()
{
    QList<QCameraInfo>cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo cameraInfo, cameras)
    {
        m_vCameraNames.push_back(cameraInfo.deviceName());
    }
}

QtVideo::~QtVideo()
{
    ;
}

