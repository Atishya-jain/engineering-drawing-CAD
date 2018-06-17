/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *buttonPlane;
    QLabel *isometric;
    QLabel *planeProj;
    QTextEdit *Ax;
    QTextEdit *By;
    QTextEdit *Cz;
    QTextEdit *Dd;
    QLabel *orthographic;
    QPushButton *buttonUP;
    QPushButton *buttonDOWN;
    QPushButton *buttonLEFT;
    QPushButton *buttonRIGHT;
    QPushButton *buttonZplus;
    QPushButton *buttonZminus;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2504, 1154);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        buttonPlane = new QPushButton(centralWidget);
        buttonPlane->setObjectName(QStringLiteral("buttonPlane"));
        buttonPlane->setGeometry(QRect(320, 400, 121, 31));
        isometric = new QLabel(centralWidget);
        isometric->setObjectName(QStringLiteral("isometric"));
        isometric->setGeometry(QRect(460, 80, 491, 351));
        planeProj = new QLabel(centralWidget);
        planeProj->setObjectName(QStringLiteral("planeProj"));
        planeProj->setGeometry(QRect(40, 30, 321, 361));
        Ax = new QTextEdit(centralWidget);
        Ax->setObjectName(QStringLiteral("Ax"));
        Ax->setGeometry(QRect(30, 400, 41, 31));
        By = new QTextEdit(centralWidget);
        By->setObjectName(QStringLiteral("By"));
        By->setGeometry(QRect(100, 400, 41, 31));
        Cz = new QTextEdit(centralWidget);
        Cz->setObjectName(QStringLiteral("Cz"));
        Cz->setGeometry(QRect(160, 400, 41, 31));
        Dd = new QTextEdit(centralWidget);
        Dd->setObjectName(QStringLiteral("Dd"));
        Dd->setGeometry(QRect(220, 400, 41, 31));
        orthographic = new QLabel(centralWidget);
        orthographic->setObjectName(QStringLiteral("orthographic"));
        orthographic->setGeometry(QRect(1010, 70, 661, 631));
        buttonUP = new QPushButton(centralWidget);
        buttonUP->setObjectName(QStringLiteral("buttonUP"));
        buttonUP->setGeometry(QRect(1090, 20, 41, 41));
        buttonDOWN = new QPushButton(centralWidget);
        buttonDOWN->setObjectName(QStringLiteral("buttonDOWN"));
        buttonDOWN->setGeometry(QRect(1070, 720, 41, 41));
        buttonLEFT = new QPushButton(centralWidget);
        buttonLEFT->setObjectName(QStringLiteral("buttonLEFT"));
        buttonLEFT->setGeometry(QRect(405, 235, 41, 41));
        buttonRIGHT = new QPushButton(centralWidget);
        buttonRIGHT->setObjectName(QStringLiteral("buttonRIGHT"));
        buttonRIGHT->setGeometry(QRect(1700, 290, 41, 41));
        buttonZplus = new QPushButton(centralWidget);
        buttonZplus->setObjectName(QStringLiteral("buttonZplus"));
        buttonZplus->setGeometry(QRect(1235, 30, 41, 36));
        buttonZminus = new QPushButton(centralWidget);
        buttonZminus->setObjectName(QStringLiteral("buttonZminus"));
        buttonZminus->setGeometry(QRect(1280, 30, 41, 36));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 2504, 33));
        MainWindow->setMenuBar(menuBar);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonPlane->setText(QApplication::translate("MainWindow", "Get Projection", nullptr));
        isometric->setText(QApplication::translate("MainWindow", "isometric", nullptr));
        planeProj->setText(QApplication::translate("MainWindow", "plane projection", nullptr));
        orthographic->setText(QApplication::translate("MainWindow", "orthographic", nullptr));
        buttonUP->setText(QApplication::translate("MainWindow", "up", nullptr));
        buttonDOWN->setText(QApplication::translate("MainWindow", "down", nullptr));
        buttonLEFT->setText(QApplication::translate("MainWindow", "left", nullptr));
        buttonRIGHT->setText(QApplication::translate("MainWindow", "right", nullptr));
        buttonZplus->setText(QApplication::translate("MainWindow", "Z+", nullptr));
        buttonZminus->setText(QApplication::translate("MainWindow", "Z-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
