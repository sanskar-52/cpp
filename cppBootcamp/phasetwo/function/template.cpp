#include <iostream>
using namespace std;


template<typename A,typename T>
void prt(T t,A a){
    cout << (t + a) << endl;
}

template<typename T>
void prtsqr(T t){
    cout << t*t << endl;
}

template<typename T,typename A>
void process(T t,A a){
    prt(t,a);
    prtsqr(t);
    prtsqr(a);
}

int main(){
    int a = 123;
    int b = 12;
    double c = 12.5;
    // prt(a,b);
    process(b,c);


    return 0;
}