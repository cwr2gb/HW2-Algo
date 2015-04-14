//Charles Regan
//cwr2gb
//hw2.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "MoveComp.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  
  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  
  // attempt to open the supplied file
  ifstream file(argv[1]);
  
  // report any problems opening the file and then exit
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
  
  int num_cases, boxes, movewith, num_comps;  
  FILE *fp = fopen(argv[1], "r");
  //Gets number of cases
  file >> num_cases;
  int numcases = 0;
  //gets Boxes, how many you have to move with
  //and number of comapnies
  while(numcases < num_cases){
    cout << "Case " << numcases+1 << endl;
    file >> boxes;
    file >> movewith;
    file >> num_comps;
    //Beginning of loop to determine lowest cost for each company
    int count = 0, tcost = 0;
    string name;
    int costper,costhalf;
    vector<MoveComp> *store  = new vector<MoveComp>;
    vector<int> *sorting = new vector<int>;
    while(count < (num_comps*3)){
      //reads in name of company and the cost
      //per item and the cost of half the items
      int tempb = boxes;
      file >> name;
      file >> costper;
      file >> costhalf;
      while(movewith < tempb){
	if( ((tempb/2)+1) > movewith){
	  if( ((tempb/2)+1)*costper > costhalf){
	    tcost =costhalf+tcost;
	    tempb = tempb - ((tempb/2)+1);
	  }
	  else{
	    tcost = ((tempb-movewith)*costper) + tcost;
	    tempb = 0;
	  }
	}
	else{
	  tcost = ((tempb-movewith)*costper) + tcost;
	  tempb = 0;
	    }
      }
      //Adds new Company to store vector for sorting
      MoveComp add = MoveComp(tcost, name);
      sorting->push_back(tcost);
      store->push_back(add);
      tcost = 0;
      //Adds 3 to count to move to next company
      count = count + 3;
    }
    
    //Sorts values
    sort(sorting->begin(),sorting->end());
    vector<MoveComp> *final= new vector<MoveComp>;
    vector<MoveComp> *store2 = new vector<MoveComp>;
    int check = 0;
    for(std::vector<int>::const_iterator y = sorting->begin(); y != sorting->end(); ++y){
      for(std::vector<MoveComp>::const_iterator z = store->begin(); z != store->end(); ++z){        if(*y == z->getCost() && check < 1){
	  MoveComp add2 = MoveComp(z->getCost(),z->getComp());
	  final->push_back(add2);
	  check++;
        }
	else 
	  {
	    MoveComp add2 = MoveComp(z->getCost(),z->getComp());
	    store2->push_back(add2);  
	  }
      }
      check = 0;
      store->clear();
      for(std::vector<MoveComp>::const_iterator x = store2->begin(); x != store2->end(); ++x){
	MoveComp add2 = MoveComp(x->getCost(),x->getComp());
	store->push_back(add2);
      } 
      store2->clear();
      
    }
    //Prints values in ascending order
    for(std::vector<MoveComp>::const_iterator x = final->begin(); x != final->end(); ++x){
      std::cout << x->getComp() << " " << x->getCost() << endl;
    }
    
    //Goes to next case and empties the Vector
    numcases++;
  }
  
}
