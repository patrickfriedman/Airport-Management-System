//Patrick Friedman 
//patrickfriedman@my.unt.edu 
//CSCE 1040
//November 26, 2018 
//This program is a system for the Mean Green Airline Application. 

#include "Header.h" 

int main() 
{ 
  system("clear");      //clears compiler
  void header();      //declares header
  void Input(int &num, string text, string error = "Input must be a Number.\n");      //declares read function
  
  int option, s, a, e, p, d, f;       //intitialize data
  
  Planes Plane; 
  CrewMembers CrewMember;         //call structs in main
  Flights Flight; 
  
  header();       //print header
  Plane.Load();
  CrewMember.Load();   //Loads all previous data
  Flight.Load();
  
  while (option != 0)       //cancels if choice = 0
  { 
    cout << "Pick an option.\n"; 
    cout << "0. Quit\n" 
         << "1. Add\n" 
         << "2. Edit\n"           //prompt choice
         << "3. Search/Find\n" 
         << "4. Delete\n" 
         << "5. Print\n"; 
    
    Input(option, "\nEnter your Selection: ");    //read in option
    switch (option)
    {
      case 0: cout << "Quit.\n\n"; 
        return 0;     //ends code
        break;
        
      case 1: 
        cout << "Add\n\n"; 
        Input(a, "1. Add Planes\t\t2. Add Crew\t\t3. Add Flights\nEnter your Selection: ");     //read in a 
        
        switch (a) 
        { 
          case 1: 
            cout << "Add Planes\n\n"; 
            Plane.addPlane();             //add plane function
            break; 
          
          case 2: 
            cout << "Add Crew\n\n"; 
            CrewMember.addCrew();       //add crew function
            break; 
          
          case 3: 
            cout << "Add Flights\n\n"; 
            Flight.addFlight();     ///add flight function
            break; 
          
          default: 
            cout << "Error.\n\n"; 
            break; 
        }
        break; 
      
      case 2: 
        cout << "Edit\n\n"; 
        Input(e, "1. Edit Planes\t\t2. Edit Crew\t\t3. Edit Flights\nEnter your Selection: ");      //read in e
        switch (e) 
        { 
          case 1: 
            cout << "Edit Planes\n\n"; 
            Plane.editPlane();        //edit plane function
            break; 
          
          case 2: 
            cout << "Edit Crew\n\n"; 
            CrewMember.editCrew();        //edit crew function
            break; 
          
          case 3: 
            cout << "Edit Flights\n\n"; 
            Flight.editFlight();            //edit flight function
            break;
            
          default: 
            cout << "Error.\n\n"; 
            break; 
        } 
        break; 
      
      case 3: 
        cout << "Search/Find\n\n"; 
        Input(f, "1. Search/Find Planes\t\t2. Search/Find Crew\t\t3. Search Flights\nEnter your Selection: ");    //read in f
        
        switch (f) 
        { 
          case 1: 
            cout << "Search/Find Planes\n\n"; 
            Plane.searchPlane();       //search plane function
            break;       
            
          case 2: 
            cout << "Search/Find Crew\n\n"; 
            CrewMember.searchCrew();            //search crew function
            break;
            
          case 3: 
            cout << "Search/Find Flights\n\n"; 
            Flight.searchFlight();            //search flight function
            break; 
          
          default: 
            cout << "Error.\n\n"; 
            break;
        } 
        break; 
      
      case 4: 
        cout << "Delete\n\n"; 
        Input(d, "1. Delete Planes\t\t2. Delete Crew\t\t3. Delete Flights\nEnter your Selection: "); 
        switch (d)
        { 
          case 1: 
            cout << "Delete Planes\n\n"; 
            Plane.deletePlane();            //delete function
            break;
            
          case 2: cout << "Delete Crew\n\n"; 
            CrewMember.deleteCrew(); //delete function
            break; 
            
          case 3: 
            cout << "Delete Flights\n\n"; 
            Flight.deleteFlight();          //delete function
            break; 
            
          default: 
            cout << "Error.\n\n"; 
            break; 
        } 
        break; 
      
      case 5: 
        cout << "Print\n\n"; 
        Input(p, "1. Print Planes\t\t2. Print Crew\t\t3. Print Flights\nEnter your Selection: "); 
        switch (p) 
        { 
          case 1: 
            cout << "Print Planes\n\n"; 
            
            Input(s, "1. Print Single\t\t2. Print All\t\t\nEnter your Selection: ");          //read in s 
                
            if (s == 1)
            {
              cout << endl;
              Plane.searchPlane();                //prints 1
              break;
            }
            else if (s == 2)
            {
              cout << endl;
              Plane.printPlane(); //print all
              break; 
            }
            else
            {
              cout << "Error.\n\n"; 
              break; 
            }
            break;
          
          case 2: 
            cout << "Print Crew\n\n"; 
            
            Input(s, "1. Print Single\t\t2. Print All\t\t\nEnter your Selection: "); 
            
            if (s == 1)
            {
              cout << endl;
              CrewMember.searchCrew();      //print 1
              break;
            }
            else if (s == 2)
            {
              cout << endl;
              CrewMember.printCrew();       //print all
              break;
            }
            else
            {
              cout << "Error.\n\n"; 
              break; 
            }
            break; 
          
          case 3: 
            cout << "Print Flights\n\n"; 
            
            Input(s, "1. Print Single\t\t2. Print All\t\t\nEnter your Selection: "); 
            
            if (s == 1)
            {
              cout << endl;
              Flight.searchFlight();        //print all
              break;    
            }
            else if (s == 2)
            {
              cout << endl;
              Flight.printFlight();         //print all
              break;
            }
            else
            {
              cout << "Error.\n\n"; 
              break; 
            }
            break; 
          
          default: 
            cout << "Error.\n\n"; 
            break; 
        } 
        break; 
      
      default: 
        cout << "Error, try again.\n\n"; 
        continue; 
    } 
  } 
  
  Plane.clearPlane(); 
  CrewMember.clearCrew();       //dealocates space in vectors
  Flight.clearFlight(); 
} 

void header() 
{ 
	cout << "+--------------------------------------------------------+" << endl;
	cout << "|            Computer Science and Engineering            |" << endl;
	cout << "|             CSCE 1040 - Computer Science II            |" << endl;
	cout << "|   Patrick Friedman     psf0023    psf0023@my.unt.edu   |" << endl;
	cout << "+--------------------------------------------------------+" << endl;
  cout << endl;
  
  cout << "\t +--------------------------------------+" << endl; 
  cout << "\t |           ***Mean Green***           |" << endl; 
  cout << "\t |            ***Airlines***            |" << endl; 
  cout << "\t +--------------------------------------+" << endl; 
  cout << endl; 
  return; 
}