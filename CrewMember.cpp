#include "CrewMember.h" 
#include <string>
using namespace std; 

void CrewMember::setName(string newName) 
{ 
  name = newName;
} 

void CrewMember::setID(int newID) 
{ 
  id = newID;
} 

void CrewMember::setStatus(int newStatus) 
{ 
  status = newStatus;
} 

void Pilot::setRate(string newRate)
{
  rate = newRate;
}

void Pilot::setHours(int newHours)
{
  hours = newHours;
}

void CoPilot::setCRate(string newCRate)
{
  crate = newCRate;
}

void CoPilot::setCHours(int newCHours)
{
  chours = newCHours;
}

void Cabin::setType(int newType)
{
  type = newType;
}

Pilot::Pilot(string n, int ID, int s, string r, int h)      //creates a new object
{ 
  name = n;
  id = ID;
  status = s;
  rate = r;
  hours = h;
} 

CoPilot::CoPilot(string n, int ID, int s, string r, int h)      //creates a new object
{ 
  name = n;
  id = ID;
  status = s;
  crate = r;
  chours = h;
} 

Cabin::Cabin(string n, int ID, int s, int t)     //creates a new object
{ 
  name = n;
  id = ID;
  status = s;
  type = t;
} 

string CrewMember::getName() 
{ 
  return name;
} 

int CrewMember::getID()
{ 
  return id;
} 

int CrewMember::getStatus() 
{ 
  return status;
}

string Pilot::getRate()
{
  return rate;
}

int Pilot::getHours()
{
  return hours;
}

string CoPilot::getCRate()
{
  return crate;
}

int CoPilot::getCHours()
{
  return chours;
}

int Cabin::getType()
{
  return type;
}
        
void CrewMember::Print()
{
    cout << "Name: " << name << endl;
    cout << "Crew Member ID: " << id << endl;
    cout << "Status: ";
    
    if (status == 1) 
    { 
      cout << "AVAILABLE\n";
    }
    else if (status == 2) 
    { 
      cout << "ON LEAVE\n";
    } 
    else if (status == 3) 
    { 
      cout << "SICK\n";
    } 
}
        
void Pilot::Print()
{
  CrewMember::Print();
  
  cout << "Rate: " << rate << endl;
  cout << "Cumlative Hours: " << hours << endl;
  cout << endl;
}
        
void CoPilot::Print()
{
  CrewMember::Print();
  
  cout << "Rate: " << crate << endl;
  cout << "Cumlative Hours: " << chours << endl;
  cout << endl;
}
        
void Cabin::Print()
{
  CrewMember::Print();
  
  cout << "Type: ";
  switch(type)
  {
    case 1:
      cout << "First Class\n\n";
      break;
      
    case 2:
      cout << "Business Class\n\n";
      break;
      
    case 3:
      cout << "Economy Front\n\n";
      break;
      
    case 4:
      cout << "Economy Rear\n\n";
      break;
      
    case 5:
      cout << "Lead\n\n";
      break;
      
    default:
      cout << "Error.\n";
  }
}