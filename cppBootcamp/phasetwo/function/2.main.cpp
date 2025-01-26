//call by reference

#include <iostream>
using namespace std;

// void lifeup(int *life){
//     ++(*life);
// }

// int main(){
//     int life = 3;
//     lifeup(&life);
//     cout << life << endl;

//     return 0;
// }


//call by value but the function definition is different

void lifeup(int &life){
    ++life;
}

int main(){
    int life = 3;
    lifeup(life);
    cout << life << endl;
    return 0;
}