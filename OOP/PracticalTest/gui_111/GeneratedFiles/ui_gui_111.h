/********************************************************************************
** Form generated from reading UI file 'gui_111.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_111_H
#define UI_GUI_111_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui_111Class
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *gui_111Class)
    {
        if (gui_111Class->objectName().isEmpty())
            gui_111Class->setObjectName(QStringLiteral("gui_111Class"));
        gui_111Class->resize(600, 400);
        verticalLayoutWidget = new QWidget(gui_111Class);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 28, 451, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_3);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButton_2);


        verticalLayout->addLayout(formLayout);


        retranslateUi(gui_111Class);

        QMetaObject::connectSlotsByName(gui_111Class);
    } // setupUi

    void retranslateUi(QWidget *gui_111Class)
    {
        gui_111Class->setWindowTitle(QApplication::translate("gui_111Class", "gui_111", 0));
        label->setText(QApplication::translate("gui_111Class", "Total Reviwed", 0));
        label_2->setText(QApplication::translate("gui_111Class", "nrReviewed", 0));
        label_3->setText(QApplication::translate("gui_111Class", "Name", 0));
        pushButton->setText(QApplication::translate("gui_111Class", "Add", 0));
        pushButton_2->setText(QApplication::translate("gui_111Class", "Revise", 0));
    } // retranslateUi

};

namespace Ui {
    class gui_111Class: public Ui_gui_111Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_111_H
