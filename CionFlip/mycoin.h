#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);

    //重写构造参数，传入金币路径
    MyCoin(QString);

    //金币的属性
    int posX;
    int posY;
    bool flag;//正反提示

    //改变标志的方法
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    int min = 1;
    int max = 8;

    //重写鼠标事件，在赢得关卡时，锁定关卡页面
    void mousePressEvent(QMouseEvent *e);

    //设定锁定关卡条件
    bool isWin = false;


signals:

};

#endif // MYCOIN_H
