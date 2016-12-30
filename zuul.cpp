#include<iostream>
#include<cstring>
#include<vector>
#include "Rooms.h"
#include<map>
#include "Items.h"

using namespace std;

bool directionCheck(char*a, const char*b);

void setupRoom(vector<Rooms*>*list){//creating all my rooms
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
    front_porch->setExits("north", entrance);
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
    entrance->placeItem(new Items("umbrella"));
    kitchen->placeItem(new Items("cookies"));
    attic->placeItem(new Items("eyeballs"));
    game_room->setEnd();
    torture_room->setLose();
}

int main(){
  bool running = true;
  vector<Items*> inventory;
  vector<Rooms*>list;
  char input[30];
  char directioninput[30];
  setupRoom(&list);
  Items* jacket = new Items("jacket");
  Items* shoes = new Items("shoes");
  
  inventory.push_back(shoes);
  inventory.push_back(jacket);
  
  Rooms* currentRoom = *list.begin();
  char continueplaying[30];
  bool checkItem = false;


  while(running == true){
    
    currentRoom->printDescription();
    if(currentRoom->gameover()){
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
    if(currentRoom->isEnd()){
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
    cout << "What would you like to do? Type: move, put, pickup, quit" << endl;
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

bool directionCheck(char*a, const char*b){
  for(int i = 0; i < strlen(b); i++){
    if(a[i] != b[i])
      return false;
  }
  return true;
}
