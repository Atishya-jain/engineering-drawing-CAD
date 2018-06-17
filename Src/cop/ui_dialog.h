/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTextEdit *filename;
    QPushButton *pushButton;
    QPushButton *browse;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rad1_file;
    QRadioButton *rad2_inter;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rad3_3d;
    QRadioButton *rad4_2d;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(743, 504);
        filename = new QTextEdit(Dialog);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(70, 80, 431, 101));
        filename->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        filename->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 270, 86, 36));
        browse = new QPushButton(Dialog);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(510, 80, 86, 36));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 30, 224, 36));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rad1_file = new QRadioButton(widget);
        rad1_file->setObjectName(QString::fromUtf8("rad1_file"));

        horizontalLayout->addWidget(rad1_file);

        rad2_inter = new QRadioButton(widget);
        rad2_inter->setObjectName(QString::fromUtf8("rad2_inter"));

        horizontalLayout->addWidget(rad2_inter);

        widget1 = new QWidget(Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(70, 230, 224, 36));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        rad3_3d = new QRadioButton(widget1);
        rad3_3d->setObjectName(QString::fromUtf8("rad3_3d"));

        horizontalLayout_2->addWidget(rad3_3d);

        rad4_2d = new QRadioButton(widget1);
        rad4_2d->setObjectName(QString::fromUtf8("rad4_2d"));

        horizontalLayout_2->addWidget(rad4_2d);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "OK", 0, QApplication::UnicodeUTF8));
        browse->setText(QApplication::translate("Dialog", "Browse", 0, QApplication::UnicodeUTF8));
        rad1_file->setText(QApplication::translate("Dialog", "file", 0, QApplication::UnicodeUTF8));
        rad2_inter->setText(QApplication::translate("Dialog", "interactive", 0, QApplication::UnicodeUTF8));
        rad3_3d->setText(QApplication::translate("Dialog", "3d", 0, QApplication::UnicodeUTF8));
        rad4_2d->setText(QApplication::translate("Dialog", "2d", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
