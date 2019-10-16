#include "Plane.h" 
#include "Planes.h"
#include <fstream>

bool avail;

void Planes::Save()
{
  ofstream file;
  file.open ("Planes.txt");
  
  cout << "Saved.\n";
  
  for (int i = 0; i < planeList.size(); i++)
  {
    file << planeList.at(i).getMake() << endl;
    file << planeList.at(i).getModel() << endl;
    file << planeList.at(i).gettailNum() << endl;
    file << planeList.at(i).getseatNum() << endl;
    file << planeList.at(i).getRange() << endl;
    file << planeList.at(i).getStatus() << endl;
  }
  file.close();
  
}

void Planes::Load()
{
  ifstream file;
  Plane newPlane;
  string str;
  int num;
  
  file.open("Planes.txt");
  
  while(file)
  {
    file >> str;
    newPlane.setMake(str);
    
    file >> str;
    newPlane.setModel(str);
    
    file >> str;
    newPlane.settailNum(str);
    
    file >> num;
    newPlane.setseatNum(num);
    
    file >> num;
    newPlane.setRange(num);
    
    file >> num;
    newPlane.setStatus(num);
    
    planeList.push_back(newPlane);
  }
  file.close();
  
}

void Planes::availPlane(string tailNum) 
{ 
  avail = false;
  
  for (int i = 0; i < planeList.size(); i++) 
  {     
    if (planeList.at(i).gettailNum() == tailNum)
    { 
      cout << "Tail Number already Exists.\n\n";
      avail = true;
      break;
    }  
  } 
} 

void Planes::addPlane() 
{ 
  string make, model, tailNum;
  int i = planeList.size(), seatNum, range, status;
  
  void Input(string &str, string text, string error = "Input must be Text.\n");
  void Input(int &num, string text, string error = "Input must be a Number.\n");
  
  Plane newPlane(make, model, tailNum, seatNum, range, status);
  
  cin.ignore();
  Input(make, "Enter the Make of the Plane: ");
  Input(model, "Enter the Model of the Plane: ");
  
  do
  {
    Input(tailNum, "Enter the Tail Number of the Plane: ");
    availPlane(tailNum);
  } while(avail == true);
  
  Input(seatNum, "Enter the Number of Seats in the Plane: ");
  Input(range, "Enter the Range of the Plane: ");
  Input(status, "\n1. IN\t\t2. OUT\t\t3. REPAIR\t\t\nEnter the Status of the Plane: ");

  switch (status) 
  { 
    case 1: 
      planeList.push_back(newPlane);

        planeList.at(i).setMake(make);
        planeList.at(i).setModel(model);
        planeList.at(i).settailNum(tailNum);
        planeList.at(i).setseatNum(seatNum);
        planeList.at(i).setRange(range);
        planeList.at(i).setStatus(status);
      
      cout << "Success.\n";
      break;

    case 2: 
      planeList.push_back(newPlane);

        planeList.at(i).setMake(make);
        planeList.at(i).setModel(model);
        planeList.at(i).settailNum(tailNum);
        planeList.at(i).setseatNum(seatNum);
        planeList.at(i).setRange(range);
        planeList.at(i).setStatus(status);

      cout << "Success.\n";
      break;

    case 3: 
      planeList.push_back(newPlane);

        planeList.at(i).setMake(make);
        planeList.at(i).setModel(model);
        planeList.at(i).settailNum(tailNum);
        planeList.at(i).setseatNum(seatNum);
        planeList.at(i).setRange(range);
        planeList.at(i).setStatus(status);

      cout << "Success.\n";
      break;

    default: 
      cout << "Error, Plane deleted.\n";
      break;
  } 
  Save();
  cout << endl;

} 

void Planes::deletePlane() 
{ 
  int i = 1;
  i = findPlane();

  if (avail == true)
  {
    planeList.erase(planeList.begin() + i);
    cout << "Plane deleted.\n\n";
  }
  Save();

} 

int Planes::findPlane() 
{ 
  void Input(string &str, string text, string error = "Input must be Text.\n");
  string tailNum;
  
  cin.ignore();
  Input(tailNum, "Enter the Plane's Tail Number: ");
  cout << endl;
  
  avail = false;
  
  for (int i = 0; i < planeList.size(); i++) 
  {     
    if (planeList.at(i).gettailNum() == tailNum) 
    { 
      cout << "PLANE FOUND.\n";
      avail = true;
      return i;
      break;
    }  
  } 
  if(avail == false)
  {
    cout << "Plane does not Exist.\n\n";
    return -1;
  }
} 

void Planes::editPlane() 
{ 
  void Input(int &num, string text, string error = "Input must be a Number.\n");
  int i = 0, status;

  i = findPlane();
  
  if (avail == true)
  {
    Input(status, "\n1. IN\t\t2. OUT\t\t3. REPAIR\t\t\nEnter the Status of the Plane: ");
  
    switch (status) 
    { 
      case 1: 
        planeList.at(i).setStatus(status);
        cout << "Success.\n";
        break;

      case 2: 
        planeList.at(i).setStatus(status);
        cout << "Success.\n";
        break;

      case 3: 
        planeList.at(i).setStatus(status);
        cout << "Success.\n";
        break;

      default: 
        cout << "Error.\n";
        break;
    } 
    Save();
    cout << endl;
    
  }
}

void Planes::printPlane()
{ 
  for (int i = 0; i < planeList.size(); i++) 
  {
    cout << "Make: " << planeList.at(i).getMake() << endl;
    cout << "Model: " << planeList.at(i).getModel() << endl;
    cout << "Tail Number: " << planeList.at(i).gettailNum() << endl;
    cout << "Number of Seats: " << planeList.at(i).getseatNum() << endl;
    cout << "Range: " << planeList.at(i).getRange() << endl;
    cout << "Status: ";
 
    if (planeList.at(i).getStatus() == 1) 
    { 
      cout << "IN\n";
    }
    else if (planeList.at(i).getStatus() == 2) 
    { 
      cout << "OUT\n";
    } 
    else if (planeList.at(i).getStatus() == 3) 
    { 
      cout << "REPAIR\n";
    } 
    cout << endl;
  
  } 
}

void Planes::searchPlane()
{
  int i = 0;
  i = findPlane();
  
  if (avail == true)
  {
    cout << "Make: " << planeList.at(i).getMake() << endl;
    cout << "Model: " << planeList.at(i).getModel() << endl;
    cout << "Tail Number: " << planeList.at(i).gettailNum() << endl;
    cout << "Number of Seats: " << planeList.at(i).getseatNum() << endl;
    cout << "Range: " << planeList.at(i).getRange() << endl;
    cout << "Status: ";
 
    if (planeList.at(i).getStatus() == 1) 
    { 
      cout << "IN\n";
    }
    else if (planeList.at(i).getStatus() == 2) 
    { 
      cout << "OUT\n";
    } 
    else if (planeList.at(i).getStatus() == 3) 
    { 
      cout << "REPAIR\n";
    } 
    cout << endl;
  }
}

void Planes::clearPlane() 
{ 
  planeList.clear();
}