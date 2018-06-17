/*! \file */
#include <bits/stdc++.h>
#include "../Include/2DProcessingSrc.h"
#include "../Include/structs.h"
using namespace std;

/*! \class TwoDGraph_class
    \brief 2D behaviour class.

    This class has all the functionalities that a 2D object can possess
    in the software. It can be rotated and converted into isometric from 2 orthographic projections
    along some plane.  
*/


  
  //! A Member function.
  /*!
    \sa TwoDtoThreeD()
    \param filename a string argument.
    \param flag3Dfile boolean character to tell the type of file (3D/2D).
  */

void TwoDGraph_class::TwoDtoThreeD(){
    //write the code to convert 2d to 3d here
    map<string, point> pointsList;
    //getting the list of all points
    for(int i=0;i<3;i++){
      for(std::map<string, vector<point> >::iterator it=TwoDGraph[i].begin(); it!=TwoDGraph[i].end(); ++it){
        string key=it->first;
        vector<string> keys;

        //code to split the key into keys
        string s = key;
        string delimiter = "^";
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            keys.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        keys.push_back(s);
        for(int j=0;j<signed(keys.size());j++){
          if(i==0){
            pointsList[keys[j]]=it->second[0];
            pointsList[keys[j]].label=keys[j];
          }
          else if(i==1){
            if(abs(pointsList[keys[j]].coordinate[2]-it->second[0].coordinate[2])>0.0000001)
              throw invalid_argument( "error in file" );
            else
              pointsList[keys[j]].coordinate[0]=it->second[0].coordinate[0];
          }
          else{
            if(abs(pointsList[keys[j]].coordinate[0]-it->second[0].coordinate[0])>0.0000001||abs(pointsList[keys[j]].coordinate[1]-it->second[0].coordinate[1])>0.0000001)
              throw invalid_argument( "error in file" );
          }
        }
      }
    }
    for(int i=0;i<3;i++){
      for(std::map<string, vector<point> >::iterator it=TwoDGraph[i].begin(); it!=TwoDGraph[i].end(); ++it){
        string key=it->first;
        vector<string> keys;

        //code to split the key into keys
        string s = key;
        string delimiter = "^";
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
          token = s.substr(0, pos);
          keys.push_back(token);
          s.erase(0, pos + delimiter.length());
        }
        keys.push_back(s);
        for(int j=0;j<signed(keys.size());j++){
          if(i==0){
            vector<point> tmp;
            ThreeDGraph[keys[j]]=tmp;
          }
          ThreeDGraph[keys[j]].push_back(pointsList[keys[j]]);
          for(int k=0;k<signed(keys.size());k++){
            if(k==j) continue;
            ThreeDGraph[keys[j]].push_back(pointsList[keys[k]]);
          }
          for(int k=1;k<signed(it->second.size());k++){
            vector<string> sepKeys;

            //code to split the key into keys
            string s2 = it->second[k].label;
            string delimiter2 = "^";
            size_t pos2 = 0;
            string token2;
            while ((pos2 = s2.find(delimiter2)) != std::string::npos) {
                token2 = s2.substr(0, pos2);
                sepKeys.push_back(token2);
                s2.erase(0, pos2 + delimiter2.length());
            }
            sepKeys.push_back(s2);
            for(int l=0;l<signed(sepKeys.size());l++){
              ThreeDGraph[keys[j]].push_back(pointsList[sepKeys[l]]);
            }
          }
        }
      } 
    }
    for(std::map<string, vector<point> >::iterator it=ThreeDGraph.begin(); it!=ThreeDGraph.end(); ++it){
      vector<point> tmp;
      for(int i=0;i<signed(it->second.size());i++){
        int ct=0;
        for(int j=i+1;j<signed(it->second.size());j++)
          if (it->second[j]==it->second[i]) ct++;
        if(ct==2){
          tmp.push_back(it->second[i]);
        }
      }
      ThreeDGraph[it->first]=tmp;
    }
  }
void TwoDGraph_class::print3D(){
  for (std::map<string, vector<point> >::iterator it=ThreeDGraph.begin(); it!=ThreeDGraph.end(); ++it){
    cout<<it->first+"->";
    for(int j=0;j<signed(it->second.size());j++){
      cout<<it->second[j].print();
    }
    cout<<endl;
  }
}
