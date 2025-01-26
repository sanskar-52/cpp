
#include <iostream>
#include <string>
using namespace std;


class User{
    int secret = 22;

public:
    string name = "default";
    void classMessage(){cout << "Class is great," << name << endl;}
};





int main(){

    User sam;
    sam.name = "Sam";
    sam.classMessage();
    // sam.secret = 23;

    User sanskar;
    sanskar.classMessage();
    sanskar.name = "sanskar";
    sanskar.classMessage();


    return 0;
}
