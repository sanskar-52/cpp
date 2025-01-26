//when a pointers points towards a function it gets more capability

#include <iostream>

using namespace std;

int getTwo(){
    return 2;
}

void hunger_bar(){
    puts("i am hungry");
}

int main(){
    void (*PointsTowardsIntrst)() = hunger_bar;
    
    cout << *PointsTowardsIntrst << endl;
    PointsTowardsIntrst();
    
    
    // int whatIgot = getTwo();
    
    // cout << whatIgot << endl;
    
    return 0;
}