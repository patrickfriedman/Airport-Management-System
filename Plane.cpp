#include "Plane.h" 

Plane::Plane()        //default constructor
{ 
  make = "N/A";
  model = "N/A";
  tailNum = "N/A";
  seatNum = 0;
  range = 0;
  status = 0;
}

void Plane::setMake(string newMake)        //set for make
{ 
  make = newMake;
}

void Plane::setModel(string newModel)     //set for model
{ 
  model = newModel;
} 

void Plane::settailNum(string newtailNum)       //set for tailnum
{ 
  tailNum = newtailNum;
} 

void Plane::setStatus(int newStatus)        //set for status
{ 
  status = newStatus;
} 

void Plane::setseatNum(int newseatNum)          //set for seat num
{ 
  seatNum = newseatNum;
} 

void Plane::setRange(int newRange)          //set for range
{ 
  range = newRange;
} 

Plane::Plane(string mk, string mdl, string tn, int sn, int r, int s)      //creates a new object
{ 
  make = mk;
  model = mdl;
  tailNum = tn;
  seatNum = sn;
  range = r;
  status = s;
} 

string Plane::getMake()       //gets make
{ 
  return make;
} 

string Plane::getModel()        //gets model
{ 
  return model;
} 

string Plane::gettailNum()          //gets tailnum
{ 
  return tailNum;
} 

int Plane::getStatus()        //gets status
{ 
  return status;
} 

int Plane::getseatNum()         //gets seat num
{ 
  return seatNum;
} 

int Plane::getRange()             //gets range
{ 
  return range;
}