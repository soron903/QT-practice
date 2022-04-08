#include "mycoin.h"
#include <QDebug>

//MyCoin::MyCoin(QWidget *parent) : QPushButton (parent)
//{

//}

//重写构造参数，传入金币路径
MyCoin::MyCoin(QString IcoinImg)
{
    QPixmap pix;
    bool ret = pix.load(IcoinImg);
    assert(ret);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听正反面的信号，并且翻转金币
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/resource/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));


//        qDebug()<<min;
        if(this->min > this->max)
        {
            this->min=1;

            timer1->stop();

            this->flag = false;
        }
    });

    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/resource/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
//        qDebug()<<max+100;
        if(this->max < this->min){
            this->max=8;

            timer2->stop();
            this->flag=true;
        }
    });

}

//重写鼠标事件，在赢得关卡时，锁定关卡页面
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isWin == true)
    {
        return;
    }
    QPushButton::mousePressEvent(e);

}



//改变标志的方法
void MyCoin::changeFlag()
{
    //如果是正面，翻成反面
    if(this->flag)
    {
        timer1->start(30);


    }
    else
    {
        timer2->start(30);


    }

}
