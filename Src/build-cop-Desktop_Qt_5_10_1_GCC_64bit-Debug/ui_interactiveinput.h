/********************************************************************************
** Form generated from reading UI file 'interactiveinput.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERACTIVEINPUT_H
#define UI_INTERACTIVEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

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
            InteractiveInput->setObjectName(QStringLiteral("InteractiveInput"));
        InteractiveInput->resize(788, 699);
        label = new QLabel(InteractiveInput);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 561, 451));
        p1x = new QTextEdit(InteractiveInput);
        p1x->setObjectName(QStringLiteral("p1x"));
        p1x->setGeometry(QRect(40, 530, 41, 41));
        p1y = new QTextEdit(InteractiveInput);
        p1y->setObjectName(QStringLiteral("p1y"));
        p1y->setGeometry(QRect(100, 530, 41, 41));
        p1z = new QTextEdit(InteractiveInput);
        p1z->setObjectName(QStringLiteral("p1z"));
        p1z->setGeometry(QRect(160, 530, 41, 41));
        p1label = new QTextEdit(InteractiveInput);
        p1label->setObjectName(QStringLiteral("p1label"));
        p1label->setGeometry(QRect(40, 580, 161, 41));
        p2label = new QTextEdit(InteractiveInput);
        p2label->setObjectName(QStringLiteral("p2label"));
        p2label->setGeometry(QRect(230, 580, 161, 41));
        p2x = new QTextEdit(InteractiveInput);
        p2x->setObjectName(QStringLiteral("p2x"));
        p2x->setGeometry(QRect(230, 530, 41, 41));
        p2y = new QTextEdit(InteractiveInput);
        p2y->setObjectName(QStringLiteral("p2y"));
        p2y->setGeometry(QRect(290, 530, 41, 41));
        p2z = new QTextEdit(InteractiveInput);
        p2z->setObjectName(QStringLiteral("p2z"));
        p2z->setGeometry(QRect(350, 530, 41, 41));
        draw = new QPushButton(InteractiveInput);
        draw->setObjectName(QStringLiteral("draw"));
        draw->setGeometry(QRect(400, 530, 86, 36));
        erase = new QPushButton(InteractiveInput);
        erase->setObjectName(QStringLiteral("erase"));
        erase->setGeometry(QRect(400, 580, 86, 36));
        Done = new QPushButton(InteractiveInput);
        Done->setObjectName(QStringLiteral("Done"));
        Done->setGeometry(QRect(520, 530, 86, 36));

        retranslateUi(InteractiveInput);

        QMetaObject::connectSlotsByName(InteractiveInput);
    } // setupUi

    void retranslateUi(QDialog *InteractiveInput)
    {
        InteractiveInput->setWindowTitle(QApplication::translate("InteractiveInput", "Dialog", nullptr));
        label->setText(QApplication::translate("InteractiveInput", "TextLabel", nullptr));
        draw->setText(QApplication::translate("InteractiveInput", "draw", nullptr));
        erase->setText(QApplication::translate("InteractiveInput", "erase", nullptr));
        Done->setText(QApplication::translate("InteractiveInput", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InteractiveInput: public Ui_InteractiveInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERACTIVEINPUT_H
