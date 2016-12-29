#include<iostream>
#include<cstring>
#include<vector>
#include "Rooms.h"
#include<map>

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
    Rooms* sanil = new Rooms("in Sanil's Room, it smells kinda funny.", list);
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

    guest_room->setExits("east", elevator);
    guest_room->setExits("north", bronze_bath);
    
    bronze_bath->setExits("south", guest_room);
    bronze_bath->setExits("west", attic);

    attic->setExits("east", bronze_bath);
}

int main(){
  bool running = true;
  vector<Item*> inventory;
  vector<Rooms*>list;
  char input[30];
  char directioninput[30];
  setupRoom(&list);
  Rooms* currentRoom = *list.begin();
  while(running == true){
    cout << currentRoom << endl;
    currentRoom->printDescription();
    cout << "What would you like to do?" << endl;
    cin.get(input,30);
    cin.ignore();
    if((strcmp(input, "move"))==0){
      currentRoom = currentRoom->goThruExit();
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
