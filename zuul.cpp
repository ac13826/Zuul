#include<iostream>
#include<string.h>
#include<vector>
#include "Rooms.h"
#include<map>

using namespace std;

void getDescription(vector<Rooms*>*list);
void pickup(vector<Rooms*>*list);

int main(){
  bool running = true;
  vector<Rooms*>*list = new vector<Rooms*>();
  cout << "You are currently in the 1-20 lab at Sunset. All the cool people are hanging out here." << endl;
  while(running == true){
    getDescription(list);
  }

}

void getDescription(vector<Rooms*>*list){
  Rooms* r = new Rooms();
  r->getRoom();
  cout << "Current exits include: ";
  r->getExits();
}
