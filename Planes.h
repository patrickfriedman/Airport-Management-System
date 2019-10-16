#include <vector>
using namespace std;

class Planes
{
  private:
    vector<Plane> planeList;
    
  public:
    int findPlane();
    void Save();
    void Load();
    void availPlane(string tailNum);
    void addPlane();
    void searchPlane();
    void editPlane();
    void printPlane();
    void deletePlane();
    void clearPlane();
};