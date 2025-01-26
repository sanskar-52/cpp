#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////

// int main(){
//     cout << "Hello There" << endl;


//     return 0;
//     cout << "Hello There 2nd time" << endl;
//     //anything after return 0; will not be executed
// }

////////////////////////////////////////////////////////////////////////////////////


//IDENTIFIERS (c++ is case sensitive,can not use number in front,you can use underscore for space, can not use reserved keywords,dont go beyond 31 characters)
//_ at start means private, __ means system keyword

// int main(){
//     int number = 0; //Declare and initialize
//     cin >> number;
//     printf("your id is %d\n",number +3);
// }

//////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
    string my_colour;
    cout << "Enter your fav color:";
    // cin >> my_colour;   //cin >> my_colour; will only capture the first word up to the first whitespace.
    // cout << my_colour <<endl;

    //to capture the entire line of the input including space you have to use std::getline() instead of std::cin
    getline(cin,my_colour);
    cout << "hey " << my_colour << " is my fav color too" <<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
