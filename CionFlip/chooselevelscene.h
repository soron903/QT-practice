#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H
#include <playscene.h>
#include <QMainWindow>
#include <QPaintEvent>
#include <dataconfig.h>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *event);

    PlayScene * play = nullptr;



signals:

    void chooseMainSecneBack();
};

#endif // CHOOSELEVELSCENE_H
