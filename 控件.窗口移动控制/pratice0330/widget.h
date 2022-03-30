#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPoint"
#include "QMouseEvent"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    QPoint z;


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
