#include <iostream>
#include <string>
using namespace std;

class CrewMember
{
  protected:
    string name;
    int id, status;

  public:
    void setName(string newName);    
    void setID(int newID);    
    void setStatus(int newStatus);
        
    string getName();
    int getID();
    int getStatus();
    
    virtual void Print();
};

class Pilot: public CrewMember
{
  private:
    string rate;
    int hours;

  public:
    void setRate(string newRate);    
    void setHours(int newHours);    
    void Print();
    
    Pilot(string n, int ID, int s, string r, int h);
    
    string getRate();
    int getHours();
    
    Pilot()
    {
      rate = "N/A";
      hours = 0;
    }
};

class CoPilot: public CrewMember
{
  private:
    string crate;
    int chours;

  public:
    void setCRate(string newCRate);    
    void setCHours(int newCHours);    
    void Print();
    
    CoPilot(string n, int ID, int s, string r, int h);
    
    string getCRate();
    int getCHours();
    
    CoPilot()
    {
      crate = "N/A";
      chours = 0;
    }
};

class Cabin: public CrewMember
{
  private:
    int type;
  
  public:
    void setType(int type);
    void Print();
    
    Cabin(string n, int ID, int s, int t);
    
    int getType();
};