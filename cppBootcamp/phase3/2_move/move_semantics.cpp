#include <iostream>
#include <string>
using namespace std;

void swap(int &a,int &b){
    int tmp = move(a);
    a = move(b);
    b = move(tmp);
}

string printme(){
    return "i am print";
}

int main()
{
    // int a = 3;
    // int b = 4;

    // swap(a,b);
    // cout << "A: " <<a << endl;   

    string s = printme();

    string&& ss = printme();

    // With normal variables (s): The returned temporary is copied into s. The temporary object is then destroyed.
    // With rvalue references (ss): The temporary object is directly referenced by ss. No new object is created or destroyed.

    // While ss is in scope: The temporary object is alive.
    // When ss goes out of scope: The temporary object is destroyed.

    return 0;
}