#include <iostream>
#include <string>
using namespace std;

void swap(int &a,int &b){
    int tmp = move(a);
    a = move(b);
    b = move(tmp);
}

int main()
{
    int a = 3;
    int b = 4;

    swap(a,b);
    cout << "A: " <<a << endl;   
    return 0;
}