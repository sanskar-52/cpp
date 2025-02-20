//print 1 to N          if N = 4 THEN 1 2 3 4
#include <iostream>
using namespace std;

void series(int i,int n){
    if (i > n) return;
    cout << i << endl;
    series(i+1,n);

}

int main(){
    int n;
    cout << "enter n" << endl;
    cin >> n;

    series(1,n);

    return 0;
}