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
    QHBoxLayout *horizontalLayout_5;
    QWidget *shadowWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnMin;
    QPushButton *btnMax;
    QPushButton *btnClose;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidgetMd5;
    QListWidget *listWidgetDuplicate;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(649, 456);
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
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
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
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
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        listWidgetMd5 = new QListWidget(frame);
        listWidgetMd5->setObjectName(QString::fromUtf8("listWidgetMd5"));

        horizontalLayout_4->addWidget(listWidgetMd5);

        listWidgetDuplicate = new QListWidget(frame);
        listWidgetDuplicate->setObjectName(QString::fromUtf8("listWidgetDuplicate"));

        horizontalLayout_4->addWidget(listWidgetDuplicate);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_6->addWidget(lineEdit);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_6);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addWidget(frame);


        horizontalLayout_5->addWidget(shadowWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "MD5", nullptr));
        btnMin->setText(QString());
        btnMax->setText(QString());
        btnClose->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "\351\207\215\345\244\215\346\226\207\344\273\266\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\351\207\215\345\244\215\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "getfiles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
