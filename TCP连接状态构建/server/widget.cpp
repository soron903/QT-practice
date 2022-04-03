#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&server,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    bool ok = server.listen(QHostAddress::AnyIPv4,8888);
    qDebug()<<"listen:"<<ok;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onNewConnection()
{
    QTcpSocket *socket = server.nextPendingConnection();

    //连接信号和槽
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
}

void Widget::onReadyRead()
{
    QObject*obj = this->sender();
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

