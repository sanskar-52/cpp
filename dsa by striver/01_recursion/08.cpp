//parameterised and functional way
//sum of first n number by functional way

#include <iostream>
using namespace std;

int f(int n){
    if(n == 0) return 0;
    return (n + f(n-1));
}

int main(){
    int n;
    cin >> n;

    cout << f(n) <<endl;
}