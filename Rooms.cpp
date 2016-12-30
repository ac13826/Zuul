//Rooms class for zuul
#include<iostream>
#include "Rooms.h"
#include "Items.h"
#include<map>

using namespace std;

Rooms::Rooms(const char* newDescription, vector<Rooms*>* roomList){
  description = strdup(newDescription);//puts description string on the heap and converts into a char* safely
  roomList->push_back(this);//pushing "this" as in the current pointer being worked on
  end = false;
  lose = false;
  runningsf = true;
}

Rooms::~Rooms(){
  delete description;

}



void Rooms::setExits(const char* exitName, Rooms* exitRoom){//create exit
  exits[exitName] = exitRoom;
  
}
void Rooms::printExits(){//printing the exits
  for(map<const char*, Rooms*>::iterator it = exits.begin(); it != exits.end(); it++){
    cout << (*it).first << endl;//prints out the first part of the map (second part would be the rooms that they go into
  }
}

void Rooms::printDescription(){//printing the description
  cout << "------------------------------" << endl;
  cout << "You are " << description << endl;
  cout << "There is/are: " << endl;
  printItems();
  cout << "You can go: " << endl;
  printExits();
  
}

/*ooms* Rooms::getExits(char* exitKey){
  map<const char*, Rooms*>::iterator it = exits.find(exitKey);
  if(it != exits.end()){
    return exits[exitKey];
  }
  else{
    return NULL;
  }  
}*/

void Rooms::pickupItem(vector<Items*>* inventory){//placing item in the inventory
  char itempickup[30];
  cout << "What would you like to pick up?" << endl;
  cin.get(itempickup,30);
  cin.ignore();
  for(vector<Items*>::iterator it = items.begin(); it !=items.end(); it++){
    if((strcmp((*it)->getName(),itempickup))==0){
      inventory->push_back(*it);
      items.erase(it);
      cout << "You picked up: " << itempickup << endl;
      break;
    }
  }

}

void Rooms::putItem(vector<Items*>* inventory){//putting item into the room item vector
  char putName[30];
  cout << "What would you like to put down?" << endl;
  cin.get(putName, 30);
  cin.ignore();
  for(vector<Items*>::iterator it = inventory->begin(); it !=inventory->end(); it++){
    if((strcmp((*it)->getName(),putName))==0){
      cout <<"hey" << endl;
      items.push_back(*it);
      inventory->erase(it);break;
    }
  }
}

void Rooms::placeItem(Items* item){//when i first begin the program and put items into the rooms i choose
  items.push_back(item);
}

void Rooms::printItems(){//printing what items you have
  for(vector<Items*>::iterator it = items.begin(); it !=items.end(); it++){
     cout << (*it)->getName() << endl;
  }
}

Rooms* Rooms::goThruExit(){//choosing which exit to go through
  while(runningsf=true){
    cout << "You can go" << endl;
    
    printExits();
    
    cout << "Where would you like to go?" << endl;
    cin.get(directioninput,30);
    cin.ignore();
    if(((strcmp(directioninput,"north"))==0) || ((strcmp(directioninput,"west"))==0) ||((strcmp(directioninput,"east"))==0) || ((strcmp(directioninput,"south"))==0)){
      for(map<const char*, Rooms*>::iterator it = exits.begin(); it != exits.end(); it++){
	if((strcmp(directioninput, (*it).first))==0){
	  cout << (*it).first << endl;
	
	  return (*it).second;
	  
	}
      }    
    }
  } 
}
//winning and losing conditions check
void Rooms::setEnd(){
  
end = true;
}
bool Rooms::isEnd(){
  return end;
}

void Rooms::setLose(){
  lose = true;
}
bool Rooms::gameover(){
  return lose;
}

/*void Rooms:: checkItem(){
  for(vector<Items*>::iterator it = inventory->begin(); it !=inventory->end(); it++){
    cout << *it << endl;
    if((strcmp((*it)->getName(),"cookies"))==0){
      itemcheck = true;
    }
  }
  }*/
