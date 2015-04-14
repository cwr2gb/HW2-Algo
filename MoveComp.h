#ifndef MOVECOMP_H
#define MOVECOMP_H

#include <iostream>

using namespace std;

class MoveComp {
public:
  MoveComp(int precio, string nombre);               
  string name;
  int cost;
  int getCost() const;
  string getComp() const;
  void setCost(int precio);
  void setComp(string nombre);
 private:
  
};

#endif
