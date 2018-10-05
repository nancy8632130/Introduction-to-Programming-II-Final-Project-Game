/********************************************************************************
** Form generated from reading UI file 'media.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIA_H
#define UI_MEDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_media
{
public:

    void setupUi(QWidget *media)
    {
        if (media->objectName().isEmpty())
            media->setObjectName(QStringLiteral("media"));
        media->resize(800, 600);

        retranslateUi(media);

        QMetaObject::connectSlotsByName(media);
    } // setupUi

    void retranslateUi(QWidget *media)
    {
        media->setWindowTitle(QApplication::translate("media", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class media: public Ui_media {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIA_H
