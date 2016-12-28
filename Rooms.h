#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include "Item.h"

using namespace std;

struct input_compare{//used to overload so that we can use strings in the maps
  bool operator()(char const*a, char const*b){
    return strcmp(a,b) < 0; 
  }

};

class Rooms{
 public:
  Rooms(const char* newDescription,vector<Rooms*>* roomList);
  
  char* getRoom();
  char* getItems();
  void getExits(char* exitKey);
  void pickupItem(vector<Item*>* inventory, char* itemName);//putting the item into inventory
  void putItem(vector<Item*>* inventory, char* itemName);//moving an item into the room
  void placeItem(Item* item); //Place item in the room
  void setExits(const char* exitName, Rooms* exitRoom);
  void printExits();//printing out all the exits
  void printDescription();//print out information (name, description,...)
 protected:
  char room[10];
  int type;
  map<const char*,Rooms*, input_compare> exits;
  vector<Item*> items;
  char* description;

};
