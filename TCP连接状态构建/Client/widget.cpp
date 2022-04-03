#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(&tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));

    tcpSocket.connectToHost("192.168.3.46",8888);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onReadyRead()
{
    QObject* obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    QByteArray data = socket->readAll();
    qDebug()<<data;
}

void Widget::onConnected()
{
    qDebug()<<"connect";
}

void Widget::onDisconnected()
{
    qDebug()<<"disconnect";
}

void Widget::onError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"error:"<<socketError;
}


void Widget::on_pushButton_clicked()
{

}
