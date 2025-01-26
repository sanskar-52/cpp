#include <iostream>
using namespace std;

int main() {

    unsigned int x = 6;
    unsigned int y = 723;

    unsigned int z = x & y; //bitwise and operator
    unsigned int a = x | y; //bitwise or operator
    unsigned int b = x ^ y; //bitwise xor operator
    unsigned int c = ~y;    //bitwise not operator
    unsigned int d = x >> 1;//bitwise right shift operation [right shift of one]
    unsigned int e = x << 1;//bitwise left shift operation [left shift of one]

    printf("the value of z is: %u\n",z);


    return 0;
}