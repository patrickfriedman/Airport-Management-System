#include <iostream>
#include <string>
using namespace std;

class Plane
{
  private:
    string make, model, tailNum; 
    int seatNum, range, status;

  public:
    void setMake(string newMake);    
    void setModel(string newModel);    
    void settailNum(string newtailNum);    
    void setStatus(int newStatus);    
    void setseatNum(int newseatNum);    
    void setRange(int newRange);    
    
    Plane();
    Plane(string mk, string mdl, string tn, int sn, int r, int s);
    
    string getMake();
    string getModel();
    string gettailNum();
    int getStatus();
    int getseatNum();
    int getRange();
};