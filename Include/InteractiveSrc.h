/*! \file */
#include <bits/stdc++.h>
#include"structs.h"
using namespace std;

#ifndef __INTERACTIVE_H
#define __INTERACTIVE_H
/*! \class Interactive_editor
    \brief Editor class.
  
    This class contains the methods to edit a drawing or to play with a model drawing
*/
class Interactive_editor
{
  // Access specifier
  public:

  // Data Members
	// TwoDGraph_class planeObj; !< This object is to store a plane's datastructure
	// TwoDGraph_class TwoDObjMain;
	// ThreeDGraph_class ThreeDObjMain;

  map<string, vector<point> > MyPlane; /*!< This is a plane */
  // pair<float,float> point; /*!< This object is to store a point's datastructure*/
  // pair<pair<float,float>,pair<float,float>> line; /*!< This object is to store a line's datastructure*/
  bool lineDraw; /*!< This flag is set to identify whether user wants to draw a line or not*/
  bool erase; /*!< This flag is set to identify whether user wants to erase something or not*/
  

  Interactive_editor();
    /*!
     Will set the options/settings user desires
    \param drawing To check if user wants to draw something or want to edit the current drawing.
    \param linedraw To check if user wants to draw a line.
    \param circledraw To check if user wants to draw a cicle.
    \param erase To check if user wants to erase something.
    \param extrude To check if user wants to extrude a plane.
    \param flag3Dfile To check if file is input or an intercative input.
  */
  void userInput();
  
  /*!
     Will display the options/settings user desires
  */
  void displayOptions();

  /*!
     Will set the options/settings user desires
    \param poin1 To get 1st point of line.
    \param poin2 To get 2nd point of line.
    \param thickness To get thickness of line.
    \param color To get color of the line.
  */
  void drawLine(point p1, point p2);

  /*!
     Will set the options/settings user desires
  */
  void eraseIt(point p1, point p2);
 /*!
  To print the graph
  */
  void print();
};
#endif
