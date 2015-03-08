#include "serialthread.h"

SerialThread::SerialThread(QSerialPortInfo serialPortInfo,int baudRate)
{
    serialPort.setPort(serialPortInfo);
    serialPort.setBaudRate(baudRate);


}

SerialThread::~SerialThread()
{

}

void SerialThread::run(){
    //TODO finish off background thread for recieving data
}

