/********************************************************************************
** Form generated from reading UI file 'movie.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIE_H
#define UI_MOVIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_movie
{
public:

    void setupUi(QWidget *movie)
    {
        if (movie->objectName().isEmpty())
            movie->setObjectName(QStringLiteral("movie"));
        movie->resize(800, 600);

        retranslateUi(movie);

        QMetaObject::connectSlotsByName(movie);
    } // setupUi

    void retranslateUi(QWidget *movie)
    {
        movie->setWindowTitle(QApplication::translate("movie", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class movie: public Ui_movie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIE_H
