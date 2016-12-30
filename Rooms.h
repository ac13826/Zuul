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
  bool isEnd();//winning condition
  bool gameover();//losing condition
  char* getItem();
  Rooms* getExits(char* exitKey);//lowkey useless don't know why i still have this
  void pickupItem(vector<Items*>* inventory);//putting the item into inventory
  void putItem(vector<Items*>* inventory);//putting an item into the room
  void placeItem(Items* item); //Place item in the room
  void setExits(const char* exitName, Rooms* exitRoom);
  void printExits();//printing out all the exits
  void printItems();//printing items
  Rooms* goThruExit();
  void printDescription();//print out information (name, description,...)
  void setEnd();//winnign room
  void setLose();//losing room
  void checkItem();//checking if you have the right item or lose
 protected:
  char room[10];
  int type;
  map<const char*,Rooms*, input_compare> exits;
  vector<Items*> items;//for the rooms
  char* description;
  char directioninput[30];//chosing direction for exit
  bool end;
  bool itemcheck;
  bool lose;
  bool runningsf;
};

#endif
