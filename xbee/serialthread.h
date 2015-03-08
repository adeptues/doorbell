#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>
class SerialThread: public QThread
{
    Q_OBJECT
public:
    SerialThread(QSerialPortInfo serialPortInfo,int baudRate);
    ~SerialThread();
    //Work method simialr to java threads run
    void run() Q_DECL_OVERRIDE;

private:
    QSerialPort serialPort;

signals:
    //emit when message recieved
    void dataReceived(const QString text);
};

#endif // SERIALTHREAD_H
