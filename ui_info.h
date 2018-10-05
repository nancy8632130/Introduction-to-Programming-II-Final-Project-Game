/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:
    QPushButton *pushButton;
    QWidget *widget;

    void setupUi(QWidget *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName(QStringLiteral("info"));
        info->resize(800, 600);
        info->setStyleSheet(QStringLiteral("border-image: url(:/Image/menubg.jpg);"));
        pushButton = new QPushButton(info);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 220, 211, 200));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/Image/pink.png);\n"
"font: 87 22pt \"Segoe UI Black\";"));
        widget = new QWidget(info);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 130, 501, 361));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/Image/info.png);"));

        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QWidget *info)
    {
        info->setWindowTitle(QApplication::translate("info", "Form", 0));
        pushButton->setText(QApplication::translate("info", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
