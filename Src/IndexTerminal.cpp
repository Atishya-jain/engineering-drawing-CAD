/*! \file */
#include "bits/stdc++.h"
#include <QtCore>
#include <QtGui>

#include "../Include/structs.h"
#include "../Include/2DProcessingSrc.h"
#include "../Include/3DProcessingSrc.h"
#include "../Include/InputSrc.h"
#include "../Include/OutputSrc.h"
#include "../Include/InteractiveSrc.h"
using namespace std;
/*! \fn main()*/
int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	TwoDGraph_class input_2d;
	ThreeDGraph_class input_3d;
	bool isFile3d = true;
	int ch;
	bool isInputFile = true;

	cout << "------INPUT------" << endl;
	cout << "Enter 1 to input via file or 2 to draw: ";
	cin >> ch;
	cout << endl;
	if (ch != 1) isInputFile = false;
	if (isInputFile) {
		//take input from file
		Input I1;
		string in1;
		bool in2;
		cout << "Enter the name of input file: ";
		cin >> in1;
		cout << "Is the file 3d or 2d(enter 1 for 3d, 2 for 2d): ";
		cin >> in2;

		I1.getFileName(in1, in2);
		isFile3d = I1.ThreeDfile;
		I1.ReadFile();
		if (isFile3d) {
			input_3d.ThreeDGraph = I1.ThreeDGraph;
		} else {
			std::copy(std::begin(I1.TwoDGraph), std::end(I1.TwoDGraph), std::begin(input_2d.TwoDGraph));
		}
	}
	else {
		//interactive input
		Interactive_editor I1;
		cout << "2D input or 3D input?(2/3): ";
		cin >> ch;
		cout << endl;
		if (ch == 3) {
			isFile3d = true;
			bool cont = true;
			while (cont) {
				cout << "Enter label for point 1: " << endl;
				point p1;
				cin >> p1.label;
				cout << "Enter space seperated coordinates for point 1: " << endl;
				cin >> p1.coordinate[0] >> p1.coordinate[1] >> p1.coordinate[2];
				cout << endl;
				cout << "Enter label for point 2: " << endl;
				point p2;
				cin >> p2.label;
				cout << "Enter space seperated coordinates for point 2: " << endl;
				cin >> p2.coordinate[0] >> p2.coordinate[1] >> p2.coordinate[2];
				cout << endl;
				cout << "draw or erase?(d/e): ";
				char de;
				cin >> de;
				cout << endl;
				if (de == 'd')
					I1.drawLine(p1, p2);
				else
					I1.eraseIt(p1, p2);
				cout << "continut(y/n): ";
				cin >> de;
				cout << endl;
				if (de == 'y')
					cont = true;
				else
					cont = false;
			}
			input_3d.ThreeDGraph = I1.MyPlane;
		} else {
			isFile3d = false;
			map<string, vector<point> > tmpTwoDGraph[3];/*!< This is the orthographic projections */
			for (int tt = 0; tt < 3; tt++) {
				bool cont = true;
				cout << "Enter details of " << tt << " view.";
				map<string, vector<point> > freshGraph;
				I1.MyPlane = freshGraph;
				while (cont) {
					cout << "Enter label for point 1: " << endl;
					point p1;
					cin >> p1.label;
					cout << "Enter space seperated coordinates for point 1: " << endl;
					cin >> p1.coordinate[0] >> p1.coordinate[1] >> p1.coordinate[2];
					cout << endl;
					cout << "Enter label for point 2: " << endl;
					point p2;
					cin >> p2.label;
					cout << "Enter space seperated coordinates for point 2: " << endl;
					cin >> p2.coordinate[0] >> p2.coordinate[1] >> p2.coordinate[2];
					cout << endl;
					cout << "draw or erase?(d/e): ";
					char de;
					cin >> de;
					cout << endl;
					if (de == 'd')
						I1.drawLine(p1, p2);
					else
						I1.eraseIt(p1, p2);
					cout << "continut(y/n): ";
					cin >> de;
					cout << endl;
					if (de == 'y')
						cont = true;
					else
						cont = false;
				}
				tmpTwoDGraph[tt] = I1.MyPlane;

			}
			std::copy(std::begin(tmpTwoDGraph), std::end(tmpTwoDGraph), std::begin(input_2d.TwoDGraph));

		}
	}



	//OUTPUTTING
	Output O1;

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
	cout << "Do you want to do model rotation?(y/n): ";
	char mdlt;
	cin >> mdlt;
	cout << "mdlt is " << mdlt << endl;

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
	input_3d.ModelRotation(0.1, tmp);
	point tmp4;
	tmp4.coordinate[0] = -5;
	tmp4.coordinate[1] = 0;
	tmp4.coordinate[2] = 0;
	tmp.p2 = tmp4;
	input_3d.ModelRotation(0.1, tmp);

	if (mdlt == 'y') {
		cout << "Model Rotation \nEnter 3 space seperated floats, which stand for angle of rotation along x, y and z axis\n ";
		float ch1, ch2, ch3;
		cin >> ch1 >> ch2 >> ch3;
		ch1 += 0.00001;
		ch2 += 0.00001;
		ch3 += 0.00001;
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
		input_3d.ModelRotation(ch1, tmp);
		tmp3.coordinate[0] = 0;
		tmp3.coordinate[1] = 1;
		tmp3.coordinate[2] = 0;
		tmp.p2 = tmp3;
		input_3d.ModelRotation(ch2, tmp);
		tmp3.coordinate[0] = 0;
		tmp3.coordinate[1] = 0;
		tmp3.coordinate[2] = 1;
		tmp.p2 = tmp3;
		input_3d.ModelRotation(ch3, tmp);
	}

	input_3d.MeanNormalisation();
	input_3d.ThreeDToOrthographic();
	input_3d.Isometric();
	O1.LookupForHidden3D = input_3d.LookupForHidden3D;
	O1.PlaneProj = input_3d.IsometricGraph;
	std::copy(std::begin(input_3d.TwoDGraph), std::end(input_3d.TwoDGraph), std::begin(O1.TwoDGraph));
	std::copy(std::begin(input_3d.LookupForHidden2D), std::end(input_3d.LookupForHidden2D), std::begin(O1.LookupForHidden2D));

	// PLANE PROJECTION
	cout << "Do you want projection along a specific plane?y/n: ";
	char ch4;
	cin >> ch4;
	cout << endl;
	if (ch4 == 'y') {
		cout << "Projection along a specific plane\nEnter 4 space seperated floats, which stand for a,b,c,d in ax+by+cz=d: ";
		float a, b, c, d;
		cin >> a >> b >> c >> d;
		plane tmp;
		tmp.A = a;
		tmp.B = b;
		tmp.C = c;
		tmp.D = d;
		map<string, vector<point> > planPro = input_3d.PlanarProjection(tmp);
		Output O2;
		O2.PlaneProj = planPro;
		O2.LookupForHidden3D = input_3d.LookupForHidden3D;
		pi3 = O2.RenderOutput3D(pi3);
		l3.setPicture(pi3);
		l3.show();
	}
	pi = O1.RenderOutput3D(pi);
	l.setPicture(pi);
	l.show();

	pi2 = O1.RenderOutput2D(pi2);
	l2.setPicture(pi2);
	l2.show();


	//SAVING IN FILE
	cout << "Do you want to save the file?(y/n): ";
	cin >> ch4;
	cout << endl;
	if (ch4 == 'y') {
		cout << "saving in output.txt ";
		if (isFile3d)
			O1.saveToFile2D("output.txt");
		else {
			O1.ThreeDGraph = input_3d.ThreeDGraph;
			O1.saveToFile3D("output.txt");
		}
	}
	cout << "Thanks for using our software" << endl;
	return a.exec();
}
