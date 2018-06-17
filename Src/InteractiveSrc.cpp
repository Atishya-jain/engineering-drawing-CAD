/*! \file */
#include <bits/stdc++.h>
#include "../Include/structs.h"
#include "../Include/InteractiveSrc.h"
#include "../Include/OutputSrc.h"
#include "../Include/2DProcessingSrc.h"
#include "../Include/3DProcessingSrc.h"
using namespace std;

/*! \class Interactive_editor
    \brief Editor class.

    This class contains the methods to edit a drawing or take the user input to draw on canvas.
*/


Interactive_editor::Interactive_editor() {
  lineDraw = false;
  erase = false;
}
/*!
   Will get the points the user wants to delete or draw.
   \sa drawLine()
   \sa eraseIt()
*/
void Interactive_editor::userInput() {
  if (lineDraw) {
    struct point tempPointA, tempPointB;
    float x, y, z;
    string ptLabel;

    cout << "Enter x y z label (all inputs with a space between them) for point1: ";
    cin >> x >> y >> z >> ptLabel;
    tempPointA.coordinate[0] = x;
    tempPointA.coordinate[1] = y;
    tempPointA.coordinate[2] = z;
    tempPointA.label = ptLabel;

    cout << "Enter x y z label (all inputs with a space between them) for point2: ";
    cin >> x >> y >> z >> ptLabel;
    tempPointB.coordinate[0] = x;
    tempPointB.coordinate[1] = y;
    tempPointB.coordinate[2] = z;
    tempPointB.label = ptLabel;

    drawLine(tempPointA, tempPointB);
  }
  if (erase) {
    struct point tempPointA, tempPointB;
    float x, y, z;
    string ptLabel;

    cout << "Enter x y z label (all inputs with a space between them) for point1: ";
    cin >> x >> y >> z >> ptLabel;
    tempPointA.coordinate[0] = x;
    tempPointA.coordinate[1] = y;
    tempPointA.coordinate[2] = z;
    tempPointA.label = ptLabel;

    cout << "Enter x y z label (all inputs with a space between them) for point2: ";
    cin >> x >> y >> z >> ptLabel;
    tempPointB.coordinate[0] = x;
    tempPointB.coordinate[1] = y;
    tempPointB.coordinate[2] = z;
    tempPointB.label = ptLabel;
    eraseIt(tempPointA, tempPointB);
  }

}

/*!
   Will display the options/settings user desires
   \sa userInput()
*/
void Interactive_editor::displayOptions() {
  /*Display various options*/
  userInput();
}

/*!
   Will make a graph to store the user desired line.
  \param point1 To get 1st point of line.
  \param point2 To get 2nd point of line.
*/
void Interactive_editor::drawLine(point p1, point p2) {
  /*draws a line*/

  if (MyPlane.count(p1.label) != 0) {
    MyPlane[p1.label].push_back(p2);
  } else {
    vector<point> tmp;
    tmp.push_back(p1);
    tmp.push_back(p2);
    MyPlane[p1.label] = tmp;
  }

  if (MyPlane.count(p2.label) != 0) {
    MyPlane[p2.label].push_back(p1);
  } else {
    vector<point> tmp;
    tmp.push_back(p2);
    tmp.push_back(p1);
    MyPlane[p2.label] = tmp;
  }
}

/*!
   Will erase the line user wishes to erase
   \param point1 To get the 1st point of line
   \param point2 To get the 2nd point of line
*/
void Interactive_editor::eraseIt(point p1, point p2) {
  /*erases a line*/

  if (MyPlane.count(p1.label) != 0) {
    for (int j = 0; j < signed(MyPlane[p1.label].size()); j++) {
      if (MyPlane[p1.label][j] == p2) {
        MyPlane[p1.label].erase(MyPlane[p1.label].begin() + j);
        break;
      }
    }
    if (MyPlane[p1.label].size() == 1) {
      MyPlane.erase(p1.label);
    }
  }

  if (MyPlane.count(p2.label) != 0) {
    for (int j = 0; j < signed(MyPlane[p2.label].size()); j++) {
      if (MyPlane[p2.label][j] == p1) {
        MyPlane[p2.label].erase(MyPlane[p2.label].begin() + j);
        break;
      }
    }
    if (MyPlane[p2.label].size() == 1) {
      MyPlane.erase(p2.label);
    }
  }
}
/*!
 To print the graph on terminal
 */
void Interactive_editor::print() {
  for (std::map<string, vector<point> >::iterator it = MyPlane.begin(); it != MyPlane.end(); ++it) {
    cout << it->first + "->";
    for (int j = 0; j < signed(it->second.size()); j++) {
      cout << it->second[j].label + " ";
    }
    cout << endl;
  }
}
