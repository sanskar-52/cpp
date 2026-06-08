#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void printNumbers(int id)
{
  lock_guard<mutex> lock(mtx);
  for (int i = 1; i <= 1000; i++)
  {
    cout << "Thread" << id << " : " << i << "\n";
  }
}

int main()
{
  thread t1(printNumbers, 1);
  thread t2(printNumbers, 2);
  t1.join();
  t2.join();
  return 0;
}
