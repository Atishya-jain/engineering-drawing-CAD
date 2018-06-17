/*! \file */
#include <bits/stdc++.h>
using namespace std;
#ifndef _STRUCT_H
#define _STRUCT_H
    /*! \struct point
        \brief Struct point.

        This struct contains the representation of the points on coordinate axis 
        which can be accessed by all the other classes to edit.
    */
    struct point {
    	float coordinate[3];
    	string label;
        bool operator==(const point& rhs){
            return (coordinate[0]==rhs.coordinate[0])&&(coordinate[1]==rhs.coordinate[1])&&(coordinate[2]==rhs.coordinate[2])&&(label.compare(rhs.label)==0);
        }
        string print(){
            return label+","+to_string(coordinate[0])+","+to_string(coordinate[1])+","+to_string(coordinate[2])+" ";
        }
    };

    /*! \struct plane
        \brief Struct plane.

        This struct contains the representation of a plane on coordinate axis 
        which can be accessed by all the other classes to edit.
        This plane is of the form Ax + By + Cz = D which is a unique representation of any plane
    */
    struct plane {
        float A;
        float B;
        float C;
        float D;
    };

    /*! \struct edge
        \brief Struct edge.

        This struct represents an edge, as we know two points uniquely determine a line.
    */
    struct edge{
        point p1;
        point p2;
        bool Dotted=false;
        bool operator==(const edge& rhs){
            return ((p1==rhs.p1 && p2==rhs.p2)||(p1==rhs.p2 && p2==rhs.p1));
        }
    };
    
#endif
