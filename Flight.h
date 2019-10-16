#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Flight
{
  private:
    string sac, eac, tailNum;
    int pilotID, planeID, copilotID, crewID[3], passNum, status;
    time_t arriveTime, departTime;
    
  public:
    void setSAC(string newSAC);    
    void setEAC(string newEAC);    
    void setdepartTime(time_t newdepartTime);
    void setarriveTime(time_t newarriveTime);
    void settailNum(string newtailNum);
    void setpilotID(int newpilotID);    
    void setplaneID(int newplaneID);    
    void setcopilotID(int newcopilotID);    
    void setcrewID(int newcrewID[3]);  
    void setcrewID(int i, int j);
    void setpassNum(int newpassNum);    
    void setStatus(int newStatus); 
    
    Flight(string SAC, string EAC, string tn, int pilid, int plaid, int coid, int cid0, int cid1, int cid2, int pn, int s);
    
    string getSAC();
    string getEAC();
    string gettailNum();
    time_t getarriveTime();
    time_t getdepartTime();
    int getpilotID();
    int getplaneID();
    int getcopilotID();
    int getcrewID(int i);
    int getpassNum();
    int getStatus();    
    
    Flight()
    {
      sac = "N/A";
      eac = "N/A";
      tailNum = "N/A";
      pilotID = 0;
      planeID = 0;
      copilotID = 0;
      crewID[0, 1, 2] = 0;
      passNum = 0;
      status = 0;
    }
};