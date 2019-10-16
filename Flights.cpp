
#include "Flight.h" 
#include "Flights.h"
#include <fstream>

bool availability;

void Flights::Save()
{
  ofstream file;
  file.open ("Flights.txt");
  
  cout << "Saved.\n";
  
  for (int i = 0; i < flightList.size(); i++)
  {
    file << flightList.at(i).getSAC() << endl;
    file << flightList.at(i).getEAC() << endl;
    file << flightList.at(i).getdepartTime() << endl;
    file << flightList.at(i).getarriveTime() << endl;
    file << flightList.at(i).gettailNum() << endl;
    file << flightList.at(i).getpilotID() << endl;
    file << flightList.at(i).getcopilotID() << endl;
    file << flightList.at(i).getpassNum() << endl;
    
    for(int j = 0; j < 3; j++)
    {
      file << flightList.at(i).getcrewID(j) << endl;
    }
    
    file << flightList.at(i).getStatus() << endl;
  }
  file.close();
  
}

void Flights::Load()
{
  ifstream file;
  Flight newFlight;
  string str;
  time_t tim;
  int num;
  
  file.open("Flights.txt");
  
  while(file)
  {
    file >> str;
    newFlight.setSAC(str);
    
    file >> str;
    newFlight.setEAC(str);
    
    file >> str;
    newFlight.settailNum(str);
    
    file >> tim;
    newFlight.setdepartTime(tim);
    
    file >> tim;
    newFlight.setarriveTime(tim);
    
    file >> num;
    newFlight.setpilotID(num);
    
    file >> num;
    newFlight.setcopilotID(num);
    
    file >> num;
    newFlight.setpassNum(num);
    
    for(int j = 0; j < 3; j++)
    {
      file >> num;
      newFlight.getcrewID(j);
      cout << endl;
    }
    
    file >> num;
    newFlight.setStatus(num);
    
    flightList.push_back(newFlight);
  }
  file.close();
  
}

void Flights::availFlight(string sac, string eac) 
{ 
  availability = false;
  
  for (int i = 0; i < flightList.size(); i++) 
  {     
    if ((flightList.at(i).getSAC() == sac) && (flightList.at(i).getEAC() == eac))
    { 
      cout << "Crew Member ID already Exists.\n\n";
      availability = true;
      break;
    }  
  } 
} 

void Flights::addFlight() 
{ 
  string sac, eac, tailNum;
  int i = flightList.size(), pilotID, planeID, copilotID, crewID[3], passNum, status; 
  time_t departTime, arriveTime;
  
  void Input(string &str, string text, string error = "Input must be Text.\n");
  void Input(int &num, string text, string error = "Input must be a Number.\n");
  void Input(time_t &now, string text);
  Flight newFlight(sac, eac, tailNum, pilotID, planeID, copilotID, crewID[0], crewID[1], crewID[2], passNum, status);
 
  cin.ignore();
  do
  {
    Input(sac, "Enter the Starting Airport Code of the Flight: ");
    Input(eac, "Enter the Ending Airport Code of the Flight: ");
    availFlight(sac, eac);
  } while(availability == true);
    
  Input(departTime, "DEPARTURE: ");
  Input(arriveTime, "ARRIVAL: ");
  
  cin.ignore();
  Input(tailNum, "Enter the Plane's Tail Number: "); //check
  Input(pilotID, "Enter the Pilot's ID of the Flight: "); //check
  Input(passNum, "Enter the Number of Passengers of the Flight: ");
  Input(copilotID, "Enter the Co-Pilot's ID of the Flight: "); //check
  Input(crewID[0], "Enter the First Crew ID of the Flight: "); //check
  Input(crewID[1], "Enter the Second Crew ID of the Flight: "); //check
  Input(crewID[2], "Enter the Third Crew ID of the Flight: "); //check
  Input(status, "\n1. ACTIVE\t\t2. CANCELLED\t\t3. COMPLETED\t\t\nEnter the Status of the Flight: ");
 
  switch (status) 
  { 
    case 1: 
      flightList.push_back(newFlight);

        flightList.at(i).setSAC(sac);
        flightList.at(i).setEAC(eac);
        flightList.at(i).setdepartTime(departTime);
        flightList.at(i).setarriveTime(arriveTime);
        flightList.at(i).settailNum(tailNum);
        flightList.at(i).setpilotID(pilotID);
        flightList.at(i).setcopilotID(copilotID);
        flightList.at(i).setpassNum(passNum);
        flightList.at(i).setcrewID(0, crewID[0]);
        flightList.at(i).setcrewID(1, crewID[1]);
        flightList.at(i).setcrewID(2, crewID[2]);
        flightList.at(i).setStatus(status);
      
      cout << "Success.\n";
      break;
 
    case 2: 
      flightList.push_back(newFlight);
            
        flightList.at(i).setSAC(sac);
        flightList.at(i).setEAC(eac);
        flightList.at(i).setdepartTime(departTime);
        flightList.at(i).setarriveTime(arriveTime);
        flightList.at(i).settailNum(tailNum);
        flightList.at(i).setpilotID(pilotID);
        flightList.at(i).setcopilotID(copilotID);
        flightList.at(i).setpassNum(passNum);
        flightList.at(i).setcrewID(0, crewID[0]);
        flightList.at(i).setcrewID(1, crewID[1]);
        flightList.at(i).setcrewID(2, crewID[2]);
        flightList.at(i).setStatus(status);
      
      cout << "Success.\n";
      break;
 
    case 3: 
      flightList.push_back(newFlight);
            
        flightList.at(i).setSAC(sac);
        flightList.at(i).setEAC(eac);
        flightList.at(i).setdepartTime(departTime);
        flightList.at(i).setarriveTime(arriveTime);
        flightList.at(i).settailNum(tailNum);
        flightList.at(i).setpilotID(pilotID);
        flightList.at(i).setcopilotID(copilotID);
        flightList.at(i).setpassNum(passNum);
        flightList.at(i).setcrewID(0, crewID[0]);
        flightList.at(i).setcrewID(1, crewID[1]);
        flightList.at(i).setcrewID(2, crewID[2]);
        flightList.at(i).setStatus(status);
      
      cout << "Success.\n";
      break;
 
    default: 
      cout << "Error, Flight deleted.\n";
      break;
  } 
  Save();
  cout << endl;
  
} 

int Flights::findFlight() 
{ 
  void Input(string &str, string text, string error = "Input must be Text.\n");
  string sac, eac;
 
  cin.ignore();
  Input(sac, "Enter the Starting Airport Code: ");
  Input(eac, "Enter the Ending Airport Code: ");
  cout << endl;
  
  availability = false;
 
  for (int i = 0; i < flightList.size(); i++) 
  {  
    if ((flightList.at(i).getSAC() == sac) && (flightList.at(i).getEAC() == eac)) 
    { 
      cout << "FLIGHT FOUND.\n";
      availability = true;
      return i;
      break;
    }
  }
  if (availability == false)
  {
    cout << "Flight does not Exist.\n\n";
    return -1;
  } 
} 

void Flights::editFlight() 
{ 
  void Input(int &num, string text, string error = "Input must be a Number.\n");
  int i = 0, status;
 
  i = findFlight();
  
  if (availability == true)
  {
    Input(status, "\n1. ACTIVE\t\t2. CANCELLED\t\t3. COMPLETED\t\t\nEnter the Status of the Flight: ");

    switch (status) 
    {  
      case 1: 
        flightList.at(i).setStatus(status);
        cout << "Success.\n";
        break;

      case 2: flightList.at(i).setStatus(status);
        cout << "Success.\n";
        break;

      case 3: flightList.at(i).setStatus(status);
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

void Flights::printFlight() 
{ 
  struct tm localFlight;
  time_t flightTime;
  
  for (int i = 0; i < flightList.size(); i++) 
  { 
    cout<<"Starting Airport Code: " << flightList.at(i).getSAC() << endl;
    cout<<"Ending Airport Code: " << flightList.at(i).getEAC() << endl;
        
    flightTime = flightList.at(i).getdepartTime();
    localFlight = *localtime(&flightTime);
    
    cout << "DEPARTURE: " << localFlight.tm_mon << "/" << localFlight.tm_mday << "/" << localFlight.tm_year << " @ " << localFlight.tm_hour << ":" << localFlight.tm_min << endl;
    
    flightTime = flightList.at(i).getarriveTime();
    localFlight = *localtime(&flightTime);
    
    cout << "ARRIVAL: " << localFlight.tm_mon << "/" << localFlight.tm_mday << "/" << localFlight.tm_year << " @ " << localFlight.tm_hour << ":" << localFlight.tm_min << endl;
    
    cout<<"Tail Number: " << flightList.at(i).gettailNum() << endl;
    cout<<"Pilot ID: " << flightList.at(i).getpilotID() << endl;
    cout<<"Number of Passengers: " << flightList.at(i).getpassNum() << endl;
    cout<<"Plane ID: " << flightList.at(i).getplaneID() << endl;
    cout<<"Co-Pilot ID: " << flightList.at(i).getcopilotID() << endl;
    
    for(int j = 0; j < 3; j++)
    {
      cout<<"Cabin Crew Member " << j << "'s ID: " << flightList.at(i).getcrewID(j);
      cout << endl;
    }
    
    cout<<"Status: ";
    
    if (flightList.at(i).getStatus() == 1) 
    { 
      cout << "ACTIVE\n";
    }
    else if (flightList.at(i).getStatus() == 2) 
    { 
      cout << "CANCELLED\n";
    } 
    else if (flightList.at(i).getStatus() == 3) 
    { 
      cout << "COMPLETED\n";
    } 
    cout << endl;
    
  } 
} 

void Flights::searchFlight()
{
  int i = 0;
  struct tm localFlight;
  time_t flightTime;
  
  i = findFlight();
  
    
  if (availability == true)
  {
    cout << "Starting Airport Code: " << flightList.at(i).getSAC() << endl;
    cout << "Ending Airport Code: " << flightList.at(i).getEAC() << endl;
    
    flightTime = flightList.at(i).getdepartTime();
    localFlight = *localtime(&flightTime);
    
    cout << "DEPARTURE: " << localFlight.tm_mon << "/" << localFlight.tm_mday << "/" << localFlight.tm_year << " @ " << localFlight.tm_hour << ":" << localFlight.tm_min << endl;
    
    flightTime = flightList.at(i).getarriveTime();
    localFlight = *localtime(&flightTime);
    
    cout << "ARRIVAL: " << localFlight.tm_mon << "/" << localFlight.tm_mday << "/" << localFlight.tm_year << " @ " << localFlight.tm_hour << ":" << localFlight.tm_min << endl;
      
    cout << "Tail Number: " << flightList.at(i).gettailNum() << endl;
    cout << "Pilot ID: " << flightList.at(i).getpilotID() << endl;
    cout << "Number of Passengers: " << flightList.at(i).getpassNum() << endl;
    cout << "Plane ID: " << flightList.at(i).getplaneID() << endl;
    cout << "Co-Pilot ID: " << flightList.at(i).getcopilotID() << endl;

    for(int j = 0; j < 3; j++)
    {
      cout <<"Cabin Crew Member " << j << "'s ID: " << flightList.at(i).getcrewID(j);
      cout << endl;
    }

    cout<<"Status: ";

    if (flightList.at(i).getStatus() == 1) 
    { 
      cout << "ACTIVE\n";
    }
    else if (flightList.at(i).getStatus() == 2) 
    { 
      cout << "CANCELLED\n";
    } 
    else if (flightList.at(i).getStatus() == 3) 
    { 
      cout << "COMPLETED\n";
    } 
    cout << endl;

  }
}

void Flights::deleteFlight()
{ 
  int i = 0;  
  i = findFlight();
  
  if (availability == true)
  {
    flightList.erase(flightList.begin() + i);
    cout << "Flight deleted.\n\n";
  }
  Save();
    
} 

void Flights::clearFlight() 
{ 
  flightList.clear();
}