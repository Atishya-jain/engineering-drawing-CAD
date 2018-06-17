/*! \file */
#include <bits/stdc++.h>
#include "../Include/InputSrc.h"
#include "../Include/2DProcessingSrc.h"
#include "../Include/3DProcessingSrc.h"
#include "../Include/structs.h"
using namespace std;

/*! \class Input
    \brief Input class.

    This class contains the methods to input content from a file etc..
*/

  /*!
     Will set the filename and type of file the user desires
     \param file a string argument containing the filename
     \param threeD a boolean argument containing the type of file
  */
  void Input::getFileName(string file, bool threeD){
    filename=file;
    ThreeDfile=threeD;
  }

  /*!
  	Will read the file user wants to input and process it to convert it into a graph to store the object
  */
  void Input::ReadFile(){
    string line;
      ifstream myfile (filename);
      if(myfile.is_open()){
        if(ThreeDfile){
          string nn;
          getline(myfile,nn);
          int n = stoi(nn);
          for(int i=0;i<n;i++){
            getline(myfile,nn);
            string pre = nn.substr(0,nn.find(" ->")-1);
            string post = nn.substr(nn.find(" ->")+3,nn.length()-nn.find(" ->")+3);
            vector<string> parts;
            //code to split the key into keys
            string s = pre;
            string delimiter = ",";
            size_t pos = 0;
            string token;
            while ((pos = s.find(delimiter)) != std::string::npos) {
                token = s.substr(0, pos);
                parts.push_back(token);
                s.erase(0, pos + delimiter.length());
            }
            parts.push_back(s);

            point tmp;
            tmp.label = parts[0];
            tmp.coordinate[0]=stof(parts[1]);
            tmp.coordinate[1]=stof(parts[2]);            
            tmp.coordinate[2]=stof(parts[3]);
            vector<point> tmp2;
            tmp2.push_back(tmp);
            ThreeDGraph[parts[0]]=tmp2;

            // code to split the key into keys
            vector<string> elems;
            s = post;
            delimiter = " ";
            pos = 0;
            while ((pos = s.find(delimiter)) != std::string::npos) {
              token = s.substr(0, pos);
              elems.push_back(token);
              s.erase(0, pos + delimiter.length());
            }
            for(int j=0;j<signed(elems.size());j++){
              vector<string> newParts;
              //code to split the key into keys
              string s2 = elems[j];
              string delimiter2 = ",";
              size_t pos2 = 0;
              string token2;
              while ((pos2 = s2.find(delimiter2)) != std::string::npos) {
                  token2 = s2.substr(0, pos2);
                  newParts.push_back(token2);
                  s2.erase(0, pos2 + delimiter2.length());
              }
              newParts.push_back(s2);

              tmp.label = newParts[0];
              tmp.coordinate[0]=stof(newParts[1]);
              tmp.coordinate[1]=stof(newParts[2]);            
              tmp.coordinate[2]=stof(newParts[3]);
              ThreeDGraph[parts[0]].push_back(tmp);
            }       
          }
        }else{
          for(int t=0;t<3;t++){
            string nn;
            getline(myfile,nn);
            int n = stoi(nn);
            for(int i=0;i<n;i++){
              getline(myfile,nn);
              string pre = nn.substr(0,nn.find(" ->")-1);
              string post = nn.substr(nn.find(" ->")+3,nn.length()-nn.find(" ->")+3);

              vector<string> parts;
              //code to split the key into keys
              string s = pre;
              string delimiter = ",";
              size_t pos = 0;
              string token;
              while ((pos = s.find(delimiter)) != std::string::npos) {
                  token = s.substr(0, pos);
                  parts.push_back(token);
                  s.erase(0, pos + delimiter.length());
              }
              parts.push_back(s);

              point tmp;
              tmp.label = parts[0];
              tmp.coordinate[0]=stof(parts[1]);
              tmp.coordinate[1]=stof(parts[2]);            
              tmp.coordinate[2]=stof(parts[3]);
              vector<point> tmp2;
              tmp2.push_back(tmp);
              TwoDGraph[t][parts[0]]=tmp2;

              //code to split the key into keys
              vector<string> elems;
              s = post;
              delimiter = " ";
              pos = 0;
              while ((pos = s.find(delimiter)) != std::string::npos) {
                token = s.substr(0, pos);
                elems.push_back(token);
                s.erase(0, pos + delimiter.length());
              }
              // elems.push_back(s);   
              for(int j=0;j<signed(elems.size());j++){
                vector<string> newParts;
                //code to split the key into keys
                string s2 = elems[j];
                string delimiter2 = ",";
                size_t pos2 = 0;
                string token2;
                while ((pos2 = s2.find(delimiter2)) != std::string::npos) {
                    token2 = s2.substr(0, pos2);
                    newParts.push_back(token2);
                    s2.erase(0, pos2 + delimiter2.length());
                }
                newParts.push_back(s2);

                tmp.label = newParts[0];
                tmp.coordinate[0]=stof(newParts[1]);
                tmp.coordinate[1]=stof(newParts[2]);            
                tmp.coordinate[2]=stof(newParts[3]);
                TwoDGraph[t][parts[0]].push_back(tmp);
              }       
            }

          }
        }
      }else{
        throw invalid_argument( "error in file" );
      }
    myfile.close();
  }

  /*!
  	Will print the 2D graph Y-Z projection on the terminal. Used mainly for debugging 
  */
  void Input::print(){
      for (std::map<string, vector<point> >::iterator it=TwoDGraph[0].begin(); it!=TwoDGraph[0].end(); ++it){
        cout<<it->first+"->";
        for(int j=0;j<signed(it->second.size());j++){
          cout<<it->second[j].label << " ";
        }
        cout<<endl;
      }
    }
  
  /*!
  	Will print the 3D graph on the terminal. Used mainly for debugging 
  */
   void Input::print3D(){
      for (std::map<string, vector<point> >::iterator it=ThreeDGraph.begin(); it!=ThreeDGraph.end(); ++it){
        cout<<it->first+"->";
        for(int j=0;j<signed(it->second.size());j++){
          cout<<it->second[j].print();
        }
        cout<<endl;
      }
    }
