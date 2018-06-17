/*! \file */
#include <bits/stdc++.h>
#include"structs.h"

typedef vector<float> Vec;
typedef vector<Vec> Mat;

using namespace std;

#ifndef _THREED_H
#define _THREED_H
#define INF 1000000
  Vec operator*(const Mat &a, const Vec &x);
  
  /*! \class ThreeDGraph_class
      \brief 3D behaviour class.

      This class has all the functionalities that a 3D object can possess
      in the software. It can be rotated, projected along some plane or
      can give its orthographic projections
  */
  class ThreeDGraph_class{
    private:
    static bool sortinrev(const pair<float,string> &a, const pair<float,string> &b);
    
    static bool sortbyfir(const pair<float,point> &a, const pair<float,point> &b);

    string GetLabel(struct point myPoint, int GraphNo);
    
    string GetLabel1(struct point myPoint, plane equationOfPlane);
    
    float DistanceFromPlane(point myPoint, plane equationOfPlane);

    point pointProj(point myPoint, plane equationOfPlane);

    bool present(vector<point> myList, string myLabel);

    Mat createMatrix();

    void specificRotation(float angle, int choiceAxis, Vec Aline, bool GraphOrLine, bool ThreeDGraphOrPlaneProj);
    
    point getIntersect(edge a1, edge a2, int GraphNum, int lab);
    
    bool onSegment(point p, point q, point r, int GraphNum);

    int orientation(point p, point q, point r, int GraphNum);

    bool doIntersect(edge a1, edge a2, int GraphNum);

    bool isInside(vector<edge> face, point p, int GraphNum);

    void classifyHiddenEdge(int GraphNum, bool IsoOr3D);

    void FaceRecognition(bool ch);

    bool lieOnLine(point p, edge a, int GraphNum);

    float distancePts(point a, point b, int GraphNum);

    bool planeBehindOrFront(point p, vector<edge> face, int GraphNum);

    bool checkSamePlane(point p1, point p2, point p3, point p4);




    // Access specifier
    public:

    ThreeDGraph_class();
  
    // Data Members
    map<string, vector<point> > ThreeDGraph; /*!< This is the 3D graph representation */
    map<string, vector<point> > IsometricGraph; /*!< This is the Isometric graph representation */
    map<string, vector<point> > TwoDGraph[3]; /*!< This is orthographic projections */
    map<string, vector<point> > PlaneProj; /*!< This is planar projection of 3D graph when requested */
    vector<string> listOfPoints;/*!< This is list of points available in 3D graph */
    vector<string> listOfPointsForOrthographic;/*!< This is list of points available for a particular orthographic projection */
    vector<string> listOfPointsForPlane;/*!< This is list of points available in planar Projection */
    map<string, vector<point> > ThreeDGraphForOrthographic; /*!< This is the 3D graph representation */
    map<string, vector<bool> > LookupForHidden2D[3]; /*!< This is orthographic projections hidden edges*/
    map<string, vector<bool> > LookupForHidden3D; /*!< This is the 3D graph representation of hidden edges*/
    vector< vector< edge>> FaceGraph; /*!< This is the graph containing faces and corresponding edges on them */
    Mat matrixAns;/*!< This is answer calculated after matrix computations */
    Mat matrix[3]; /*!< This is matrix for rotating about specific axis */
    Mat matrixA; /*!< This is matrix for rotating about specific axis */
    Mat matrixB; /*!< This is matrix for rotating about specific axis */
    edge tempLineAns;/*!< This is an temporary edge*/
    Vec tempLineVect;/*!< This is a temporary vector*/
    Vec tempLineVectForPlane;/*!< This is a temporary vector*/
    vector<char> digit; /*!< To store the coincident labels in a view for a particular vertex*/


    //! A Member function.
    /*!
      \param ch a boolean argument to recognize whether we have to recignize faces of our 3D graph/ Isometric graph
      Function to recognize faces in a graph
    */
    vector<vector<edge> > getPolygons(bool ch);
    //! A Member function.
    /*!
      Function to initialise a lookup vector to listOfPoints for 3D graph
    */
    void InitialiseLookupForHidden3D(bool IsoOr3D);
    
    //! A Member function.
    /*!
      Function to create listOfPoints for 3D graph
    */
    void GraphToList(bool ThreeDGraphOrPlaneProj);

    //! A Member function.
    /*!
      \param ScaleFactor to tell the factor of scale.
      Will scale the graph to the scale factor
    */
    void Scaling(float ScaleFactor);

    //! A Member function.
    /*!
      \sa Translation()
      \param x to tell the amount of shift in x coordinate.
      \param y to tell the amount of shift in y coordinate.
      \param z to tell the amount of shift in z coordinate.
      \param line line to translate.
      \param GraphOrLine boolean character to tell whether translation required is of line or graph.
      A function to translate the graph to specified position
    */
    void Translation(float x, float y, float z,edge line, bool GraphOrLine);
    //! A Member function.
    /*!
      \param angle a float argument to tell the angle of rotation.
      \param exis an edge about which we have to rotate.
      A function to rotate a graph about an axis by an angle
    */
    void ModelRotation(float angle, edge axis);

     //! A Member function.
    /*!
    A function to scale and translate our object to origin and scale it to look good on canvas
    */
    void MeanNormalisation();
    //! A Member function.
    /*!
    A function to get Isometric graoh from 3D graph
    */
    void Isometric();

    //! A Member function.
    /*!
      \sa GraphToList()
      \param equationOfPlane this defines the plane on which projection has to be taken.
      A function to get a plane projection of a 3D graph on a plane
    */
    map<string, vector<point> > PlanarProjection(plane equationOfPlane);

    //! A Member function.
    /*!
    A function to create all 3 orthographic projections from a 3D graph and save them in a 2D graph
    */
    void ThreeDToOrthographic();

    //! A Member function.
    /*!
      Function to print 2D graph of Y-Z plane on terminal for debugging purposes
    */
    void print();

    //! A Member function.
    /*!
      Function to print 3D graph on terminal for debugging purposes
    */
    void print3D();
  };
#endif
