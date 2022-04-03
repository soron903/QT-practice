#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPoint"
#include "QMouseEvent"
#include "sharelib.h"

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

    QStringList getfiles(const QString &path);


    QString getFiles(const QString &path);
    QByteArray getFileMd5(const QString &fileName);
private:
    QPoint z;


private slots:
    void on_btnClose_clicked();

    void on_btnMax_clicked();

    void on_btnMin_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
