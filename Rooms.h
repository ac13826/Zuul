#include<iostream>
#include<string.h>
#include<map>
using namespace std;

struct input_compare{
  bool operator()(char const*a, char const*b){
    return strcmp(a,b) < 0; 
  }

};

class Rooms{
 public:
  Rooms();
  
  char* getRoom();
  char* getItems();
  void getExits();
 protected:
  char room[10];
  int type;
  map<const char*,Rooms*, input_compare> exits;
};
