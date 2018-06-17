/*! \file */
#include <bits/stdc++.h>
#include"structs.h"
using namespace std;

#ifndef _TWOD_H
#define _TWOD_H

  /*! \class TwoDGraph_class
      \brief 2D behaviour class.

      This class has all the functionalities that a 2D object can possess
      in the software. It can be rotated and converted into isometric from 2 orthographic projections
      along some plane.  
  */
  class TwoDGraph_class{
      // Access specifier
      public:
      // Data Members
      map<string, vector<point> > TwoDGraph[3];/*!< This is the orthographic projections */
      map<string, vector<point> > ThreeDGraph; /*!< This is the 3D graph representation */
      map<string,vector<vector<edge> > > faceSet; /*!<This consists of the faces. It would be a dictionary with face equation as keys as values as those edges which lie in that plane*/

  	//! A Member function.
      /*!
        \sa TwoDtoThreeD()
        \param filename a string argument.
        \param flag3Dfile boolean character to tell the type of file (3D/2D).
      */

      void TwoDtoThreeD();
      void print3D();


  };
#endif