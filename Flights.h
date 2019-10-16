#include <vector>
#include <ctime>
using namespace std;

class Flights
{
  private:
    vector<Flight> flightList;
    
  public:
    int findFlight();
    void addFlight();
    void Save();
    void Load();
    void availFlight(string sac, string eac);
    void searchFlight();
    void editFlight();
    void printFlight();
    void deleteFlight();
    void clearFlight();
};