//printing in reverse fashion
#include <iostream>
using namespace std;

void series(int n){
    if (n == 0) return;
    cout << n << endl;
    series(n-1);
}

int main(){
    int n;
    cout << "enter n: ";
    cin >> n;

    series(n);
    
    return 0;
}