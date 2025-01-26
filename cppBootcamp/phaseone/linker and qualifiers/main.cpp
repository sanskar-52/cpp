#include <iostream>

using namespace std;

int lifeup(){
    static int life = 3;
    return life = life + 1;
}
//post fix operation = first use variable and then do all updates for ex:- life++

//pre fix operator = increment first then use variable [++life]
//++life is more efficient 

int main() {
    int life = 3; //what if we declare static int here instead of in lifeup() function
    cout << "your starting hearts is: " << life << endl;
    
    life = lifeup();
    printf("your updated hearts is %d\n",life);

    life = lifeup();
    printf("your updated hearts is %d\n",life);

}