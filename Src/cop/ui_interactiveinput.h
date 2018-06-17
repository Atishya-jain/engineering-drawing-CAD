/********************************************************************************
** Form generated from reading UI file 'interactiveinput.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIVEINPUT_H
#define UI_INTERACTIVEINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_InteractiveInput
{
public:
    QLabel *label;
    QTextEdit *p1x;
    QTextEdit *p1y;
    QTextEdit *p1z;
    QTextEdit *p1label;
    QTextEdit *p2label;
    QTextEdit *p2x;
    QTextEdit *p2y;
    QTextEdit *p2z;
    QPushButton *draw;
    QPushButton *erase;
    QPushButton *Done;

    void setupUi(QDialog *InteractiveInput)
    {
        if (InteractiveInput->objectName().isEmpty())
            InteractiveInput->setObjectName(QString::fromUtf8("InteractiveInput"));
        InteractiveInput->resize(788, 699);
        label = new QLabel(InteractiveInput);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 561, 451));
        p1x = new QTextEdit(InteractiveInput);
        p1x->setObjectName(QString::fromUtf8("p1x"));
        p1x->setGeometry(QRect(40, 530, 41, 41));
        p1y = new QTextEdit(InteractiveInput);
        p1y->setObjectName(QString::fromUtf8("p1y"));
        p1y->setGeometry(QRect(100, 530, 41, 41));
        p1z = new QTextEdit(InteractiveInput);
        p1z->setObjectName(QString::fromUtf8("p1z"));
        p1z->setGeometry(QRect(160, 530, 41, 41));
        p1label = new QTextEdit(InteractiveInput);
        p1label->setObjectName(QString::fromUtf8("p1label"));
        p1label->setGeometry(QRect(40, 580, 161, 41));
        p2label = new QTextEdit(InteractiveInput);
        p2label->setObjectName(QString::fromUtf8("p2label"));
        p2label->setGeometry(QRect(230, 580, 161, 41));
        p2x = new QTextEdit(InteractiveInput);
        p2x->setObjectName(QString::fromUtf8("p2x"));
        p2x->setGeometry(QRect(230, 530, 41, 41));
        p2y = new QTextEdit(InteractiveInput);
        p2y->setObjectName(QString::fromUtf8("p2y"));
        p2y->setGeometry(QRect(290, 530, 41, 41));
        p2z = new QTextEdit(InteractiveInput);
        p2z->setObjectName(QString::fromUtf8("p2z"));
        p2z->setGeometry(QRect(350, 530, 41, 41));
        draw = new QPushButton(InteractiveInput);
        draw->setObjectName(QString::fromUtf8("draw"));
        draw->setGeometry(QRect(400, 530, 86, 36));
        erase = new QPushButton(InteractiveInput);
        erase->setObjectName(QString::fromUtf8("erase"));
        erase->setGeometry(QRect(400, 580, 86, 36));
        Done = new QPushButton(InteractiveInput);
        Done->setObjectName(QString::fromUtf8("Done"));
        Done->setGeometry(QRect(520, 530, 86, 36));

        retranslateUi(InteractiveInput);

        QMetaObject::connectSlotsByName(InteractiveInput);
    } // setupUi

    void retranslateUi(QDialog *InteractiveInput)
    {
        InteractiveInput->setWindowTitle(QApplication::translate("InteractiveInput", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InteractiveInput", "TextLabel", 0, QApplication::UnicodeUTF8));
        draw->setText(QApplication::translate("InteractiveInput", "draw", 0, QApplication::UnicodeUTF8));
        erase->setText(QApplication::translate("InteractiveInput", "erase", 0, QApplication::UnicodeUTF8));
        Done->setText(QApplication::translate("InteractiveInput", "Done", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InteractiveInput: public Ui_InteractiveInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIVEINPUT_H
