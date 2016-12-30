#include<iostream>
#include<string.h>
#include<vector>
#include "Items.h"

using namespace std;

Items::Items(const char* newName){
  itemName = strdup(newName);
}
Items::~Items(){
  delete itemName;
}

char* Items::getName(){
  return itemName;

}
