//print name n time by recursion

#include <iostream>
#include <string>
using namespace std;

int count = 1;
string name = "sanskar";

int print(int n){
    if (count > n) return 0;
    else{
        cout << name << " " << count <<endl;
        count++;
    }
    print(n);
}


int main(){

    int n = 10;
    
    print(n);

    return 0;
}