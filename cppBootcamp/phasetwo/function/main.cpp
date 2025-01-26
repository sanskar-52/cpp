//Call by value

#include <iostream>
using namespace std;

void lifeup(int life){
    ++life;
}

int main(){

    int life = 3;
    lifeup(life);
    cout << life << endl;

    return 0;
}