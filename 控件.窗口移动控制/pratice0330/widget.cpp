#include "widget.h"
#include "ui_widget.h"
#include "QGraphicsDropShadowEffect"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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

