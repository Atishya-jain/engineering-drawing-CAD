/*! \file */
#include "cop/mainwindow.h"
#include <QApplication>
#include "bits/stdc++.h"
#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <QLabel>
#include "../Include/structs.h"
#include "../Include/2DProcessingSrc.h"
#include "../Include/3DProcessingSrc.h"
#include "../Include/InputSrc.h"
#include "../Include/OutputSrc.h"
#include "../Include/InteractiveSrc.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "interactiveinput.h"
#include "ui_interactiveinput.h"
#include <QFileDialog>
#include <QDir>
using namespace std;
TwoDGraph_class input_2d;
ThreeDGraph_class input_3d;
Interactive_editor I1;
Output O1;
Output O2;
bool isFile3d;
bool isInputFile;
string filename;

/*!
\sa ModelRotation()
\sa ThreeDToOrthographic()
\sa Isometric()
\sa RenderOutput3D()
\sa RenderOutput2D()
Coordinates the user click response on Up button and rotates the object about x axis
*/
void MainWindow::on_buttonUP_clicked()
{
    //MODEL ROTATION and ISOMETRIC
    edge tmp;
    point tmp2;
    tmp2.coordinate[0] = 0;
    tmp2.coordinate[1] = 0;
    tmp2.coordinate[2] = 0;
    tmp.p1 = tmp2;
    point tmp3;
    tmp3.coordinate[0] = 5;
    tmp3.coordinate[1] = 0;
    tmp3.coordinate[2] = 0;
    tmp.p2 = tmp3;
    input_3d.ModelRotation(10, tmp);
    input_3d.Isometric();
    O1.PlaneProj = input_3d.IsometricGraph;
    O1.LookupForHidden3D = input_3d.LookupForHidden3D;
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    QPicture pi;
    pi = O1.RenderOutput3D(pi);
    ui->isometric->setPicture(pi);
    ui->isometric->show();

    input_3d.ThreeDToOrthographic();
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));
    QPicture pi4;
    pi4 = O1.RenderOutput2D(pi4);
    ui->orthographic->setPicture(pi4);
    ui->orthographic->show();
}

/*!
\sa ModelRotation()
\sa ThreeDToOrthographic()
\sa Isometric()
\sa RenderOutput3D()
\sa RenderOutput2D()
Coordinates the user click response on Left button and rotates the object about y axis
*/
void MainWindow::on_buttonLEFT_clicked()
{
    //MODEL ROTATION and ISOMETRIC
    edge tmp;
    point tmp2;
    tmp2.coordinate[0] = 0;
    tmp2.coordinate[1] = 0;
    tmp2.coordinate[2] = 0;
    tmp.p1 = tmp2;
    point tmp3;
    tmp3.coordinate[0] = 0;
    tmp3.coordinate[1] = 5;
    tmp3.coordinate[2] = 0;
    tmp.p2 = tmp3;
    input_3d.ModelRotation(10, tmp);
    input_3d.Isometric();
    O1.PlaneProj = input_3d.IsometricGraph;
    O1.LookupForHidden3D = input_3d.LookupForHidden3D;
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    QPicture pi;
    pi = O1.RenderOutput3D(pi);
    ui->isometric->setPicture(pi);
    ui->isometric->show();

    input_3d.ThreeDToOrthographic();
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));
    QPicture pi4;
    pi4 = O1.RenderOutput2D(pi4);
    ui->orthographic->setPicture(pi4);
    ui->orthographic->show();
}


/*!
\sa ModelRotation()
\sa ThreeDToOrthographic()
\sa Isometric()
\sa RenderOutput3D()
\sa RenderOutput2D()
Coordinates the user click response on Right button and rotates the object about y axis
*/
void MainWindow::on_buttonRIGHT_clicked()
{
    //MODEL ROTATION and ISOMETRIC
    edge tmp;
    point tmp2;
    tmp2.coordinate[0] = 0;
    tmp2.coordinate[1] = 0;
    tmp2.coordinate[2] = 0;
    tmp.p1 = tmp2;
    point tmp3;
    tmp3.coordinate[0] = 0;
    tmp3.coordinate[1] = 5;
    tmp3.coordinate[2] = 0;
    tmp.p2 = tmp3;
    input_3d.ModelRotation(-10, tmp);
    input_3d.Isometric();
    O1.PlaneProj = input_3d.IsometricGraph;
    O1.LookupForHidden3D = input_3d.LookupForHidden3D;
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    QPicture pi;
    pi = O1.RenderOutput3D(pi);
    ui->isometric->setPicture(pi);
    ui->isometric->show();

    input_3d.ThreeDToOrthographic();
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));
    QPicture pi4;
    pi4 = O1.RenderOutput2D(pi4);
    ui->orthographic->setPicture(pi4);
    ui->orthographic->show();
}


/*!
\sa ModelRotation()
\sa ThreeDToOrthographic()
\sa Isometric()
\sa RenderOutput3D()
\sa RenderOutput2D()
Coordinates the user click response on Down button and rotates the object about x axis
*/
void MainWindow::on_buttonDOWN_clicked()
{
    //MODEL ROTATION and ISOMETRIC
    edge tmp;
    point tmp2;
    tmp2.coordinate[0] = 0;
    tmp2.coordinate[1] = 0;
    tmp2.coordinate[2] = 0;
    tmp.p1 = tmp2;
    point tmp3;
    tmp3.coordinate[0] = 5;
    tmp3.coordinate[1] = 0;
    tmp3.coordinate[2] = 0;
    tmp.p2 = tmp3;
    input_3d.ModelRotation(-10, tmp);
    input_3d.Isometric();
    O1.PlaneProj = input_3d.IsometricGraph;
    O1.LookupForHidden3D = input_3d.LookupForHidden3D;
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    QPicture pi;
    pi = O1.RenderOutput3D(pi);
    ui->isometric->setPicture(pi);
    ui->isometric->show();

    input_3d.ThreeDToOrthographic();
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));
    QPicture pi4;
    pi4 = O1.RenderOutput2D(pi4);
    ui->orthographic->setPicture(pi4);
    ui->orthographic->show();
}


/*!
\sa ModelRotation()
\sa ThreeDToOrthographic()
\sa Isometric()
\sa RenderOutput3D()
\sa RenderOutput2D()
Coordinates the user click response on Z+ button and rotates the object about z axis
*/
void MainWindow::on_buttonZplus_clicked()
{
    //MODEL ROTATION and ISOMETRIC
    edge tmp;
    point tmp2;
    tmp2.coordinate[0] = 0;
    tmp2.coordinate[1] = 0;
    tmp2.coordinate[2] = 0;
    tmp.p1 = tmp2;
    point tmp3;
    tmp3.coordinate[0] = 0;
    tmp3.coordinate[1] = 0;
    tmp3.coordinate[2] = 5;
    tmp.p2 = tmp3;
    input_3d.ModelRotation(10, tmp);
    input_3d.Isometric();
    O1.PlaneProj = input_3d.IsometricGraph;
    O1.LookupForHidden3D = input_3d.LookupForHidden3D;
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    QPicture pi;
    pi = O1.RenderOutput3D(pi);
    ui->isometric->setPicture(pi);
    ui->isometric->show();

    input_3d.ThreeDToOrthographic();
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));
    QPicture pi4;
    pi4 = O1.RenderOutput2D(pi4);
    ui->orthographic->setPicture(pi4);
    ui->orthographic->show();
}

/*!
\sa ModelRotation()
\sa ThreeDToOrthographic()
\sa Isometric()
\sa RenderOutput3D()
\sa RenderOutput2D()
Coordinates the user click response on Z- button and rotates the object about z axis
*/
void MainWindow::on_buttonZminus_clicked()
{
    //MODEL ROTATION and ISOMETRIC
    edge tmp;
    point tmp2;
    tmp2.coordinate[0] = 0;
    tmp2.coordinate[1] = 0;
    tmp2.coordinate[2] = 0;
    tmp.p1 = tmp2;
    point tmp3;
    tmp3.coordinate[0] = 0;
    tmp3.coordinate[1] = 0;
    tmp3.coordinate[2] = 5;
    tmp.p2 = tmp3;
    input_3d.ModelRotation(-10, tmp);
    input_3d.Isometric();
    O1.PlaneProj = input_3d.IsometricGraph;
    O1.LookupForHidden3D = input_3d.LookupForHidden3D;
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    QPicture pi;
    pi = O1.RenderOutput3D(pi);
    ui->isometric->setPicture(pi);
    ui->isometric->show();

    input_3d.ThreeDToOrthographic();
    std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
    std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));
    QPicture pi4;
    pi4 = O1.RenderOutput2D(pi4);
    ui->orthographic->setPicture(pi4);
    ui->orthographic->show();
}

/*!
\sa PlanarProjection()
\sa RenderOutput3D()
Coordinates the user click response on plane button and does the corresponding planar projection
*/
void MainWindow::on_buttonPlane_clicked()
{
    //PLANE PROJECTION
    plane tmpPlane;
    tmpPlane.A = ui->Ax->toPlainText().toFloat();
    tmpPlane.B = ui->By->toPlainText().toFloat();
    tmpPlane.C = ui->Cz->toPlainText().toFloat();
    tmpPlane.D = ui->Dd->toPlainText().toFloat();
    map<string, vector<point> > planPro = input_3d.PlanarProjection(tmpPlane);
    O2.LookupForHidden3D = input_3d.LookupForHidden3D;
    O2.PlaneProj = planPro;
    QPicture pi3;
    pi3 = O2.RenderOutput3D(pi3);
    ui->planeProj->setPicture(pi3);
    ui->planeProj->show();
}

/*!
Coordinates the user click response on radio buttons for 3D/2D and sets the corresponding values
*/
void Dialog::on_pushButton_clicked()
{
    if (ui->rad2_inter->isChecked())
        isInputFile = false;
    filename = ui->filename->toPlainText().toStdString();
    if (ui->rad4_2d->isChecked())
        isFile3d = false;
    cout << isFile3d << endl;
    close();
}

/*!
Coordinates the user click response on browse button and browses the file on system.
*/
void Dialog::on_browse_clicked()
{
    QString tmpFileName = QFileDialog::getOpenFileName(this, "Select the file", QDir::currentPath());
    ui->filename->setPlainText(tmpFileName);
}

void InteractiveInput::on_draw_clicked()
{
    point p1;
    p1.label = ui->p1label->toPlainText().toStdString();
    p1.coordinate[0] = ui->p1x->toPlainText().toFloat();
    p1.coordinate[1] = ui->p1y->toPlainText().toFloat();
    p1.coordinate[2] = ui->p1z->toPlainText().toFloat();
    point p2;
    p2.label = ui->p2label->toPlainText().toStdString();
    p2.coordinate[0] = ui->p2x->toPlainText().toFloat();
    p2.coordinate[1] = ui->p2y->toPlainText().toFloat();
    p2.coordinate[2] = ui->p2z->toPlainText().toFloat();
    I1.drawLine(p1, p2);
    ThreeDGraph_class Itmp;
    Itmp.ThreeDGraph = I1.MyPlane;
    Itmp.GraphToList(true);
    Itmp.Isometric();
    Itmp.InitialiseLookupForHidden3D(false);
    Output Otmp;
    Otmp.PlaneProj = Itmp.IsometricGraph;
    Otmp.LookupForHidden3D = Itmp.LookupForHidden3D;
    QPicture pi;
    pi = Otmp.RenderOutput3D(pi);
    ui->label->setPicture(pi);
    ui->label->show();

}

/*!
\sa InitialiseLookupForHidden3D()
\sa GraphToList()
\sa Isometric()
\sa RenderOutput3D()
Coordinates the user click response on erase button and does the corresponding erase action
*/
void InteractiveInput::on_erase_clicked()
{
    point p1;
    p1.label = ui->p1label->toPlainText().toStdString();
    p1.coordinate[0] = ui->p1x->toPlainText().toFloat();
    p1.coordinate[1] = ui->p1y->toPlainText().toFloat();
    p1.coordinate[2] = ui->p1z->toPlainText().toFloat();
    point p2;
    p2.label = ui->p2label->toPlainText().toStdString();
    p2.coordinate[0] = ui->p2x->toPlainText().toFloat();
    p2.coordinate[1] = ui->p2y->toPlainText().toFloat();
    p2.coordinate[2] = ui->p2z->toPlainText().toFloat();
    I1.eraseIt(p1, p2);
    ThreeDGraph_class Itmp;
    Itmp.ThreeDGraph = I1.MyPlane;
    Itmp.GraphToList(true);
    Itmp.Isometric();
    Itmp.InitialiseLookupForHidden3D(false);
    Output Otmp;
    Otmp.PlaneProj = Itmp.IsometricGraph;
    Otmp.LookupForHidden3D = Itmp.LookupForHidden3D;
    QPicture pi;
    pi = Otmp.RenderOutput3D(pi);
    ui->label->setPicture(pi);
    ui->label->show();
}

/*!
Coordinates the user click response on Done button and does the corresponding action to close the interactive Input canvas.
*/
void InteractiveInput::on_Done_clicked()
{
    close();
}


/*! \fn main()
	It is the main control of our program.
*/
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    Dialog d;
    d.setModal(true);
    isFile3d = true;
    isInputFile = true;
    d.exec();

    cout << "------INPUT------" << endl;
    if (isInputFile) {
        Input I1;
        I1.getFileName(filename, isFile3d);
        I1.ReadFile();
        if (isFile3d) {
            input_3d.ThreeDGraph = I1.ThreeDGraph;
        } else {
            std::copy(std::begin(I1.TwoDGraph), std::end(I1.TwoDGraph), std::begin(input_2d.TwoDGraph));
        }
    }
    else {
        if (isFile3d) {
            InteractiveInput i;
            i.exec();
            input_3d.ThreeDGraph = I1.MyPlane;
        } else {
            map<string, vector<point> > tmpTwoDGraph[3];/*!< This is the orthographic projections */
            for (int tt = 0; tt < 3; tt++) {
                cout << "Enter details of " << tt << " view.";
                map<string, vector<point> > freshGraph;
                I1.MyPlane = freshGraph;
                InteractiveInput i;
                i.exec();
                tmpTwoDGraph[tt] = I1.MyPlane;
            }
            std::copy(std::begin(tmpTwoDGraph), std::end(tmpTwoDGraph), std::begin(input_2d.TwoDGraph));
        }
    }

    if (isFile3d == false) {
        input_2d.TwoDtoThreeD();
        std::copy(std::begin(input_2d.TwoDGraph), std::end(input_2d.TwoDGraph), std::begin(input_3d.TwoDGraph));
        input_3d.ThreeDGraph = input_2d.ThreeDGraph;
    }

    //rendering the 3d input

    QLabel l;//iso
    QPicture pi;
    QLabel l2;//ortho
    QPicture pi2;
    QLabel l3;//planarproj
    QPicture pi3;


    //MODEL ROTATATION
    input_3d.GraphToList(true);
    input_3d.MeanNormalisation();
    input_3d.ThreeDToOrthographic();


    //SAVING IN FILE
    cout << "saving in output.txt ";
    if (isFile3d) {
        copy(begin(input_3d.TwoDGraph), end(input_3d.TwoDGraph), begin(O1.TwoDGraph));
        O1.saveToFile2D("output.txt");
    }
    else {
        O1.ThreeDGraph = input_3d.ThreeDGraph;
        O1.saveToFile3D("output.txt");
    }
    if (isInputFile) {
        w.ui->buttonUP->click();
        w.ui->buttonRIGHT->click();
    } else {
        w.ui->buttonZplus->click();
        w.ui->buttonZminus->click();
    }
    w.show();
    cout << "Thanks for using our software" << endl;
    return a.exec();
}

// Our aim is not to create duplicates of graph everywhere but only to use pointers to point to one graph
