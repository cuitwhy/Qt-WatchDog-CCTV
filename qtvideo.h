/**************************
 *Class Video
 *By:Why
 *2017.07.15
 *************************/
#ifndef QTVIDEO_H
#define QTVIDEO_H

#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVideoWidget>
#include <QFileDialog>

#include <vector>
#include <string>

using namespace std;

class QtVideo
{
public:
    QtVideo();
    ~QtVideo();

    std::vector<string> m_vCameraNames;



};

#endif // QTVIDEO_H
