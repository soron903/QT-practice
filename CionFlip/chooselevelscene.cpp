#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSound>


ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置固定大小
    setFixedSize(400,588);
    //设置图标
    setWindowIcon(QIcon(":/resource/Coin0001.png"));
    //设置标题
    setWindowTitle("选择关卡场景");


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


    //设置选择关卡按钮音效
    QSound *chooseBtnSound = new QSound(":/resource/TapButtonSound.wav",this);
    //设置返回按钮音效
    QSound *backSound = new QSound(":/resource/BackButtonSound.wav",this);


    //设置返回按钮
    MyPushButton * backButton = new MyPushButton(":/resource/BackButton.png",":/resource/BackButtonSelected.png");
    backButton->setParent(this);
    backButton->move(this->width()-backButton->width(),this->height()-backButton->height());

    connect(backButton,&MyPushButton::clicked,[=](){
//        qDebug()<<"test backbutton";


        backSound->play();
        //激发自定义信号
        QTimer::singleShot(100,[=](){
            emit this->chooseMainSecneBack();
        });

    });

//设置关卡按钮




    for(int i=0; i<20;i++)
    {
        MyPushButton *btn = new MyPushButton(":/resource/LevelIcon.png");
        btn->setParent(this);
        btn->move(i%4*btn->width()*1.5+45,i/4*btn->height()+180);

        //监听每个按钮
//        QString str = QString("第 %1 关").arg(i+1);
        connect(btn,&MyPushButton::clicked,[=](){
            chooseBtnSound->play();
//            qDebug()<<str;

            //进入游戏场景
            play = new PlayScene(i+1);
            //固定play场景位置
            play->setGeometry(this->geometry());
            this->hide();
            play->show();

            connect(play,&PlayScene::chooseSecneBack,[=](){
                //
                this->setGeometry(play->geometry());
                delete play;
                this->show();

                play = nullptr;
            });
        });

        QLabel *label = new QLabel;
        label->setFixedSize(btn->width(),btn->height());
        label->setParent(this);
        label->setText(QString::number(i+1));
        label->move(i%4*btn->width()*1.5+45,i/4*btn->height()+180);
//设置水平居中对齐
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


        //设置鼠标穿透事件
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

//重写绘图事件
void ChooseLevelScene::paintEvent(QPaintEvent *)
{

    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/resource/OtherSceneBg.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/resource/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);


}
