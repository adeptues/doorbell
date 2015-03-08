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

void MainWindow::on_sendBtn_clicked()
{

}

void MainWindow::on_connectBtn_clicked()
{

}
