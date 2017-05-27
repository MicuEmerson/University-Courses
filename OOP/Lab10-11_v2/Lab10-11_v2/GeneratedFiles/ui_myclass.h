/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myClassClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myClassClass)
    {
        if (myClassClass->objectName().isEmpty())
            myClassClass->setObjectName(QStringLiteral("myClassClass"));
        myClassClass->resize(600, 400);
        menuBar = new QMenuBar(myClassClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        myClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myClassClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        myClassClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(myClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        myClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(myClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        myClassClass->setStatusBar(statusBar);

        retranslateUi(myClassClass);

        QMetaObject::connectSlotsByName(myClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *myClassClass)
    {
        myClassClass->setWindowTitle(QApplication::translate("myClassClass", "myClass", 0));
    } // retranslateUi

};

namespace Ui {
    class myClassClass: public Ui_myClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
