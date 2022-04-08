#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    //重写构造函数
    MyPushButton(QString normalImg,QString pressImg = "");

    //成员属性
    QString normalImgPath;
    QString pressImgPath;

    //设置弹跳特效

    //向下跳
    void zoom1();

    //向上跳
    void zoom2();

    //重写按钮的按下和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H
