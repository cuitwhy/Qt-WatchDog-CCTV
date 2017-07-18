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

private slots:
    void on_openButton1_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
