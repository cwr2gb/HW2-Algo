//MoveComp.cpp
#include "MoveComp.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
//Constructor
MoveComp::MoveComp(int precio, string nombre){
  name = nombre;
  cost = precio;
}

int MoveComp::getCost() const{
  return cost;
}

string MoveComp::getComp() const{
  return name;
}
void MoveComp::setCost(int precio){
  cost = precio;
}

void MoveComp::setComp(string nombre){
  name = nombre;
}
