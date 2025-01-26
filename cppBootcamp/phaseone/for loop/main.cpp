
#include <iostream>

using namespace std;

int main(){

    int my_numbs[] = {2,3,4,5,6};
    for(int i = 0;i < 5 ; i++){
        cout << my_numbs[i] << endl;
    }
    

    //for each loop or for ranged loop
    cout << "take a break\n";
    for (int i:my_numbs){
        cout << i << endl;
    }

    
    
    return 0;
}