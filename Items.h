//Items header file for zuul
#ifndef ITEMS_H
#define ITEMS_H

#include<iostream>
#include<string.h>
#include<vector>

class Items{
 public:
  Items(const char* newName);
  ~Items();
  char* getName();
 protected:
  char* itemName;


};
#endif
