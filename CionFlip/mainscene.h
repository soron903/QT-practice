#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <mypushbutton.h>
#include <QDebug>
#include <chooselevelscene.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);

    //画图事件设置背景
    void paintEvent(QPaintEvent *);



    ~MainScene();

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
