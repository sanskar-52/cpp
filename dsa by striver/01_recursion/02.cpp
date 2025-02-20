//without global variable
#include <iostream>
#include <string>
using namespace std;

void name(int i,int n){
    if (i > n) return;
    printf("sanskar\n");
    name(i + 1,n);
}


int main(){
    int n;
    cout << "enter n" << endl;
    cin >> n;

    name(1,n);

    return 0;
}