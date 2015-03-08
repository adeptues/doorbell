#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QSerialPortInfo> ports = serialInfo();

    for(QSerialPortInfo port: ports){
        ui->portBox->addItem(port.portName(),QVariant::fromValue(port));
    }
    // get data back this->ui->combobox->itemData(x).value<MyClass*>();


    connectSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QList<QSerialPortInfo> MainWindow::serialInfo(){
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    qDebug() << "There are " << ports.length() << "Serial ports";
    for(int i = 0; i < ports.length(); i++){
        QSerialPortInfo port = ports[i];
        qDebug() << "Port " << i << "port name: " << port.portName();
    }
    return ports;

}

void MainWindow::connectSignalSlots(){
    //Signal slot connections go here
}

void MainWindow::on_sendBtn_clicked()
{
    //TODO send message here to serial
}

void MainWindow::on_connectBtn_clicked()
{
    int index = ui->portBox->currentIndex();
    int baudRate = 9600;
    QSerialPortInfo info = ui->portBox->itemData(index).value<QSerialPortInfo>();
    //SET worker thread

    //TODO acquire serial connection here
}

void MainWindow::onMessageRecieved(const QString text){
    qDebug() << "Received message text from serial: " << text;
    ui->textArea->append(text);

}
