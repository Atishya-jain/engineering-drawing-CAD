/*! \file */
#include <bits/stdc++.h>
#include "../Include/3DProcessingSrc.h"
#include "../Include/structs.h"

typedef vector<float> Vec;
typedef vector<Vec> Mat;
#define PI 3.14159265
#define ERRORMARGIN 0.0000001

using namespace std;

/*!
Overloads the * operator to allow for a matrix and a vector multiplication
*/
Vec operator*(const Mat &a, const Vec &x){
  int i,j;
  int m = a.size();
  int n = x.size();

  Vec prod(m);

  for(i = 0; i < m; i++){
    prod[i] = 0.;
    for(j = 0; j < n; j++)
      prod[i] += a[i][j]*x[j];
  }
  return prod;
}

/*! \class ThreeDGraph_class
    \brief 3D behaviour class.

    This class has all the functionalities that a 3D object can possess
    in the software. It can be rotated, projected along some plane or
    can give its orthographic projections
*/

  bool ThreeDGraph_class::sortinrev(const pair<float,string> &a, const pair<float,string> &b){
         return (a.first > b.first);
  }

  // Driver function to sort the vector elements
  // by second element of pairs
  bool ThreeDGraph_class::sortbyfir(const pair<float,point> &a, const pair<float,point> &b){
    return (a.first < b.first);
  }

  string ThreeDGraph_class::GetLabel(struct point myPoint, int GraphNo){
    long tempSize = listOfPoints.size();
    vector< pair<float,string>> ToSort;
    ToSort.push_back(make_pair(myPoint.coordinate[GraphNo],myPoint.label));
    digit.clear();
    for(int j = 0;j<tempSize;j++){
      point tempPoint = ThreeDGraph[listOfPoints[j]][0];
      if((abs((tempPoint.coordinate[(GraphNo+1)%3]) - (myPoint.coordinate[(GraphNo+1)%3]))<= ERRORMARGIN)&&(abs((tempPoint.coordinate[(GraphNo+2)%3]) - (myPoint.coordinate[(GraphNo+2)%3]))<= ERRORMARGIN)){
        if(abs((tempPoint.coordinate[(GraphNo)%3]) - (myPoint.coordinate[(GraphNo)%3]))>= ERRORMARGIN){
          ToSort.push_back(make_pair(tempPoint.coordinate[GraphNo],tempPoint.label));
          digit.push_back(j);
        }
      }
    }
    sort(ToSort.begin(), ToSort.end(), sortinrev);
    int ToSortLen = ToSort.size();
    string tempLabel = ToSort[0].second;
    for(int j = 1;j<ToSortLen;j++){
      tempLabel.append("^");
      tempLabel.append(ToSort[j].second);
    }
    return tempLabel;
  }
  
  string ThreeDGraph_class::GetLabel1(struct point myPoint, plane equationOfPlane){
    long tempSize = listOfPoints.size();
    vector< pair<float,string>> ToSort;
    float distance = DistanceFromPlane(myPoint, equationOfPlane);
    ToSort.push_back(make_pair(distance,myPoint.label));
    point modMyPoint = pointProj(myPoint, equationOfPlane);
    for(int j = 0;j<tempSize;j++){
      point tempPoint = ThreeDGraph[listOfPoints[j]][0];
      point modPoint = pointProj(tempPoint, equationOfPlane);
      float tempA = modPoint.coordinate[0];
      float tempB = modPoint.coordinate[1];
      float tempC = modPoint.coordinate[2];
      float tempMyA = modMyPoint.coordinate[0];
      float tempMyB = modMyPoint.coordinate[1];
      float tempMyC = modMyPoint.coordinate[2];
      if(tempPoint.label != myPoint.label){
        if((abs((tempA) - (tempMyA))<= ERRORMARGIN)&&(abs((tempB) - (tempMyB))<= ERRORMARGIN)&&(abs((tempC) - (tempMyC))<= ERRORMARGIN)){
          distance = DistanceFromPlane(tempPoint, equationOfPlane);
          ToSort.push_back(make_pair(distance,tempPoint.label));
        }
      }
    }
    sort(ToSort.begin(), ToSort.end(), sortinrev);
    int ToSortLen = ToSort.size();
    string tempLabel = ToSort[0].second;
    for(int j = 1;j<ToSortLen;j++){
      tempLabel.append("^");
      tempLabel.append(ToSort[j].second);
    }
    return tempLabel;
  }

  float ThreeDGraph_class::DistanceFromPlane(point myPoint, plane equationOfPlane){
    float a = equationOfPlane.A;
    float b = equationOfPlane.B;
    float c = equationOfPlane.C;
    float num = (a*myPoint.coordinate[0]) + (b*myPoint.coordinate[1]) + (c*myPoint.coordinate[2]) + equationOfPlane.D; // Currently I have not taken Absolute value in numerator as I want it diection wise
    float denom = sqrt(a*a + b*b + c*c);
    return float(num/denom);
  }

  point ThreeDGraph_class::pointProj(point myPoint, plane equationOfPlane){
    point tempPoint;
    float tempA = equationOfPlane.A;
    float tempB = equationOfPlane.B;
    float tempC = equationOfPlane.C;
    float tempD = equationOfPlane.D;
    float t = (tempD - ((tempA)*(myPoint.coordinate[0])) - ((tempB)*(myPoint.coordinate[1])) - ((tempC)*(myPoint.coordinate[2])))/((tempA*tempA)+(tempB*tempB)+(tempC*tempC));
    tempPoint.coordinate[0] = myPoint.coordinate[0] + (tempA*t);
    tempPoint.coordinate[1] = myPoint.coordinate[1] + (tempB*t);
    tempPoint.coordinate[2] = myPoint.coordinate[2] + (tempC*t);
    return tempPoint;
  }

  bool ThreeDGraph_class::present(vector<point> myList, string myLabel){
    long leng = myList.size();
    for(int i = 0;i<leng;i++){
      if(myList[i].label == myLabel){
        return true;
      }
    }
    return false;
  }

  Mat ThreeDGraph_class::createMatrix(){
    Mat tempMatrix;
    for(int i = 0;i<4;i++){
      Vec row;
      for (int j = 0; j < 4; j++)
      {
        if (i == j)
        {
          row.push_back(1);
        }else{
          row.push_back(0);
        }
      }
      tempMatrix.push_back(row);
    }
    return tempMatrix;
  }

  void ThreeDGraph_class::specificRotation(float angle, int choiceAxis, Vec Aline, bool GraphOrLine, bool ThreeDGraphOrPlaneProj){
    if(choiceAxis == 0){
      matrix[0][1][1] = cos(angle);
      matrix[0][2][2] = cos(angle);
      matrix[0][2][1] = sin(angle);
      matrix[0][1][2] = -1.0*sin(angle);
    }else if(choiceAxis == 1){
      matrix[1][0][0] = cos(angle);
      matrix[1][2][2] = cos(angle);
      matrix[1][0][2] = sin(angle);
      matrix[1][2][0] = -1.0*sin(angle);
    }else{
      matrix[2][1][1] = cos(angle);
      matrix[2][0][0] = cos(angle);
      matrix[2][1][0] = sin(angle);
      matrix[2][0][1] = -1.0*sin(angle);
    }
    if(GraphOrLine){
      long totalPoints;
      if (ThreeDGraphOrPlaneProj)
      {
        totalPoints = listOfPoints.size();
      }else{
        totalPoints = listOfPointsForPlane.size();
      }
      for(int i = 0; i < totalPoints; ++i){
        vector<point> tempList;
        if(ThreeDGraphOrPlaneProj){
          tempList = ThreeDGraph[listOfPoints[i]];
        }else{
          tempList = PlaneProj[listOfPointsForPlane[i]];
        }
        long tempsiz = tempList.size();
        for (int j = 0; j < tempsiz; j++){
          Vec tempVec;
          tempVec.push_back(tempList[j].coordinate[0]);
          tempVec.push_back(tempList[j].coordinate[1]);
          tempVec.push_back(tempList[j].coordinate[2]);
          tempVec.push_back(1);
          tempVec = matrix[choiceAxis]*tempVec;
          if(ThreeDGraphOrPlaneProj){
            ThreeDGraph[listOfPoints[i]][j].coordinate[0] = tempVec[0];
            ThreeDGraph[listOfPoints[i]][j].coordinate[1] = tempVec[1];
            ThreeDGraph[listOfPoints[i]][j].coordinate[2] = tempVec[2];
          }else{
            PlaneProj[listOfPointsForPlane[i]][j].coordinate[0] = tempVec[0];
            PlaneProj[listOfPointsForPlane[i]][j].coordinate[1] = tempVec[1];
            PlaneProj[listOfPointsForPlane[i]][j].coordinate[2] = tempVec[2];
          }
        }
      }
    }else{
      if(ThreeDGraphOrPlaneProj){
        tempLineVect = matrix[choiceAxis]*Aline;
      }else{
        tempLineVectForPlane = matrix[choiceAxis]*Aline;
      }
    }
  }

  point ThreeDGraph_class::getIntersect(edge my1, edge my2, int GraphNum, int lab){
  	float x1 = my1.p1.coordinate[(GraphNum+1)%3];	
  	float y1 = my1.p1.coordinate[(GraphNum+2)%3];

  	float x2 = my1.p2.coordinate[(GraphNum+1)%3];	
  	float y2 = my1.p2.coordinate[(GraphNum+2)%3];

  	float a1 = y2-y1;
  	float b1 = x1-x2;
  	float c1 = (a1*x1) + (y1*b1);


  	float xx1 = my2.p1.coordinate[(GraphNum+1)%3];	
  	float yy1 = my2.p1.coordinate[(GraphNum+2)%3];

  	float xx2 = my2.p2.coordinate[(GraphNum+1)%3];	
  	float yy2 = my2.p2.coordinate[(GraphNum+2)%3];

  	float a2 = yy2-yy1;
  	float b2 = xx1-xx2;
  	float c2 = (a2*xx1) + (yy1*b2);

  	point temp;
  	temp.coordinate[GraphNum] = 0;
  	float denom = a1*b2 - a2*b1;
  	if(denom >= .00001){
	  	temp.coordinate[(GraphNum+1)%3] = (c1*b2 - c2*b1)/denom;
	  	temp.coordinate[(GraphNum+2)%3] = -1.0*((c1*a2 - c2*a1)/denom);
  	}
	if((((my1.p1.coordinate[(GraphNum+1)%3]) - (temp.coordinate[(GraphNum+1)%3])) <= .00001) && (((my1.p1.coordinate[(GraphNum+2)%3]) - (temp.coordinate[(GraphNum+2)%3])) <= .00001)){
		temp.label = my1.p1.label;
	}else if((((my1.p2.coordinate[(GraphNum+1)%3]) - (temp.coordinate[(GraphNum+1)%3])) <= .00001) && (((my1.p2.coordinate[(GraphNum+2)%3]) - (temp.coordinate[(GraphNum+2)%3])) <= .00001)){
		temp.label = my1.p2.label;
	}else if((((my2.p2.coordinate[(GraphNum+1)%3]) - (temp.coordinate[(GraphNum+1)%3])) <= .00001) && (((my2.p2.coordinate[(GraphNum+2)%3]) - (temp.coordinate[(GraphNum+2)%3])) <= .00001)){
		temp.label = my2.p2.label;
	}else if((((my2.p1.coordinate[(GraphNum+1)%3]) - (temp.coordinate[(GraphNum+1)%3])) <= .00001) && (((my2.p1.coordinate[(GraphNum+2)%3]) - (temp.coordinate[(GraphNum+2)%3])) <= .00001)){
		temp.label = my2.p1.label;
	}else{
		temp.label = "Point " + lab;
	}
  	
  	return temp;
  }

  bool ThreeDGraph_class::onSegment(point p, point q, point r, int GraphNum){
    if (q.coordinate[(GraphNum+1)%3] <= max(p.coordinate[(GraphNum+1)%3], r.coordinate[(GraphNum+1)%3]) && q.coordinate[(GraphNum+1)%3] >= min(p.coordinate[(GraphNum+1)%3], r.coordinate[(GraphNum+1)%3]) &&
            q.coordinate[(GraphNum+2)%3] <= max(p.coordinate[(GraphNum+2)%3], r.coordinate[(GraphNum+2)%3]) && q.coordinate[(GraphNum+2)%3] >= min(p.coordinate[(GraphNum+2)%3], r.coordinate[(GraphNum+2)%3]))
        return true;
    return false;
  }

  int ThreeDGraph_class::orientation(point p, point q, point r, int GraphNum){
    int val = (q.coordinate[(GraphNum+2)%3] - p.coordinate[(GraphNum+2)%3]) * (r.coordinate[(GraphNum+1)%3] - q.coordinate[(GraphNum+1)%3]) - (q.coordinate[(GraphNum+1)%3] - p.coordinate[(GraphNum+1)%3]) * (r.coordinate[(GraphNum+2)%3] - q.coordinate[(GraphNum+2)%3]);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
  }

  bool ThreeDGraph_class::doIntersect(edge a1, edge a2, int GraphNum){
    // Find the four orientations needed for general and
    // special cases
    point p1 = a1.p1;
    point q1 = a1.p2;
    point p2 = a2.p1;
    point q2 = a2.p2;
    int o1 = orientation(p1, q1, p2, GraphNum);
    int o2 = orientation(p1, q1, q2, GraphNum);
    int o3 = orientation(p2, q2, p1, GraphNum);
    int o4 = orientation(p2, q2, q1, GraphNum);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1, GraphNum)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1, GraphNum)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2, GraphNum)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2, GraphNum)) return true;
 
    return false; // Doesn't fall in any of the above cases
  }

  bool ThreeDGraph_class::isInside(vector<edge> face, point p, int GraphNum){
  	long n = face.size();
  	// There must be at least 3 vertices in face
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    point extreme;
 	extreme.coordinate[GraphNum] = 0;
 	extreme.coordinate[(GraphNum+1)%3] = INF;
 	extreme.coordinate[(GraphNum+2)%3] = p.coordinate[(GraphNum+2)%3];
    
 	p.coordinate[GraphNum] = 0;
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%(n);
 		face[i].p1.coordinate[GraphNum] = 0;
 		face[i].p2.coordinate[GraphNum] = 0;
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'face[i].p1' to 'face[i].p2'
        edge tempEdge; tempEdge.p1 = face[i].p1; tempEdge.p2 = face[i].p2;
        edge tempEdge2; tempEdge2.p1 = p; tempEdge2.p2 = extreme;
        if (doIntersect(tempEdge, tempEdge2, GraphNum))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            
            if (orientation(face[i].p1, p, face[i].p2, GraphNum) == 0)
               return onSegment(face[i].p1, p, face[i].p2, GraphNum);
 			// return true;
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)	
  }

  void ThreeDGraph_class::InitialiseLookupForHidden3D(bool IsoOr3D){
  	LookupForHidden3D.clear();
	  if(IsoOr3D){	
		for (map<string, vector<point> >::iterator it=ThreeDGraph.begin(); it!=ThreeDGraph.end(); ++it){
		    long len = it->second.size();
		    for(int j=0;j<len;j++){
		        LookupForHidden3D[it->first].push_back(false);
		    }
		}
	  }else{
		for (map<string, vector<point> >::iterator it=IsometricGraph.begin(); it!=IsometricGraph.end(); ++it){
		    long len = it->second.size();
		    for(int j=0;j<len;j++){
		        LookupForHidden3D[it->first].push_back(false);
		    }
		}
	  }
  }

  bool ThreeDGraph_class::lieOnLine(point p, edge a, int GraphNum){
  	  	float x1 = a.p1.coordinate[(GraphNum+1)%3];	
	  	float y1 = a.p1.coordinate[(GraphNum+2)%3];

	  	float x2 = a.p2.coordinate[(GraphNum+1)%3];	
	  	float y2 = a.p2.coordinate[(GraphNum+2)%3];

	  	float a1 = y2-y1;
	  	float b1 = x1-x2;
	  	float c1 = (a1*x1) + (y1*b1);
	  	float nearZ = a1*p.coordinate[(GraphNum+1)%3] + b1*p.coordinate[(GraphNum+2)%3] - c1;
	  	if(nearZ <= 0.001){
	  		return true;
	  	}else{
	  		return false;
	  	}
  }

  float ThreeDGraph_class::distancePts(point a, point b, int GraphNum){
  	float dist = sqrt(pow((a.coordinate[(GraphNum+1)%3] - b.coordinate[(GraphNum+1)%3]),2)+pow((a.coordinate[(GraphNum+2)%3] - b.coordinate[(GraphNum+2)%3]),2));
  	return dist;
  }

  bool ThreeDGraph_class::planeBehindOrFront(point p, vector<edge> face, int GraphNum){
  	// true means behind
  	float x1 = face[0].p1.coordinate[0];
  	float y1 = face[0].p1.coordinate[1];
  	float z1 = face[0].p1.coordinate[2];

  	float x2 = face[0].p2.coordinate[0];
  	float y2 = face[0].p2.coordinate[1];
  	float z2 = face[0].p2.coordinate[2];

  	float x3 = face[1].p2.coordinate[0];
  	float y3 = face[1].p2.coordinate[1];
  	float z3 = face[1].p2.coordinate[2];

  	float a = (y2-y1)*(z3-z1) - (z2-z1)*(y3-y1);
  	float b = -1*((x2-x1)*(z3-z1) - (z2-z1)*(x3-x1));
  	float c = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
  	float d = a*x1 + b*y1 + c*z1;

  	float ans1 = a*p.coordinate[0] + b*p.coordinate[1] + c*p.coordinate[2] - d;
  	p.coordinate[GraphNum] = -1000000;
  	float ans2 = a*p.coordinate[0] + b*p.coordinate[1] + c*p.coordinate[2] - d;
  	float finalAns;
  	if((ans1 >= 5) || (ans1 <= -5)){
  		finalAns = ans2/ans1;
  	}else{
  		return false;
  	}
  	if((GraphNum == 0) && ((a <= 0.00001) && (a >= -0.00001))){
  		return false;
  	}else if((GraphNum == 1) && ((b <= 0.00001) && (b >= -0.00001))){
  		return false;
  	}else if((GraphNum == 2) && ((c <= 0.00001) && (c >= -0.00001))){
  		return false;
  	}else if((finalAns > 0.1)){
  		return true;
  	}else{
  		return false;
  	}
  }

 // will make listOfPointsForOrthographic, ThreeDGraphForOrthographic, LookupForHidden3D
  void ThreeDGraph_class::classifyHiddenEdge(int GraphNum, bool IsoOr3D){
	InitialiseLookupForHidden3D(IsoOr3D);
	long NoOfFaces = FaceGraph.size();
	for (int i = 0; i < signed(listOfPointsForOrthographic.size()); i++){
	  	for(int j = 0;j<NoOfFaces;j++){
	  		/*For all points traverse their neighbours*/
	  		point myPoint;
	  		if (IsoOr3D){
	  			myPoint = ThreeDGraphForOrthographic[listOfPointsForOrthographic[i]][0];	  			
	  		}else{
	  			myPoint = IsometricGraph[listOfPoints[i]][0];	  			
	  		}
	  		
	  		/*check whether myPoint is inside or outside*/
	  		bool inside = isInside(FaceGraph[j], myPoint, GraphNum);
	  		bool behind = planeBehindOrFront(myPoint, FaceGraph[j], GraphNum);
			vector<point> tempPoints;
	  		if (IsoOr3D){
	  			tempPoints = ThreeDGraph[myPoint.label];
	  		}else{
	  			tempPoints = IsometricGraph[myPoint.label];
	  		}
	  		
	  		long tempSize = tempPoints.size();
			if(inside && behind){  	
		  		for(int k = 1;k<tempSize;k++){
		  			LookupForHidden3D[myPoint.label][k] = true;

		  			long temptempSize;
	  				vector<point> temptempPoints;
		  			if(IsoOr3D){
			  			temptempSize = ThreeDGraph[tempPoints[k].label].size();
		  				temptempPoints = ThreeDGraph[tempPoints[k].label];
		  			}else{
			  			temptempSize = IsometricGraph[tempPoints[k].label].size();
		  				temptempPoints = IsometricGraph[tempPoints[k].label];
		  			}
		  			for(int m = 1;m<temptempSize;m++){
		  				if((temptempPoints[m].label == myPoint.label)){
							LookupForHidden3D[tempPoints[k].label][m] = true;
		  				}		  			
		  			}
		  		}
	  		}
	  	}	
	  }
  }

  void ThreeDGraph_class::FaceRecognition(bool ch){
  	FaceGraph.clear();
    FaceGraph = getPolygons(ch);
  }

// Public functions
  ThreeDGraph_class::ThreeDGraph_class(){
    matrix[0] = createMatrix();
    matrix[1] = createMatrix();
    matrix[2] = createMatrix();
    matrixA = createMatrix();
    matrixB = createMatrix();
    matrixA[1][1] = cos(35.264*PI/180);
    matrixA[1][2] = sin(35.264*PI/180);
    matrixA[2][1] = -1*sin(35.264*PI/180);
    matrixA[1][1] = cos(35.264*PI/180);

    matrixB[0][0] = cos(45*PI/180);
    matrixB[2][0] = sin(45*PI/180);
    matrixB[0][2] = -1*sin(45*PI/180);
    matrixB[2][2] = cos(45*PI/180);
  }

  bool ThreeDGraph_class::checkSamePlane(point p1, point p2, point p3, point p4){
      //returns whether they are in the same plane or not
      bool ne = !(p1==p2) && !(p2==p3) && !(p3==p4) && !(p1==p3) && !(p2==p4); 
      float a = p2.coordinate[0]-p1.coordinate[0];
      float b = p2.coordinate[1]-p1.coordinate[1];
      float c = p2.coordinate[2]-p1.coordinate[2];
      float p = p4.coordinate[0]-p3.coordinate[0];
      float q = p4.coordinate[1]-p3.coordinate[1];
      float r = p4.coordinate[2]-p3.coordinate[2];

      float cpx = b*r-q*c;
      float cpy = c*p-r*a;
      float cpz = a*q-p*b;
      float diffx = p1.coordinate[0]-p4.coordinate[0];
      float diffy = p1.coordinate[1]-p4.coordinate[1];
      float diffz = p1.coordinate[2]-p4.coordinate[2];

      if(fabs(diffx*cpx+diffy*cpy+diffz*cpz)<5 && ne) return true;
      else return false;


    }

  vector<vector<edge> > ThreeDGraph_class::getPolygons(bool ch){
      edge a1;
      vector<plane> listOfPlanes;
      vector<vector<edge> > toReturn;
      map<string, vector<point> > iterateOver;
      if (ch){
        iterateOver = ThreeDGraph;
      }else{
        iterateOver = IsometricGraph;
      }
    
      for (std::map<string, vector<point> >::iterator it=iterateOver.begin(); it!=iterateOver.end(); ++it){
        for(int i=1;i<signed(it->second.size());i++){
          for(int j=1;j<signed(iterateOver[it->second[i].label].size());j++){
            for(int k=1;k<signed(iterateOver[iterateOver[it->second[i].label][j].label].size());k++){
              point p1 = it->second[0];
              point p2 = it->second[i];
              point p3 = iterateOver[it->second[i].label][j];
              point p4 = iterateOver[iterateOver[it->second[i].label][j].label][k];
    
              if(checkSamePlane(p1,p2,p3,p4)){
                //add to planes 
                
                int ind=0;
                for(;ind<signed(listOfPlanes.size());ind++){
                  float v1 = listOfPlanes[ind].A*p1.coordinate[0] + listOfPlanes[ind].B*p1.coordinate[1] + listOfPlanes[ind].C*p1.coordinate[2] - listOfPlanes[ind].D;
                  float v2 = listOfPlanes[ind].A*p2.coordinate[0] + listOfPlanes[ind].B*p2.coordinate[1] + listOfPlanes[ind].C*p2.coordinate[2] - listOfPlanes[ind].D;
                  float v3 = listOfPlanes[ind].A*p3.coordinate[0] + listOfPlanes[ind].B*p3.coordinate[1] + listOfPlanes[ind].C*p3.coordinate[2] - listOfPlanes[ind].D;
                  float v4 = listOfPlanes[ind].A*p4.coordinate[0] + listOfPlanes[ind].B*p4.coordinate[1] + listOfPlanes[ind].C*p4.coordinate[2] - listOfPlanes[ind].D;
                  if((v1>-5) && (v1<5) && (v2>-5) && (v2<5) && (v3>-5) && (v3<5) && (v4>-5) && (v4<5)) break;
                }
                if(ind<signed(listOfPlanes.size())){
                  a1.p1 = p3;
                  a1.p2 = p4;
                  bool flag = false;
                  for(int t=0;t<signed(toReturn[ind].size());t++){
                    if(a1==toReturn[ind][t]){
                      flag=true;
                      break;
                    } 
                  }
                  if (flag==false)
                    toReturn[ind].push_back(a1);
                }
                else{
                  float a =p1.coordinate[0]-p2.coordinate[0];
                  float b =p1.coordinate[1]-p2.coordinate[1];
                  float c =p1.coordinate[2]-p2.coordinate[2];
                  float p =p1.coordinate[0]-p3.coordinate[0];
                  float q =p1.coordinate[1]-p3.coordinate[1];
                  float r =p1.coordinate[2]-p3.coordinate[2];
                  plane Pla1;
                  Pla1.A = b*r-q*c;
                  Pla1.B = c*p-r*a;
                  Pla1.C = a*q-p*b;
                  Pla1.D = Pla1.A*p1.coordinate[0]+Pla1.B*p1.coordinate[1]+Pla1.C*p1.coordinate[2];
                
                  listOfPlanes.push_back(Pla1);
                  vector<edge> newPlane;
                  a1.p1 = p1;
                  a1.p2 = p2;
                  newPlane.push_back(a1);
                  a1.p1 = p2;
                  a1.p2 = p3;
                  newPlane.push_back(a1);
                  a1.p1 = p3;
                  a1.p2 = p4;
                  newPlane.push_back(a1);
                  toReturn.push_back(newPlane);
               } 
              }
            }
          }
        }
      }
      return toReturn;
    }
    
  void ThreeDGraph_class::GraphToList(bool ThreeDGraphOrPlaneProj){
    if(ThreeDGraphOrPlaneProj){
      listOfPoints.clear();
      for (std::map<string, vector<point> >::iterator it=ThreeDGraph.begin(); it!=ThreeDGraph.end(); ++it){
        listOfPoints.push_back(it->first);
      }
    }else{
      listOfPointsForPlane.clear();
      for (std::map<string, vector<point> >::iterator it=PlaneProj.begin(); it!=PlaneProj.end(); ++it){
        listOfPointsForPlane.push_back(it->first);
      }
    }
  }

  void ThreeDGraph_class::Scaling(float ScaleFactor){
    long siz = listOfPoints.size();
    for(int i = 0; i<siz; i++){
      vector<point> temp = ThreeDGraph[listOfPoints[i]];
      long tempsiz = temp.size();
      for (int j = 0; j < tempsiz; j++)
      {
        ThreeDGraph[listOfPoints[i]][j].coordinate[0] = temp[j].coordinate[0]*ScaleFactor;
        ThreeDGraph[listOfPoints[i]][j].coordinate[1] = temp[j].coordinate[1]*ScaleFactor;
        ThreeDGraph[listOfPoints[i]][j].coordinate[2] = temp[j].coordinate[2]*ScaleFactor;
      }
    }
  }

  void ThreeDGraph_class::Translation(float x, float y, float z,edge line, bool GraphOrLine){
    if (GraphOrLine){ // if true then graph else axis
      long siz = listOfPoints.size();
      for(int i = 0; i<siz; i++){
        vector<point> temp = ThreeDGraph[listOfPoints[i]];
        long tempsiz = temp.size();
        for (int j = 0; j < tempsiz; j++)
        {
          ThreeDGraph[listOfPoints[i]][j].coordinate[0] = temp[j].coordinate[0] - x;
          ThreeDGraph[listOfPoints[i]][j].coordinate[1] = temp[j].coordinate[1] - y;
          ThreeDGraph[listOfPoints[i]][j].coordinate[2] = temp[j].coordinate[2] - z;
        }
      }
    }else{
      tempLineAns.p1.coordinate[0] = line.p1.coordinate[0] - x;
      tempLineAns.p1.coordinate[1] = line.p1.coordinate[1] - y;
      tempLineAns.p1.coordinate[2] = line.p1.coordinate[2] - z;

      tempLineAns.p2.coordinate[0] = line.p2.coordinate[0] - x;
      tempLineAns.p2.coordinate[1] = line.p2.coordinate[1] - y;
      tempLineAns.p2.coordinate[2] = line.p2.coordinate[2] - z;
    }
  }

  void ThreeDGraph_class::ModelRotation(float angle, edge axis){
    if (angle!=0){
      angle = angle*(PI/180);
      Translation(axis.p1.coordinate[0], axis.p1.coordinate[1], axis.p1.coordinate[2], axis, false);
      Translation(axis.p1.coordinate[0], axis.p1.coordinate[1], axis.p1.coordinate[2], axis, true);
      tempLineVect.clear();
      tempLineVect.push_back(tempLineAns.p2.coordinate[0]);
      tempLineVect.push_back(tempLineAns.p2.coordinate[1]);
      tempLineVect.push_back(tempLineAns.p2.coordinate[2]);
      tempLineVect.push_back(1);

      // calculate angleX
      float angleX;
      if(tempLineVect[2] != 0){
        angleX = (atan(tempLineVect[1]/tempLineVect[2])); // angleX = y/z
      }else{
        angleX = PI/2;
      }
      specificRotation(angleX,0,tempLineVect,false,true);
      specificRotation(angleX,0,tempLineVect,true,true);
      
      // calculate angleY
      float angleY;
      if(tempLineVect[2] != 0){
        angleY = (atan(tempLineVect[0]/tempLineVect[2])); // angleY = x/z
      }else{
        angleY = -1*PI/2;
      }
      specificRotation(angleY,1,tempLineVect,false,true);
      specificRotation(angleY,1,tempLineVect,true,true);

      specificRotation(angle,2,tempLineVect,true,true);
    
      // Inverse Transformations
      tempLineVect.clear();
      specificRotation(-1*angleY,1,tempLineVect,true,true);
      specificRotation(-1*angleX,0,tempLineVect,true,true);
      Translation(-1*axis.p1.coordinate[0], -1*axis.p1.coordinate[1], -1*axis.p1.coordinate[2], tempLineAns, true);
    }
  }

  void ThreeDGraph_class::MeanNormalisation(){
    long siz = listOfPoints.size();
    float meanx = 0;
    float meany = 0;
    float meanz = 0;
    float maxX = -100000000, minX = 100000000;
    float maxY = -100000000, minY = 100000000;
    float maxZ = -100000000, minZ = 100000000;
    for(int i = 0; i<siz; i++){
      point temp = ThreeDGraph[listOfPoints[i]][0];
      meanx += temp.coordinate[0];
      meany += temp.coordinate[1];
      meanz += temp.coordinate[2];
      if(temp.coordinate[0] > maxX){
        maxX = temp.coordinate[0];
      }
      if(temp.coordinate[1] > maxY){
        maxY = temp.coordinate[1];
      }
      if(temp.coordinate[2] > maxZ){
        maxZ = temp.coordinate[2];
      }
      if(temp.coordinate[0] < minX){
        minX = temp.coordinate[0];
      }
      if(temp.coordinate[1] < minY){
        minY = temp.coordinate[1];
      }
      if(temp.coordinate[2] < minZ){
        minZ = temp.coordinate[2];
      }
    }
    float MaxDist = -10000000;
    if((maxX - minX) > (maxY - minY)){
      if((maxX - minX) > (maxZ - minZ)){
        MaxDist = (maxX - minX);
      }else{
        MaxDist = (maxZ - minZ);
      }
    }else if((maxY - minY) > (maxZ - minZ)){
        MaxDist = (maxY - minY);
    }else{
        MaxDist = (maxZ - minZ);
    }
    float factor = 170/MaxDist;
    meanx = float(meanx/siz);
    meany = float(meany/siz);
    meanz = float(meanz/siz);
    for(int i = 0; i<siz; i++){
      vector<point> temp = ThreeDGraph[listOfPoints[i]];
      long tempsiz = temp.size();
      for (int j = 0; j < tempsiz; j++)
      {
        ThreeDGraph[listOfPoints[i]][j].coordinate[0] = temp[j].coordinate[0] - meanx;
        ThreeDGraph[listOfPoints[i]][j].coordinate[1] = temp[j].coordinate[1] - meany;
        ThreeDGraph[listOfPoints[i]][j].coordinate[2] = temp[j].coordinate[2] - meanz;
      }
    }
    Scaling(factor);
  }

  void ThreeDGraph_class::Isometric(){
    long totalPoints;
    IsometricGraph = ThreeDGraph;
    totalPoints = listOfPoints.size();
    for(int i = 0; i < totalPoints; ++i){
      vector<point> tempList;
      tempList = IsometricGraph[listOfPoints[i]];
      long tempsiz = tempList.size();
      for (int j = 0; j < tempsiz; j++){
        Vec tempVec;
        tempVec.push_back(tempList[j].coordinate[0]);
        tempVec.push_back(tempList[j].coordinate[1]);
        tempVec.push_back(tempList[j].coordinate[2]);
        tempVec.push_back(1);
        tempVec = matrixB*tempVec;
        tempVec = matrixA*tempVec;
        IsometricGraph[listOfPoints[i]][j].coordinate[0] = tempVec[0];
        IsometricGraph[listOfPoints[i]][j].coordinate[1] = tempVec[1];
        IsometricGraph[listOfPoints[i]][j].coordinate[2] = tempVec[2];
      }
    }
    FaceRecognition(false);
    classifyHiddenEdge(2, false);
  }

  map<string, vector<point> > ThreeDGraph_class::PlanarProjection(plane equationOfPlane){
    InitialiseLookupForHidden3D(true);
    map<string, vector<point> > tempProj;
    
    long siz = listOfPoints.size();
    for(int i = 0; i<siz; i++){
      vector<point> temp = ThreeDGraph[listOfPoints[i]];
      long tempsiz = temp.size();
      
      struct point myPoint = temp[0];
      // if there is any other point in the list
      if(tempsiz > 1){
      
        // Get combined Label
        string tempLabel = GetLabel1(myPoint, equationOfPlane);
        // cout << tempLabel << " HIHI" << endl;
        // If that label is not present already
        if(tempProj.count(tempLabel) == 0){
          // change my label
          point modPoint = pointProj(myPoint, equationOfPlane);
          myPoint.coordinate[0] = modPoint.coordinate[0];
          myPoint.coordinate[1] = modPoint.coordinate[1];
          myPoint.coordinate[2] = modPoint.coordinate[2];
          myPoint.label = tempLabel;
          // Insert me in graph first
          tempProj[myPoint.label].push_back(myPoint);
          // Iterate over my neighbours
          for(int j = 1;j<tempsiz;j++){
            // Project coordinate on plane
            modPoint = pointProj(temp[j],equationOfPlane);
            float tempA = modPoint.coordinate[0];
            float tempB = modPoint.coordinate[1];
            float tempC = modPoint.coordinate[2];

            // for All my non overlapping neighbours
            if((abs(tempA - (myPoint.coordinate[0]))>= ERRORMARGIN)||(abs(tempB - (myPoint.coordinate[1]))>= ERRORMARGIN)||(abs(tempC - (myPoint.coordinate[2]))>= ERRORMARGIN)){
              
              // Check with what all points do they overlapp and get label
              temp[j].label = GetLabel1(temp[j], equationOfPlane);
              // If that combined label is not present already then add else join edge with pre existing label
              if(tempProj.count(temp[j].label) == 0){
                temp[j].coordinate[0] = tempA;
                temp[j].coordinate[1] = tempB;
                temp[j].coordinate[2] = tempC;
                if(!present(tempProj[myPoint.label], temp[j].label)){
                  tempProj[myPoint.label].push_back(temp[j]);
                }
              }else{
                if(!present(tempProj[myPoint.label], temp[j].label)){
                  tempProj[myPoint.label].push_back(tempProj[temp[j].label][0]);
                }
              }
            }
          }
        }
      }
    }
    tempLineVectForPlane.clear();
    tempLineVectForPlane.push_back(equationOfPlane.A);
    tempLineVectForPlane.push_back(equationOfPlane.B);
    tempLineVectForPlane.push_back(equationOfPlane.C);
    tempLineVectForPlane.push_back(1);

    PlaneProj = tempProj;
    GraphToList(false);

    // calculate angleX
    float angleX = (atan(equationOfPlane.B/equationOfPlane.C)); // angleX = y/z
    specificRotation(angleX,0,tempLineVectForPlane,false,false);
    specificRotation(angleX,0,tempLineVectForPlane,true,false);
    
    // calculate angleY
    float angleY = -1*(atan(tempLineVectForPlane[0]/tempLineVectForPlane[2])); // angleY = x/z
    specificRotation(angleY,1,tempLineVectForPlane,true,false);

    tempProj = PlaneProj;
    return tempProj;
  }

  void ThreeDGraph_class::ThreeDToOrthographic(){
    LookupForHidden2D[0].clear();
    LookupForHidden2D[1].clear();
    LookupForHidden2D[2].clear();
    FaceRecognition(true);
    // MeanNormalisation();
    TwoDGraph[0].clear();
    TwoDGraph[1].clear();
    TwoDGraph[2].clear();
    for(int GraphNo = 0; GraphNo<3;GraphNo++){
	  ThreeDGraphForOrthographic = ThreeDGraph;
	  listOfPointsForOrthographic = listOfPoints;
	  classifyHiddenEdge(GraphNo, true); // will make listOfPointsForOrthographic, ThreeDGraphForOrthographic, LookupForHidden3D
      long length = listOfPoints.size();
      // TwoDGraph[0] is graph with x = 0 -> Y-Z plane
      // TwoDGraph[1] is graph with y = 0 -> X-Z plane
      // TwoDGraph[2] is graph with z = 0 -> X-Y plane
      for(int i = 0;i<length;i++){
        // Iterate over all points
        vector<point> tempPoints = ThreeDGraphForOrthographic[listOfPoints[i]];
        long tempSize = tempPoints.size();
        struct point myPoint = tempPoints[0];
        // if there is any other point in the list
        if(tempSize > 1){
        
          // Get combined Label
          string originalLabel = myPoint.label;
          string tempLabel = GetLabel(myPoint, GraphNo);
          
            // change my label
            myPoint.label = tempLabel;
            myPoint.coordinate[GraphNo] = 0;
            // Insert me in graph first
            TwoDGraph[GraphNo][myPoint.label].push_back(myPoint);
            LookupForHidden2D[GraphNo][myPoint.label].push_back(true);
            // Iterate over my neighbours
            for(int j = 1;j<tempSize;j++){
              
              // for All my non overlapping neighbours
              if((abs(((tempPoints[j].coordinate[(GraphNo+1)%3]) - (myPoint.coordinate[(GraphNo+1)%3])))>= ERRORMARGIN)||(abs(((tempPoints[j].coordinate[(GraphNo+2)%3]) - (myPoint.coordinate[(GraphNo+2)%3])))>= ERRORMARGIN)){
                
                // Check with what all points do they overlapp and get label
                tempPoints[j].label = GetLabel(tempPoints[j], GraphNo);
                // Reduce coordinate to 0
                tempPoints[j].coordinate[GraphNo] = 0;
            
                // If that combined label is not present already then add else join edge with pre existing label
                if(TwoDGraph[GraphNo].count(tempPoints[j].label) == 0){
                  if(!present(TwoDGraph[GraphNo][myPoint.label], tempPoints[j].label)){
                    TwoDGraph[GraphNo][myPoint.label].push_back(tempPoints[j]);
                    
                    bool val = true;
              			vector<string> keys;
        		        string s = tempPoints[j].label;
      			        string delimiter = "^";
      			        size_t pos = s.find(delimiter);
      			        string token;
      			        token = s.substr(0, pos);
      			        keys.push_back(token);
  	                s.erase(0, pos + delimiter.length());
      			        string a11 = token;
      			        keys.clear();

        		        s = myPoint.label;
      			        pos = s.find(delimiter);
      			        token = "";
    		            token = s.substr(0, pos);
    		            keys.push_back(token);
    		            s.erase(0, pos + delimiter.length());
      			        string a22 = token;

      			        for(int z = 0;z<signed(ThreeDGraph[a22].size());z++){
      			        	if(ThreeDGraph[a22][z].label == a11){
      			        		val = LookupForHidden3D[a22][z];
      			        	}
      			        }
                    LookupForHidden2D[GraphNo][myPoint.label].push_back(val);
                  }
                }else{
                  if(!present(TwoDGraph[GraphNo][myPoint.label], tempPoints[j].label)){
                    TwoDGraph[GraphNo][myPoint.label].push_back(TwoDGraph[GraphNo][tempPoints[j].label][0]);             
           					bool val = true;
                			vector<string> keys;
          		        string s = tempPoints[j].label;
        			        string delimiter = "^";
        			        size_t pos = s.find(delimiter);
        			        string token;
      		            token = s.substr(0, pos);
      		            keys.push_back(token);
      		            s.erase(0, pos + delimiter.length());
        			        string a11 = token;
        			        keys.clear();

          		        s = myPoint.label;
        			        pos = s.find(delimiter);
        			        token = "";
      		            token = s.substr(0, pos);
      		            keys.push_back(token);
      		            s.erase(0, pos + delimiter.length());
      		            string a22 = token;

        			        for(int z = 0;z<signed(ThreeDGraph[a22].size());z++){
        			        	if(ThreeDGraph[a22][z].label == a11){
        			        		val = LookupForHidden3D[a22][z];
        			        	}
        			        }
                    LookupForHidden2D[GraphNo][myPoint.label].push_back(val);
                  }
                }
              }
        	}
        }
      }
    }
  }

  void ThreeDGraph_class::print(){
    for (std::map<string, vector<point> >::iterator it=TwoDGraph[0].begin(); it!=TwoDGraph[0].end(); ++it){
      cout<< it->first << " -> " << it->second[0].coordinate[0] << " " << it->second[0].coordinate[1] << " " << it->second[0].coordinate[2] << "->";
      cout<<endl;
    }
  }

  void ThreeDGraph_class::print3D(){
    for (std::map<string, vector<point> >::iterator it=ThreeDGraph.begin(); it!=ThreeDGraph.end(); ++it){
      cout<<it->first+"->";
      for(int j=0;j<signed(it->second.size());j++){
        cout<<it->second[j].print();
      }
      cout<<endl;
    }
  }