/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *pushButton;
    QTableView *tableWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(800, 600);
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 560, 75, 23));
        tableWidget = new QTableView(MyWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 10, 561, 321));
        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(100, 560, 75, 23));
        pushButton_3 = new QPushButton(MyWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 560, 75, 23));
        label = new QLabel(MyWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 370, 53, 15));
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 400, 53, 15));
        label_3 = new QLabel(MyWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 430, 53, 15));
        label_4 = new QLabel(MyWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 460, 53, 15));
        lineEdit = new QLineEdit(MyWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 370, 341, 21));
        lineEdit_2 = new QLineEdit(MyWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 400, 341, 21));
        lineEdit_3 = new QLineEdit(MyWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 430, 341, 21));
        lineEdit_4 = new QLineEdit(MyWidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(90, 460, 341, 21));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("MyWidget", "\345\214\257\345\205\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MyWidget", "\345\214\257\345\207\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MyWidget", "\346\226\260\345\242\236", nullptr));
        label->setText(QCoreApplication::translate("MyWidget", "\345\255\270\350\231\237:", nullptr));
        label_2->setText(QCoreApplication::translate("MyWidget", "\347\217\255\347\264\232:", nullptr));
        label_3->setText(QCoreApplication::translate("MyWidget", "\345\247\223\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("MyWidget", "\351\233\273\350\251\261:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
