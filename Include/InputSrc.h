/*! \file */
#include <bits/stdc++.h>
#include"structs.h"
using namespace std;

#ifndef _INPUT_H
#define _INPUT_H
/*! \class Input
    \brief Input class.

    This class contains the methods to input content from a file or drawing etc..
*/
class Input
{

  // Access specifier
  public:

  // Data Members
  string filename; /*!< This is the filename*/
  bool file = false; /*!< This is flag for checking interactive input or file input from the user*/ 
  bool ThreeDfile = false; /*!< This is flag for checking whether file has 3D or 2D input*/ 
  int TwoDFileCount = 0; /*!< Count of 2D objects as there has to be 3 projections for our software to work on*/
  map<string, vector<point> > TwoDGraph[3]; /*!< This is the array of orthographic projections */
  map<string, vector<point> > ThreeDGraph;  /*!< This is the 3D graph */
   
  /*!
     Will prompt the user for filename or through GUI
  */
  void getFileName(string file, bool threeD);
  /*!
    \param filename a string argument.
    \param ThreeDorTwoD boolean character to tell the type of file (3D/2D).
  */
  void ReadFile();
  void print();
  void print3D();
};
#endif

