// print from 1 to N. by backtracking

#include <iostream>
using namespace std;

void f(int i){
    if (i < 1) return;
    f(i -1);
    cout << i << endl;
}

int main(){
    int i;
    cin >> i;

    f(i);

    return 0;
}