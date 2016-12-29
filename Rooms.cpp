#include<iostream>
#include "Rooms.h"
#include<map>

using namespace std;

Rooms::Rooms(const char* newDescription, vector<Rooms*>* roomList){
  description = strdup(newDescription);//puts description string on the heap and converts into a char* safely
  roomList->push_back(this);//pushing "this" as in the current pointer being worked on
  
  

}

Rooms::~Rooms(){
  delete description;

}



void Rooms::setExits(const char* exitName, Rooms* exitRoom){//create exit
  exits[exitName] = exitRoom;
  
}
void Rooms::printExits(){
  for(map<const char*, Rooms*>::iterator it = exits.begin(); it != exits.end(); it++){
    cout << (*it).first << endl;//prints out the first part of the map (second part would be the rooms that they go into
  }
}

void Rooms::printDescription(){
  cout << "You are " << description << endl;
  cout << "There is: " << endl;
  cout << "You can go: " << endl;
  printExits();
}

Rooms* Rooms::getExits(char* exitKey){
  map<const char*, Rooms*>::iterator it = exits.find(exitKey);
  if(it != exits.end()){
    return exits[exitKey];
  }
  else{
    return NULL;
  }  
}


Rooms* Rooms::goThruExit(){
  cout << "Where would you like to go?" << endl;
  cin.get(directioninput,30);
  
  for(map<const char*, Rooms*>::iterator it = exits.begin(); it != exits.end(); it++){
    if((strcmp(directioninput, (*it).first))==0){
      cout << (*it).first << endl;
      cin.ignore();
      return (*it).second;
      
    }
  }

}
