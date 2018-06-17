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
            return ((fabs(coordinate[0]-rhs.coordinate[0])<0.001)&&(fabs(coordinate[1]-rhs.coordinate[1])<0.001)&&(fabs(coordinate[2]-rhs.coordinate[2])<0.001)&&(label.compare(rhs.label)==0));
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
        // string toString(){
        //     ostringstream s1;
        //     s1 << A;
        //     ostringstream s2;
        //     s2 << B;
        //     ostringstream s3;
        //     s3 << C;
        //     return s1.str()+"["+s2.str()+"]"+s3.str();
        // }
        // plane getPlane(string s){
        //     int x = s.find("[");
        //     int y = s.find("]");

        //     string a = s.substr(0,x);
        //     string b = s.substr(x+1,y-x-1);
        //     string c = s.substr(y+1,s.length()-y-1);

        //     plane ret;
        //     ret.A = stof(a);
        //     ret.B = stof(b);
        //     ret.C = stof(c);
        //     return ret;
        // }
        float A;
        float B;
        float C;
        float D;
        // point p1;    
        // point p2;    
        // point p3;    
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
