#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QDataStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    imageIndex = 0;
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
    clients.append(socket);

    //连接信号和槽
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));
}

void Widget::onReadyRead()
{
    QObject* obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    qint64 sizeNow = 0;
    do
    {
        sizeNow = socket->bytesAvailable();
        if(sizeNow<sizeof(quint32))
        {
            return;
        }
        QDataStream stream(socket);
        quint32 sizePack = 0;
        stream>>sizePack;

        //包不完整，等待完整，在执行下面语句
        if(sizeNow < sizePack - 4)
        {
            return;
        }

        qDebug()<<"full pack";
        QByteArray dataFull;
        stream>>dataFull;

        //判断剩下的字节数，是否会有粘包的情况
        sizeNow = socket->bytesAvailable();

        QString prefix = dataFull.mid(0,4);
        qDebug()<<prefix;
        if(prefix == "TXT:")
        {
            QString textContent = dataFull.mid(4);
            ui->textMsg->append(textContent);
        }
        else if(prefix == "IMG:")
        {
            QString htmlTag = "<img src=\"%1\"></img>";
            QString index = QString::number(imageIndex);
            htmlTag = htmlTag.arg(index+".png");

            QFile file(index+".png");
            file.open(QIODevice::WriteOnly);
            file.write(dataFull.mid(4));
            file.close();

            index=index+1;
            ui->textMsg->insertHtml(htmlTag);
        }
    }while(sizeNow>0);

}

void Widget::onConnected()
{
    qDebug()<<"connect";
}

void Widget::onDisconnected()
{
    QObject*obj = this->sender();
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(obj);
    clients.removeAll(socket);
    socket->deleteLater();
    qDebug()<<"disconnect";
}

void Widget::onError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"error:"<<socketError;
}


void Widget::on_pushButton_clicked()
{
    for(QList<QTcpSocket*>::iterator itr = clients.begin();itr != clients.end();itr++)
    {
        QTcpSocket*client = *itr;
        QString msgInput = "TXT:" + ui->textEdit_input->toPlainText();

        QByteArray dataSend;//分装数据包
        QDataStream stream(&dataSend,QIODevice::WriteOnly);
        stream<<(quint32)0<<msgInput.toLocal8Bit();
        stream.device()->seek(0);
        stream<<dataSend.size();

        client->write(dataSend);
    }
}

void Widget::on_pushButton_2_clicked()
{
    QString image = QFileDialog::getOpenFileName(this,"title",".","Images (*.png *.xpm *.jpg)");
    if(image.isEmpty())
    {
        return;
    }
    QFile file(image);
    file.readAll();
    file.open(QIODevice::ReadOnly);
    QByteArray data ="IMG:"+ file.readAll();
    file.close();

    QByteArray dataSend;//分装数据包
    QDataStream stream(&dataSend,QIODevice::WriteOnly);
    stream<<(quint32)0<<data;
    stream.device()->seek(0);
    stream<<dataSend.size();

    for(QList<QTcpSocket*>::iterator itr=clients.begin(); itr!=clients.end();itr++)
    {
        QTcpSocket*client = *itr;


        client->write(dataSend);
    }
}


