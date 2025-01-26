//recusrion
#include <iostream>

int factorial(int n);

int main(){
    //factorial : 5 x 4 x 3 x 2 x 1
    //factorial : 1 x 2 x 3 x 4 x 5
int n;

std::cout << "Enter a value : ";
std::cin >> n;

std::cout << "your result for factorial is: " << factorial(n) << std::endl;

    return 0;
}

int factorial(int n){
    if (n > 1){
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}