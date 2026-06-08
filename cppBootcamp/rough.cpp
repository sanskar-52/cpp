#include <iostream>
using namespace std;

class Car
{
public:
  void drive()
  {
    cout << "Car driving\n";
  }
  int x = 12;
  void prnt() { cout << x; }
};

class SUV : public Car
{
public:
  void drive()
  {
    cout << "SUV driving\n";
  }
  int x = 2;
  void prnt() { cout << x; }
};

int main()
{
  Car *suv1 = new SUV;
  suv1->drive();
  suv1->prnt();
}