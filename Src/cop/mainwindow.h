#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonPlane_clicked();

    void on_buttonDOWN_clicked();
    void on_buttonLEFT_clicked();
    void on_buttonZplus_clicked();
    void on_buttonZminus_clicked();
    void on_buttonRIGHT_clicked();
    void on_buttonUP_clicked();

public:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
