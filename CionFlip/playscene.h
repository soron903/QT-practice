#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <dataconfig.h>
#include <mycoin.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    int levelIndex;//记录关卡

    //初始化游戏场景
    void paintEvent(QPaintEvent *);

public:
    dataConfig config;
    MyCoin * coinArr[4][4];
    bool isWin;

signals:
    void chooseSecneBack();
};

#endif // PLAYSCENE_H
