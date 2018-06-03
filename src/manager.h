#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Manager()
{
public:
  Manager(string,string);
  ~Manager();
  void PrintMenu();
  void PrintItem();
  void AddMenu();
  void DelMenu();
  void AddItem();
  void DelItem();
private:
  string _name,_number;
}
