//This is zuul, a game where you run around picking stuff up.
//By Austin Chang, completed 12/30 (college apps p much due tomorrow)
//Period 7

#include<iostream>
#include<cstring>
#include<vector>
#include "Rooms.h"//rooms class
#include<map>
#include "Items.h"//items class

using namespace std;

bool directionCheck(char*a, const char*b);//was intended for later but pmuch useless at this point

void setupRoom(vector<Rooms*>*list){//creating a vector of room pointers
    Rooms* front_porch = new Rooms("at Sanil's front door. He invited you to his game room, but you have to find it yourself", list);
    Rooms* entrance = new Rooms("at the entrance of the house. Please take of your shoes.", list);
    Rooms* hall = new Rooms("in the hall.", list);
    Rooms* family_room = new Rooms("in the family room.", list);
    Rooms* silver_bath = new Rooms("in the silver bathroom.", list);
    Rooms* kitchen = new Rooms("in the kitchen.", list);
    Rooms* living_room = new Rooms("in the living room. Play the piano!", list);
    Rooms* elevator = new Rooms("in the elevator that is moving upward.", list);
    Rooms* corridor = new Rooms("in the corridor.", list);
    Rooms* sanil = new Rooms("in Sanil's Room, it smells kinda funny. You are at a crossroads of sorts. I recommend that you get the eyeballs and the cookies. Should you choose the wrong path, and not have all the items... hehehe (basically you might lose, so i recommend getting cookies and eyeballs", list);
    Rooms* torture_room = new Rooms("in the torture room... you hear screaming, it's all dark, there seems to be a curtain that's blocking the view.", list);
    Rooms* golden_bath = new Rooms("IN THE GOLDEN BATHROOM.", list);
    Rooms* game_room = new Rooms("finally in the game room!", list);
    Rooms* guest_room = new Rooms("in the guest room. Might as well take a nap here", list);
    Rooms* bronze_bath = new Rooms("in the bronze bathroom.", list);
    Rooms* attic = new Rooms("in the attic. It's quite dusty.", list);
    
    //exits
    front_porch->setExits("north", entrance);//setExit is in the Room class and is used for making maps where the "direction" refers to a specific room pointer
    entrance->setExits("north", hall);
    entrance->setExits("south", front_porch);

    hall->setExits("north", family_room);
    hall->setExits("south", entrance);
    
    family_room->setExits("west", silver_bath);
    family_room->setExits("east", kitchen);
    family_room->setExits("south", hall);
    
    silver_bath->setExits("east", family_room);
   
    kitchen->setExits("west", family_room);
    kitchen->setExits("north", living_room);
    
    living_room->setExits("north", elevator);
    living_room->setExits("south", kitchen);
    
    elevator->setExits("south", living_room);
    elevator->setExits("east", corridor);
    elevator->setExits("west", guest_room);
    
    corridor->setExits("west", elevator);
    corridor->setExits("east", sanil);

    sanil->setExits("west", corridor);
    sanil->setExits("north", golden_bath);
    sanil->setExits("south", torture_room);

    torture_room->setExits("north", sanil);
    
    golden_bath->setExits("south", sanil);
    golden_bath->setExits("east", game_room);

    game_room->setExits("west",golden_bath);

    guest_room->setExits("east", elevator);
    guest_room->setExits("north", bronze_bath);
    
    bronze_bath->setExits("south", guest_room);
    bronze_bath->setExits("west", attic);

    attic->setExits("east", bronze_bath);
    entrance->placeItem(new Items("umbrella"));//creating and placing a couple of items in specific rooms 
    kitchen->placeItem(new Items("cookies"));
    attic->placeItem(new Items("eyeballs"));
    game_room->setEnd();//win condition room
    torture_room->setLose();//lose condition room
}

int main(){
  bool running = true;
  vector<Items*> inventory;//user vector for items
  vector<Rooms*>list;//vector of rooms
  char input[30];
  char directioninput[30];
  setupRoom(&list);//setting up the rooms
  Items* jacket = new Items("jacket");//initial user items
  Items* shoes = new Items("shoes");
  
  inventory.push_back(shoes);//pushing onto the inventory
  inventory.push_back(jacket);
  
  Rooms* currentRoom = *list.begin();//currentRoom tracks which room pointer i'm on, and starts from the "beginning"
  char continueplaying[30];
  bool checkItem = false;


  while(running == true){
    
    currentRoom->printDescription();//printing out everything about the room
    if(currentRoom->gameover()){//losing conidition
      for(vector<Items*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	if((strcmp((*it)->getName(),"eyeballs"))==0){
	  cout << "Thank you for bringing the eyeballs, we will now spare your life." << endl;
	  checkItem = true;
	}
	
      }
      if(checkItem == false){
	cout << "Ruhika: You didn't bring eyes for sacrifices... therefore I'll have you instead :) <3" << endl;
	return 0;
      }
    

    }
    if(currentRoom->isEnd()){//winning conditiion
      for(vector<Items*>::iterator it = inventory.begin(); it != inventory.end() ; it++){
        cout << (*it)->getName() << endl;
	if((strcmp((*it)->getName(),"cookies"))==0){
	  cout << "Sanil: HEYY You brought cookies! Thanks!" << endl;
	  cout << "you win" << endl;
	  cout << "Would you like to keep exploring?" << endl;
	  cin.get(continueplaying, 30);
	  cin.ignore();
	  if((strcmp(continueplaying,"yes"))==0){
	    running = true;
	  }
	  else if((strcmp(continueplaying,"no"))==0){
	    running = false;
	  }
	
	}
      }
    }
    cout << "What would you like to do? Type: move, put, pickup, quit" << endl;//start
    cin.get(input,30);
    cin.ignore();
    if((strcmp(input, "quit"))==0){
      return 0;
    }
    if((strcmp(input, "move"))==0){
      currentRoom = currentRoom->goThruExit();
    }
    else if((strcmp(input, "inventory"))==0){
      cout << "You have: " << endl;
      for(vector<Items*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	cout << (*it)->getName() << endl;
	/*    for(vector<Items*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	 */ if((strcmp((*it)->getName(),"cookies"))==0){
        checkItem = true;
      }/*
      cout << (*it)->getName() << endl;
    }
	 */
      }
    }
    else if((strcmp(input, "pickup"))==0){
      cout << "hello " << endl;
      currentRoom->pickupItem(&inventory);
      
    }
    else if((strcmp(input, "put"))==0){
      currentRoom->putItem(&inventory);
    }
    
  }
}

bool directionCheck(char*a, const char*b){//lowkey useless
  for(int i = 0; i < strlen(b); i++){
    if(a[i] != b[i])
      return false;
  }
  return true;
}
