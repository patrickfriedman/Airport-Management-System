#include <vector>
using namespace std;

class CrewMembers
{
  private:
    vector<CrewMember*> crewList;
    
  public:
    int findCrew();
    void Save();
    void Load();
    void availCrew(int id);
    void addCrew();
    void searchCrew();
    void editCrew();
    void printCrew();
    void deleteCrew();
    void clearCrew();
};