//null pointer

#include <iostream>
using namespace std;
// #define NULL 0 //this will make printval(NULL) to go throgh printval(int a) instead of printval(int *a)

void printval(int a){
    printf("Integer value is %d\n",a);
}

void printval(double a){
    printf("Double value is %f\n",a);
}

void printval(int* a){
    printf("Pointer value is %p\n",a);
}
int main() {

    printval(237);
    printval(5.476);
    // printval(NULL);
    printval(nullptr);
    return 0;
}