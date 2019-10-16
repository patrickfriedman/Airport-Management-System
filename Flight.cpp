#include "Flight.h" 

void Flight::setSAC(string newSAC) 
{ 
  sac = newSAC;
} 

void Flight::setEAC(string newEAC) 
{ 
  eac = newEAC;
} 

void Flight::setarriveTime(time_t newarriveTime)
{
  arriveTime = newarriveTime;
}

void Flight::setdepartTime(time_t newdepartTime)
{
  departTime = newdepartTime;
}

void Flight::settailNum(string newtailNum) 
{ 
  tailNum = newtailNum;
} 

void Flight::setpilotID(int newpilotID) 
{ 
  pilotID = newpilotID;
} 

void Flight::setplaneID(int newplaneID) 
{ 
  planeID = newplaneID;
} 

void Flight::setcopilotID(int newcopilotID) 
{ 
  copilotID = newcopilotID;
} 

void Flight::setcrewID(int i, int j) 
{ 
  crewID[i] = j;
} 

void Flight::setcrewID(int newcrewID[3]) 
{
  crewID[0, 1, 2] = newcrewID[0, 1, 2];
} 

void Flight::setpassNum(int newpassNum) 
{ 
  passNum = newpassNum;
} 

void Flight::setStatus(int newStatus) 
{ 
  status = newStatus;
} 

Flight::Flight(string SAC, string EAC, string tn, int pilid, int plaid, int coid, int cid0, int cid1, int cid2, int pn, int s) 
{
  sac = SAC;
  eac = EAC;
  tailNum = tn;
  pilotID = pilid;
  planeID = plaid;
  copilotID = coid;
  passNum = pn;
  status = s;
  crewID[0] = cid0;
  crewID[1] = cid1;
  crewID[2] = cid2;
}

string Flight::getSAC() 
{ 
  return sac;
} 

string Flight::getEAC() 
{ 
  return eac;
} 

time_t Flight::getarriveTime()
{
  return arriveTime;
}

time_t Flight::getdepartTime()
{
  return departTime;
}

string Flight::gettailNum() 
{ 
  return tailNum;
} 

int Flight::getpilotID() 
{ 
  return pilotID;
} 

int Flight::getplaneID() 
{ 
  return pilotID;
} 

int Flight::getcopilotID() 
{ 
  return copilotID;
} 

int Flight::getcrewID(int i) 
{ 
  return crewID[i];
} 

int Flight::getpassNum() 
{ 
  return passNum;
} 

int Flight::getStatus()
{ 
  return status;
}