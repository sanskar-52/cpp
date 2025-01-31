#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> say;
    say.push_back(0);
    say.push_back(1);
    say.push_back(2);
    
    cout << say.size() << endl;//3
    cout << say.capacity() << endl;//4

    say.push_back(3); //size and capacity of array will be 4

    say.push_back(4); //size = 5 capacity = 8

    cout << say.size() << endl;
    cout << say.capacity() <<endl;

    //xor  n^n = 0 and n ^ 0 = n repeatation will be cancelled by xor
}
