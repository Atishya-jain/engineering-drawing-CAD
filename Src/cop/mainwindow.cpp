#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../structs.cpp"

MainWindow::MainWindow(QWidget *parent) :
     QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->pushButton,SIGNAL(clicked(bool)),l,SIGNAL(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{
//    edge tmp;
//    point tmp2;
//     tmp2.coordinate[0]=0;
//     tmp2.coordinate[1]=0;
//     tmp2.coordinate[2]=0;
//    tmp.p1=tmp2;
//     point tmp3;
//     tmp3.coordinate[0]=5;
//     tmp3.coordinate[1]=0;
//     tmp3.coordinate[2]=0;
//     tmp.p2=tmp3;
//     input_3d.ModelRotation(stof(ui->coordx->text.toString()),tmp);
//     tmp3.coordinate[0]=0;
//     tmp3.coordinate[1]=1;
//     tmp3.coordinate[2]=0;
//     tmp.p2=tmp3;
//     input_3d.ModelRotation(stof(ui->coordy->text.toString()),tmp);
//     tmp3.coordinate[0]=0;
//     tmp3.coordinate[1]=0;
//     tmp3.coordinate[2]=1;
//     tmp.p2=tmp3;
//     input_3d.ModelRotation(stof(ui->coordz->text.toString()),tmp);
//    ui->label->show();
//}


