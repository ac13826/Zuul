#include<iostream>
#include<string.h>
#include<vector>
#include "Items.h"

using namespace std;

Items::Items(const char* newName){
  itemName = strdup(newName);
}
Items::~Items(){//unneeded, was going to try something
  delete itemName;
}

char* Items::getName(){//getting the name of the item
  return itemName;

}
