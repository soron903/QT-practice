#include "mainscene.h"
#include "ui_mainscene.h"
#include <QMenu>
#include <QPainter>
#include <QTimer>
#include <chooselevelscene.h>
#include <QSound>
#include <QTime>


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(400,588);
    //设置图标
    setWindowIcon(QIcon(":/resource/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币主场景");

    //退出功能实现
    connect(ui->actionq,&QAction::triggered,[=]()
    {
        this->close();
    });

    //设置音效
    QSound *startSound = new QSound(":/resource/TapButtonSound.wav",this);

    //设置自定义开始按钮
    MyPushButton* startBtn = new MyPushButton(":/resource/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    //创建关卡场景
    ChooseLevelScene* levelScene = new ChooseLevelScene;

    //连接自定义信号chooseMainSceneBack，返回主场景的信号
    connect(levelScene,&ChooseLevelScene::chooseMainSecneBack,[=]()
    {
        //
        this->setGeometry(levelScene->geometry());
        levelScene->hide();
        this->show();

    });
    //建立连接关系
    connect(startBtn,&MyPushButton::clicked,[=](){

        startSound->play();
//        qDebug()<<"test mypushbutton";
        startBtn->zoom1();
        startBtn->zoom2();


        //进入到选择关卡场景
        QTimer::singleShot(200,this,[=](){

            //设置levelscene场景位置
            levelScene->setGeometry(this->geometry());

            //自身隐藏
            this->hide();
            //显示选择关卡场景
            levelScene->show();
        });

    });

}

//画图事件设置背景
void MainScene::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pic;
    pic.load(":/resource/PlayLevelSceneBg.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pic);

    //设置背景图标
    pic.load(":/resource/Title.png");
    pic = pic.scaled(pic.width()*0.5,pic.height()*0.5);
    painter.drawPixmap(10,30,pic);



}

MainScene::~MainScene()
{
    delete ui;
}

