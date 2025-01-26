#include <iostream>
using namespace std;

struct User{
    const int uId;     //uId is constant and it can not be changed
    const char *name;  //pointer for the name is constant not the name so it can be changed
    const char *email; //pointer for the email is constant not the email so it can be changed
    int course_count;
};

int main() {

    User mickey = {001, "mickey", "mickey@gmail.com", 2};
    cout << "course count of mickey is " << mickey.course_count << endl;
    mickey.course_count = 23;
    cout << "after studying a lot mickey course count went up to " << mickey.course_count <<endl;


    User donald = {002, "donald", "donald@usa.com" , 9};
    User * d = &donald;
    cout << "value of *d = When you dereference a pointer like *d, you are asking for the entire object that the pointer refers to (in this case, the User struct)\n";
    cout << "so how do you access the element of User donanld by using pointer [d->]" << endl;
    cout << d->email << endl;
    d->email = "d&d@macdonald.com";
    cout << "new email of donald is " << d->email << endl;
    return 0;
}