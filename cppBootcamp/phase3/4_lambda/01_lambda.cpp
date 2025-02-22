#include <iostream>
#include <string>
using namespace std;

int main(){

    []{cout << "hello world" <<endl;}();
    int a = []{return 100;}();      //a is variable because the lambda function runs immediately.
    cout << "value of a is " << a << endl;

    auto b = [](){return 200;};       //b is lambda funtion kyunki lamda funtion immediately run nahi hota hai, isiliye hame baad me function ko call karna padta hai ie b()
    cout << "value of b is " << b() << endl <<endl;          //b() ?? why ?

    auto sum = [](auto a, auto b){return a + b;};

    cout << "sum of 5 and 10 is " << sum(5,10) <<endl;
    cout << "sum of 5.3 and 10.32 is " << sum(5.3,10.32) <<endl;
    cout << "sum of a and b is " << sum(a,b()) <<endl;

    string s1 = "abc";
    string s2 = "def";
    cout << "sum of s1 and s2 is " <<sum(s1,s2) <<endl;

    return 0;
}