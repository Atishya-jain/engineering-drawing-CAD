#ifndef INTERACTIVEINPUT_H
#define INTERACTIVEINPUT_H

#include <QDialog>

namespace Ui {
class InteractiveInput;
}

class InteractiveInput : public QDialog
{
    Q_OBJECT

public:
    explicit InteractiveInput(QWidget *parent = 0);
    ~InteractiveInput();

public:
    Ui::InteractiveInput *ui;
private slots:
    void on_draw_clicked();
    void on_erase_clicked();
    void on_Done_clicked();
};

#endif // INTERACTIVEINPUT_H
