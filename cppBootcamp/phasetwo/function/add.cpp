//

#include <iostream>

using namespace std;

template<typename T>

T addme(T a , T b){
    return a + b;
}

int main(){
    int v1= 12;
    int v2= 3;
    float v3 = 1.032;
    float v4 = 43.123;
    cout << addme(v3,v4) << endl;

    return 0;
}