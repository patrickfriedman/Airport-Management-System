#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Input(string &str, string text, string error = "Input must be Text.")
{
  do
  {
    if (!cin)
    {
      cin.clear();
      cin.ignore();
      cout << error << endl;
    }
    
    cout << text;
    getline(cin, str);
  } while(!cin);
}

void Input(int &num, string text, string error = "Input must be a Number.")
{
  do
  {
    if (!cin)
    {
      cin.clear();
      cin.ignore();                   //works per character
      cout << error << endl;
    }
    
    cout << text;
    cin >> num;
    
  } while(!cin);
}

void Input(time_t &now, string text)
{
  string error = "Input must be a Number.\n\n";
  string pastError = "Flight cannot be made in the Past.\n\n";
  struct tm userLocal;
  struct tm nowLocal;
  bool avail = true;
  
  now = time(NULL);
  nowLocal = *localtime(&now);
    
  do
  {
    avail = true;
    
    if (!cin)
    {
      cin.clear();
      cin.ignore();                   //works per character
      cout << error << endl;
    }
    
    cout << "Enter the Date(mm dd yy) of the " << text;
    cin >> userLocal.tm_mon >> userLocal.tm_mday >> userLocal.tm_year;

    userLocal.tm_year += 100;
    
    if (userLocal.tm_year < nowLocal.tm_year)
    {
      cout << pastError;
      avail = false;
    }
    else if ((userLocal.tm_year < nowLocal.tm_year) && (userLocal.tm_mon < nowLocal.tm_mon))
    {
      cout << pastError;
      avail = false;
    }
    else if ((userLocal.tm_year < nowLocal.tm_year) && (userLocal.tm_mon < nowLocal.tm_mon) && (userLocal.tm_mday < nowLocal.tm_mday))
    {
      cout << pastError;
      avail = false;
    } 
  } while ((!cin) || (!avail));
  
  do
  {
    avail = true;
    
    if (!cin)
    {
      cin.clear();
      cin.ignore();                   //works per character
      cout << error << endl;
    }
    
    cout << "Enter the Military Time(hh mm) of the " << text;
    cin >> userLocal.tm_hour >> userLocal.tm_min;
    
    if ((userLocal.tm_mon == nowLocal.tm_mon) && (userLocal.tm_year == nowLocal.tm_year) && (nowLocal.tm_mday == userLocal.tm_mday))
    {
      if (userLocal.tm_hour < nowLocal.tm_hour)
      {
        cout << pastError;
        avail = false;
      }
      else if ((userLocal.tm_hour < nowLocal.tm_hour) && (userLocal.tm_min < nowLocal.tm_min))
      {
        cout << pastError;
        avail = false;
      }
    }
  } while ((!cin) || (!avail));

  userLocal.tm_year -= 100;
  now = mktime(&userLocal);
}