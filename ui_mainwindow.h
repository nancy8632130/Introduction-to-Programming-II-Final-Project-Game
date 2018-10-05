/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_info;
    QPushButton *pushButton_1;
    QPushButton *pushButton_start;
    QPushButton *pushButton_5;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QStringLiteral("border-image: url(:/Image/menubg.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 110, 100, 100));
        pushButton_2->setStyleSheet(QLatin1String("border-image: url(:/Image/yellow.png);\n"
"font: 75 9pt \"Segoe Print\";\n"
""));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 380, 101, 81));
        pushButton_4->setStyleSheet(QLatin1String("border-image: url(:/Image/blue.png);\n"
"font: 75 9pt \"Segoe Print\";"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 260, 91, 81));
        pushButton_3->setStyleSheet(QLatin1String("border-image: url(:/Image/green.png);\n"
"font: 75 9pt \"Segoe Print\";"));
        pushButton_info = new QPushButton(centralWidget);
        pushButton_info->setObjectName(QStringLiteral("pushButton_info"));
        pushButton_info->setGeometry(QRect(140, 250, 101, 101));
        pushButton_info->setStyleSheet(QLatin1String("border-image: url(:/Image/pink.png);\n"
"font: 75 26pt \"Impact\";"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(340, 50, 101, 101));
        pushButton_1->setStyleSheet(QLatin1String("border-image: url(:/Image/orange.png);\n"
"font: 75 9pt \"Segoe Print\";"));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(290, 210, 191, 171));
        pushButton_start->setStyleSheet(QLatin1String("border-image: url(:/Image/red.png);\n"
"font: 87 22pt \"Segoe UI Black\";"));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 430, 101, 91));
        pushButton_5->setStyleSheet(QLatin1String("border-image: url(:/Image/purple.png);\n"
"font: 75 9pt \"Segoe Print\";"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "level 2", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "level 4", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "level 3", 0));
        pushButton_info->setText(QApplication::translate("MainWindow", "?", 0));
        pushButton_1->setText(QApplication::translate("MainWindow", "level 1", 0));
        pushButton_start->setText(QApplication::translate("MainWindow", " start", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "level 5", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
