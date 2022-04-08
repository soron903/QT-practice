#include "playscene.h"
#include <QString>
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <mycoin.h>
#include <dataconfig.h>
#include <QPropertyAnimation>
#include <QSound>


//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum)
{
    QString str = QString("进入了第 %1 关").arg(levelNum);
    qDebug()<<str;
    this->levelIndex=levelNum;

    //初始化游戏场景

    //设置固定大小
    setFixedSize(400,588);
    //设置图标
    setWindowIcon(QIcon(":/resource/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币场景");


    //创建菜单栏
    QMenuBar*bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu*startMenu = bar->addMenu("开始");
    //创建退出菜单项
    QAction *quitAction = startMenu->addAction("退出");
    //点击退出，实现游戏退出
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });


    //设置翻转金币音效
    QSound *filpSoud = new QSound(":/resource/ConFlipSound.wav",this);
    //设置胜利音效
    QSound *winSound = new QSound(":/resource/LevelWinSound.wav",this);
    //设置返回按钮音效
    QSound *backSound = new QSound(":/resource/BackButtonSound.wav",this);


    //创建返回按钮
    MyPushButton * backButton = new MyPushButton(":/resource/BackButton.png",":/resource/BackButtonSelected.png");
    backButton->setParent(this);
    backButton->move(this->width()-backButton->width(),this->height()-backButton->height());

    connect(backButton,&MyPushButton::clicked,[=](){
        backSound->play();
//        qDebug()<<"playscene test backbutton";

        //激发自定义信号
        QTimer::singleShot(100,[=](){
            emit this->chooseSecneBack();
        });

    });

    //创建关卡提示框
    QLabel *levelLabel = new QLabel(this);
    QString str1 = QString("LEVEL %1").arg(levelNum);
    levelLabel->setText(str1);
    levelLabel->setFixedSize(backButton->width()*2,backButton->height()*2);
    levelLabel->move(0,this->height()-levelLabel->height());

    QFont fon;
    fon.setFamily("华文新魏");
    fon.setPointSize(20);
    levelLabel->setFont(fon);

    //创建胜利提示
    QLabel *winLabel = new QLabel(this);
    QPixmap winPix;
    winPix.load(":/resource/LevelCompletedDialogBg.png");
    winLabel->setFixedSize(winPix.width(),winPix.height());
    winLabel->setPixmap(winPix);
    winLabel->move((this->width()-winLabel->width())*0.5,-this->height()*0.5);


    //a.创建金币数据（dataconfig.h）
    QString str2;



    //显示翻金币背景图片
    for(int i=0; i<16; i++)
    {
        QLabel *label = new QLabel(this);
        QPixmap pix;
        pix.load(":/resource/BoardNode.png");

        label->setGeometry(0,0,pix.width(),pix.height());
        label->setPixmap(pix);
        label->move(i%4*pix.width()+98,i/4*pix.height()+200);


        //引用a注释的下的内容，创建关卡金币布局
        if(config.mData[levelNum][i%4][i/4]==1)
        {
            str2 = QString(":/resource/Coin0001.png");
        }
        else
        {
            str2 = QString(":/resource/Coin0008.png");
        }
         //创建金币
        MyCoin *coin = new MyCoin(str2);
        coin->setParent(this);
        coin->move(i%4*pix.width()+100,i/4*pix.height()+203);


        coin->posX = i%4;
        coin->posY = i/4;
        coin->flag = config.mData[levelNum][i%4][i/4];

        //数组维护每一关卡的所有金币
        coinArr[i%4][i/4] = coin;



        //点击金币进行翻转
        connect(coin,&MyCoin::clicked,[=](){
            coin->changeFlag();
            filpSoud->play();
            config.mData[levelNum][i%4][i/4] = config.mData[levelNum][i%4][i/4]==0?1:0;

            //延迟反转
            QTimer::singleShot(100,this,[=](){
                //上翻
                if(coin->posY-1>=0)
                {
                    coinArr[coin->posX][coin->posY-1]->changeFlag();
                    config.mData[levelNum][coin->posX][coin->posY-1] = config.mData[levelNum][coin->posX][coin->posY-1]==0?1:0;

                }

                //下翻

                if(coin->posY+1<=3)
                {
                    coinArr[coin->posX][coin->posY+1]->changeFlag();
                    config.mData[levelNum][coin->posX][coin->posY+1] = config.mData[levelNum][coin->posX][coin->posY+1]==0?1:0;

                }

                //左翻
                if(coin->posX-1>=0)
                {
                    coinArr[coin->posX-1][coin->posY]->changeFlag();
                    config.mData[levelNum][coin->posX-1][coin->posY] = config.mData[levelNum][coin->posX-1][coin->posY]==0?1:0;

                }

                //右翻
                if(coin->posX+1<=3)
                {
                    coinArr[coin->posX+1][coin->posY]->changeFlag();
                    config.mData[levelNum][coin->posX+1][coin->posY] = config.mData[levelNum][coin->posX+1][coin->posY]==0?1:0;

                }

                //判断是否成功完成关卡
                this->isWin = true;
                for(int i = 0; i<4; i++)
                {
                    for(int j = 0; j<4; j++)
                    {
                        if(config.mData[levelNum][i][j] == false)
                        {
                            this->isWin = false;
                        }
                    }
                }

                if(this->isWin == true)
                {
                    qDebug()<<"you win";
                    for(int i = 0; i<4; i++)
                    {
                        for(int j = 0; j<4; j++)
                        {
                            coinArr[i][j]->isWin = true;
                        }
                    }

                    //弹出胜利提示框
                    //
                    winSound->play();
                    QPropertyAnimation* animation = new QPropertyAnimation(winLabel,"geometry");
                    //设置持续时间
                    animation->setDuration(2000);
                    //设置开始位置
                    animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                    //设置结束位置
                    animation->setEndValue(QRect(winLabel->x(),winLabel->y()+this->height()*0.6,winLabel->width(),winLabel->height()));
                    //设置动画曲线
                    animation->setEasingCurve(QEasingCurve::OutBounce);
                    //执行动画
                    animation->start();

                }


            });


        });


    }


}
void PlayScene::paintEvent(QPaintEvent *)
{

    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/resource/PlayLevelSceneBg.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/resource/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);



}



