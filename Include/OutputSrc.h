/*! \file */
#include <bits/stdc++.h>
#include "structs.h"
#include <QtCore>
#include <QtGui>

using namespace std;

#ifndef _OUTPUT_H
#define _OUTPUT_H

  /*! \class Output
      \brief Render and save class.

      This class contains the methods to render the object on screen as well as save it in a file.
  */
  class Output
  {
      // Access specifier
      public:

      // Data Members
      map<string, vector<bool> > LookupForHidden2D[3]; /*!< This is orthographic projections hidden edges*/
      map<string, vector<bool> > LookupForHidden3D; /*!< This is isometric projection hidden edges*/
      map<string, vector<point> > TwoDGraph[3]; /*!< This is the array of orthographic projections */
      map<string, vector<point> > ThreeDGraph;  /*!< This is the 3D graph */
      map<string, vector<point> > PlaneProj;
      map<string, vector<point> > TwoDGraphTemp[3]; 
      map<string, vector<point> > PlaneProjTemp; 
  	  
      //! A Member function.
      /*!
        \sa RenderOutput3D()
        \param filename a string argument.
        \param flag3Dfile boolean character to tell the type of file (3D/2D).
      */
      QPicture RenderOutput3D(QPicture pi);

   
  	  //! A Member function.
      /*!
        \sa RenderOutput2D()
        \param filename a string argument.
        \param flag3Dfile boolean character to tell the type of file (3D/2D).
      */
      QPicture RenderOutput2D(QPicture pi);
  	//! A Member function.
      /*!
        \sa saveToFile3D()
        \param filename a string argument.
        \param flag3Dfile boolean character to tell the type of file (3D/2D).
      */
      void saveToFile3D(string fname);


  	//! A Member function.
      /*!
        \sa saveToFile2D()
        \param filename a string argument.
        \param flag3Dfile boolean character to tell the type of file (3D/2D).
      */
      void saveToFile2D(string fname);
  };
#endif
