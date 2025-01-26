#include <iostream>
using namespace std;

int main(){
    const int life = 4;  //const int does not allow to change the value of the variable after Initialising it

    int card;
    card = 40;
    int my_card = card;

    printf("1. value of the card is %d\n",my_card);

    int *myp;   //intialising pointer
    myp =  &card;
    std::cout << "2." << myp << " is the address of card and the value of card is " << *myp <<endl;
    printf("3. address of card is %p\n",myp);
    printf("4. address of my_card is %p\n",&my_card);

    //*mpy "*" is used in intialising the pointer
    //after that *myp will ressemble the value stored in the address
    //pointer declare karne ke baad agar * ke sath variable ko likhenge to vo uska value represent karega na ki uska address.

    *myp = 3440;
    printf("5. value of the card is %d and %d",card,*myp);
}