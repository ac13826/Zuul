#ifndef ROOMS_H
#define ROOMS_H

#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include "Items.h"

using namespace std;

struct input_compare{//used to overload so that we can use strings in the maps
  bool operator()(char const*a, char const*b){
    return strcmp(a,b) < 0; 
  }

};

class Rooms{
 public:
  Rooms(const char* newDescription,vector<Rooms*>* roomList);
  ~Rooms();
  bool isEnd();
  bool gameover();
  char* getItem();
  Rooms* getExits(char* exitKey);
  void pickupItem(vector<Items*>* inventory);//putting the item into inventory
  void putItem(vector<Items*>* inventory);//putting an item into the room
  void placeItem(Items* item); //Place item in the room
  void setExits(const char* exitName, Rooms* exitRoom);
  void printExits();//printing out all the exits
  void printItems();
  Rooms* goThruExit();
  void printDescription();//print out information (name, description,...)
  void setEnd();
  void setLose();
  void checkItem();
 protected:
  char room[10];
  int type;
  map<const char*,Rooms*, input_compare> exits;
  vector<Items*> items;//for the rooms
  char* description;
  char directioninput[30];
  bool end;
  bool itemcheck;
  bool lose;
};

#endif
