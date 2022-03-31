#include "widget.h"
#include "ui_widget.h"
#include "QGraphicsDropShadowEffect"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QCryptographicHash>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    testFunction();
    //去掉系统边框
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置子窗口阴影
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);

    shadow-> setBlurRadius(10);
    shadow-> setColor(Qt::black);
    shadow-> setOffset(0);

    ui->shadowWidget->setGraphicsEffect(shadow);


    //设置父窗口透明模式
    this->setAttribute(Qt::WA_TranslucentBackground);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    QPoint y = event->globalPos();
    QPoint x = y-this->z;
    this->move(x);

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    QPoint y = event->globalPos();
    QPoint x = this->geometry().topLeft();
    z = y-x;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    //    this->z = QPoint();
}

QStringList Widget::getfiles(const QString &path)
{
    QStringList ret;
    QDir dir(path);
    QFileInfoList infolist = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Files|QDir::Dirs);

    for(int i = 0; i<infolist.count(); i++)
    {
        QFileInfo info = infolist.at(i);
        if(info.isDir())
        {
            QString subDir = info.absoluteFilePath();
            //如果目录存在，就启用getfile，传入目录，参数
            QStringList files = getfiles(subDir);

            ret.append(files);
        }
        else
        {
            QString fileName = info.absoluteFilePath();
            ret.append(fileName);
        }
    }


    return ret;
}

QString Widget::getFiles(const QString &path)
{

}

QByteArray Widget::getFileMd5(const QString &fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {

        //文件较大时，内存不一定够用，可以使用这种方法
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd()){
            QByteArray content = file.read(100*1024*1024);
            hash.addData(content);

        }
        QByteArray md5 = hash.result();

        return md5;

        file.close();
    }
    else
    {
        perror("文件打开错误： ");
        return QByteArray();
    }
}



//关闭
void Widget::on_btnClose_clicked()
{
    this->close();
}
//最大化
void Widget::on_btnMax_clicked()
{
    if(this->isMaximized())
    {
        ui->viMargin->setMargin(9);
        this->showNormal();
    }
    else
    {
        ui->viMargin->setMargin(0);
        this->showMaximized();
    }
}
//最小化
void Widget::on_btnMin_clicked()
{
    this->showMinimized();
}

void Widget::on_pushButton_clicked()
{
    QFile file("C:/Users/14165/Desktop/日常资料/TCP.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        //文件较小时可以使用这段代码
//        QByteArray content = file.readAll();
//        QMessageBox::information(this,"TCP",content);
//       QByteArray md5 = QCryptographicHash::hash(content,QCryptographicHash::Md5);

        //文件较大时，内存不一定够用，可以使用这种方法
        QCryptographicHash hash(QCryptographicHash::Md5);
        while(!file.atEnd()){
            QByteArray content = file.read(100*1024*1024);
            hash.addData(content);

        }
        QByteArray md5 = hash.result();

        qDebug()<<md5.toHex();

        file.close();
    }
    else
    {
      qDebug()<<"file is not opened";
    }
}





void Widget::on_pushButton_2_clicked()
{
    QStringList files = this->getfiles("C:/Users/14165/Desktop/qtCode/shareLib");
    for(int i=0; i<files.count(); i++)
    {
        QByteArray md5 = getFileMd5(files.at(i));
        qDebug()<<md5.toHex();

    }

    qDebug()<<files;
}
