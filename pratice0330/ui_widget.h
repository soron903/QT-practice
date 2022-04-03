/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *viMargin;
    QWidget *shadowWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnMin;
    QPushButton *btnMax;
    QPushButton *btnClose;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QListWidget *listWidgetMd5;
    QListWidget *listWidgetDuplicate;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(649, 456);
        viMargin = new QVBoxLayout(Widget);
        viMargin->setSpacing(6);
        viMargin->setObjectName(QString::fromUtf8("viMargin"));
        shadowWidget = new QWidget(Widget);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setStyleSheet(QString::fromUtf8("#shadowWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"border-radius:5px\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(shadowWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(shadowWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        btnMin = new QPushButton(shadowWidget);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setMinimumSize(QSize(42, 42));
        btnMin->setMaximumSize(QSize(42, 42));
        btnMin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"\n"
"}\n"
"QPushButton:hover{background-color: rgb(232, 235, 232)}\n"
"\n"
"\n"
"QPushButton:pressed{background-color: rgb(255, 255, 255);}\n"
""));

        horizontalLayout->addWidget(btnMin);

        btnMax = new QPushButton(shadowWidget);
        btnMax->setObjectName(QString::fromUtf8("btnMax"));
        btnMax->setMinimumSize(QSize(42, 42));
        btnMax->setMaximumSize(QSize(42, 42));
        btnMax->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"\n"
"}\n"
"QPushButton:hover{background-color: rgb(232, 235, 232)}\n"
"\n"
"\n"
"QPushButton:pressed{background-color: rgb(255, 255, 255);}\n"
""));

        horizontalLayout->addWidget(btnMax);

        btnClose = new QPushButton(shadowWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(42, 42));
        btnClose->setMaximumSize(QSize(42, 42));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"background-color:rgb(231,63,33);\n"
"border-top-right-radius:5px\n"
"}\n"
"QPushButton:hover{background-color: rgb(255, 146, 56)}\n"
"\n"
"\n"
"QPushButton:pressed{background-color: rgb(255, 187, 175);}\n"
""));

        horizontalLayout->addWidget(btnClose);


        verticalLayout_2->addLayout(horizontalLayout);

        frame = new QFrame(shadowWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 330, 93, 28));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(440, 20, 93, 28));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 330, 451, 23));
        progressBar->setValue(0);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 20, 401, 21));
        listWidgetMd5 = new QListWidget(frame);
        new QListWidgetItem(listWidgetMd5);
        listWidgetMd5->setObjectName(QString::fromUtf8("listWidgetMd5"));
        listWidgetMd5->setGeometry(QRect(30, 80, 256, 192));
        listWidgetDuplicate = new QListWidget(frame);
        listWidgetDuplicate->setObjectName(QString::fromUtf8("listWidgetDuplicate"));
        listWidgetDuplicate->setGeometry(QRect(310, 80, 256, 192));

        verticalLayout_2->addWidget(frame);


        viMargin->addWidget(shadowWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "frameless Window", nullptr));
        btnMin->setText(QString());
        btnMax->setText(QString());
        btnClose->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "openfile", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "getfiles", nullptr));

        const bool __sortingEnabled = listWidgetMd5->isSortingEnabled();
        listWidgetMd5->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetMd5->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        listWidgetMd5->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
