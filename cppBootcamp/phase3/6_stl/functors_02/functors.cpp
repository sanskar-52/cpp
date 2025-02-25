//operators overloading
#include <iostream>
using namespace std;

class MyFloat{
    float ft;
public:
    MyFloat(){
        ft = 0.1;
    }
    
    void getvalue(){
        cout << ft << endl;
    }

    void operator ()(float v){
        ft += v;
    }

};

int main(){

    MyFloat floaty;
    floaty.getvalue();
    
    //floaty is a class object and we are calling it as if it were a fucntion
    floaty(0.1);
    floaty.getvalue();

    floaty(1);
    floaty.getvalue();

    return 0;
}