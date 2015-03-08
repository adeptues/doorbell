#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QDebug>
#include <QVariant>
#include <memory>

#include "serialthread.h"
Q_DECLARE_METATYPE(QSerialPortInfo)
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendBtn_clicked();

    void on_connectBtn_clicked();

public slots:
    void onMessageRecieved(const QString text);

private:
    Ui::MainWindow *ui;
    QList<QSerialPortInfo> serialInfo();
    std::unique_ptr<SerialThread> workerThread;
    void connectSignalSlots();
};

#endif // MAINWINDOW_H
