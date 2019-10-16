#include "CrewMember.h" 
#include "CrewMembers.h" 
#include <fstream>

bool available;

void CrewMembers::Save()
{
  ofstream file;
  file.open ("CrewMembers.txt");
  
  cout << "Saved.\n";
  
  for (int i = 0; i < crewList.size(); i++)
  {
    file << crewList.at(i)->getName() << endl;
    file << crewList.at(i)->getID() << endl;
    //file << crewList.at(i)->getType() << endl;
    file << crewList.at(i)->getStatus() << endl;
  }
  file.close();
  
}

void CrewMembers::Load()
{
  ifstream file;
  CrewMember newCrew;
  string str;
  int num;
  
  file.open("CrewMembers.txt");
  
  while(file)
  {
    file >> str;
    newCrew.setName(str);
    
    file >> str;
    newCrew.setID(num);
    
    //file >> str;
    //newCrew.setType(num);
    
    file >> num;
    newCrew.setStatus(num);
    
    //crewList.push_back(newCrew);
  }
  file.close();
  
}


void CrewMembers::availCrew(int id) 
{ 
  available = false;
  
  for (int i = 0; i < crewList.size(); i++) 
  {     
    if (crewList.at(i)->getID() == id)
    { 
      cout << "Crew Member ID already Exists.\n\n";
      available = true;
      break;
    }  
  } 
} 

void CrewMembers::addCrew() 
{ 
  string name;
  int i = crewList.size(), id, type, status = 1, hours;
  string rate;
  
  void Input(string &str, string text, string error = "Input must be Text.\n");
  void Input(int &num, string text, string error = "Input must be a Number.\n");
   
  CrewMember *New;
  
  cin.ignore();
  Input(name, "Enter the Name of the Crew Member: ");
  
  do
  {
    Input(id, "Enter the ID of the Crew Member: ");
    availCrew(id);
  } while(available == true);
  
  Input(type, "\n1. PILOT\t\t2. CO-PILOT\t\t3. CABIN\t\t\nEnter the Position of the Crew Member: ");
 
  switch (type) 
  { 
    case 1:
      cin.ignore();
      
      do
      {
        Input(rate, "Enter the Pilot's 5 Character Rating: ");
        
        if (rate.length() > 5)
        {
          cout << "Rating must be 5 Characters.\n";  
        }
      } while (rate.length() > 5);
      
      New = new Pilot(name, id, status, rate, hours);
      crewList.push_back(New);
      
      cout << "Success.\n";
      break;
 
    case 2: 
      cin.ignore();
      
      do
      {
        Input(rate, "Enter the CoPilot's 4 Character Rating: ");
        
        if (rate.length() > 4)
        {
          cout << "Rating must be 4 Characters.\n";  
        }
      } while (rate.length() > 4);
      
      New = new CoPilot(name, id, status, rate, hours);
      crewList.push_back(New);
      
      cout << "Success.\n";
      break;
 
    case 3: 
      cin.ignore();
      
      do
      {
        Input(type, "\n1. FIRST CLASS\t\t2. BUSINESS CLASS\t\t3. ECONOMY FRONT\t\t4. ECONOMY REAR\t\t5. LEAD\t\t\nEnter the Type: ");
        
        if ( (type < 1) || (type > 5) )
        {
          cout << "Error, Crew Deleted.\n";  
          break;
        }
                     
        New = new Cabin(name, id, status, type);
        crewList.push_back(New);

        cout << "Success.\n";
        break;
            
      } while ( (type < 1) || (type > 5) );     
      break;
 
    default: 
      cout << "Error, Crew Member deleted.\n";
      break;
  } 
  Save();
  cout << endl;
 
} 

int CrewMembers::findCrew() 
{ 
  void Input(int &num, string text, string error = "Input must be a Number.\n");
  int ID;
 
  cin.ignore();
  Input(ID, "Enter the Crew Member's ID: ");
  cout << endl;
  
  available = false;
  
  for (int i = 0; i < crewList.size(); i++) 
  { 
    if (crewList.at(i)->getID() == ID) 
    {
      cout << "CREW MEMBER FOUND.\n";
      available = true;
      return i;
      break;
    }
  }
  if (available == false)
  {
    cout << "Crew Member does not Exist.\n\n";
    return -1;
  } 
} 

void CrewMembers::editCrew() 
{ 
  void Input(int &num, string text, string error = "Input must be a Number.\n");
  int i = 0, status;
 
  i = findCrew();
  
  if (available == true)
  {
    Input(status, "\n1. AVAILABLE\t\t2. ON LEAVE\t\t3. SICK\t\t\nEnter the Status of the Crew Member: ");

    switch (status) 
    { 
      case 1: 
        crewList.at(i)->setStatus(status);
        cout << "Success.\n";
        break;

      case 2: crewList.at(i)->setStatus(status);
        cout << "Success.\n";
        break;

      case 3: crewList.at(i)->setStatus(status);
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

void CrewMembers::printCrew() 
{ 
  for (int i = 0; i < crewList.size(); i++) 
  { 
    crewList.at(i)->Print();
  } 
} 

void CrewMembers::searchCrew()
{
  int i = 0;
  i = findCrew();
  
  if (available == true)
  {
    cout << "Name: " << crewList.at(i)->getName() << endl;
    cout << "Crew Member ID: " << crewList.at(i)->getID() << endl;
    cout << "Position: ";
    
    if (crewList.at(i)->getStatus() == 1) 
    { 
      cout << "PILOT\n";
    }
    else if (crewList.at(i)->getStatus() == 2) 
    { 
      cout << "CO-PILOT\n";
    } 
    else if (crewList.at(i)->getStatus() == 3) 
    { 
      cout << "CABIN\n";
    } 
    
    cout << "Status: ";
    
    if (crewList.at(i)->getStatus() == 1) 
    { 
      cout << "AVAILABLE\n";
    }
    else if (crewList.at(i)->getStatus() == 2) 
    { 
      cout << "ON LEAVE\n";
    } 
    else if (crewList.at(i)->getStatus() == 3) 
    { 
      cout << "SICK\n";
    } 
    cout << endl;
    
  }
}


void CrewMembers::deleteCrew() 
{ 
  int i = 0;  
  i = findCrew();
  
  if (available == true)
  {
    crewList.erase(crewList.begin() + i);
    cout << "Crew Member deleted.\n\n";
  }
  Save();
    
} 

void CrewMembers::clearCrew() 
{
  crewList.clear();
}