#include<iostream>
#include "Rooms.h"
#include<map>
Rooms::Rooms(){
  map<char, char> maplist;
  //  maplist["1-20"] = "East";
  // for(map<string, char[30]>:: iterator it = maplist.begin(); it !=maplist.end(); i++){
  // cout << it.first <<  " " << it.second << endl;
  // }
  type = 1;

}

char* Rooms::getRoom(){
  if(type == 1){
    cout << "You are currently in the 1-20 lab at SUnset. All the cool people are hanging out here." << endl;
  }
  if(type == 2){
    cout << "You are currently in the Hall. You are getting pushed around, quickly exit the area" << endl;
  }
  return room;

}

void Rooms::getExits(){
  char input[5];
  if(type == 1){
    cout << "East" << endl;
    cout << "Where would you like to go?" << endl;
    cin.get(input, 5);
    cin.ignore();
    if(((strcmp(input, "East")) == 0)){
      type = 2;
     
    }
  }
}
