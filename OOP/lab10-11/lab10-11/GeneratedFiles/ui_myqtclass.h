/********************************************************************************
** Form generated from reading UI file 'myqtclass.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTCLASS_H
#define UI_MYQTCLASS_H

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

class Ui_myQtClassClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myQtClassClass)
    {
        if (myQtClassClass->objectName().isEmpty())
            myQtClassClass->setObjectName(QStringLiteral("myQtClassClass"));
        myQtClassClass->resize(600, 400);
        menuBar = new QMenuBar(myQtClassClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        myQtClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myQtClassClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        myQtClassClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(myQtClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        myQtClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(myQtClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        myQtClassClass->setStatusBar(statusBar);

        retranslateUi(myQtClassClass);

        QMetaObject::connectSlotsByName(myQtClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *myQtClassClass)
    {
        myQtClassClass->setWindowTitle(QApplication::translate("myQtClassClass", "myQtClass", 0));
    } // retranslateUi

};

namespace Ui {
    class myQtClassClass: public Ui_myQtClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTCLASS_H
