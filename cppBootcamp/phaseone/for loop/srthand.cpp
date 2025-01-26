//short hand notation used for loop

#include <iostream>
using namespace std;

int main() {
    // char c = 'h';
    // cout << c ;

    char string[] = {"hari"};  //array of an character 
    printf("harry's full name is %s.\n",string);
    
    char name[] = {'h','a','r','i', 0 };
    cout << "take a break\n";
    cout << name << endl;

    for(int i = 0; name[i] ;i++){
        cout << "character is " << name[i] << endl;

    }
    cout << "do the same as above but using pointers and pointers dereferencing using for loop\n";

    for(char *p = name ; *p ; p++){
        cout << "character is " << *p << endl;
    }
    return 0;
}