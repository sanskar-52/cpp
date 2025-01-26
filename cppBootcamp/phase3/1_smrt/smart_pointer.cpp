#include <iostream>
#include <string>
#include <memory>
using namespace std;

class User{
public:
    User(){
        cout << "User constructed" <<endl;
    }
    ~User(){
        cout << "User destroyed" << endl;
    }
    void testfunc(){
        cout << "i am a test func" <<endl;
    }
};

int main()
{


    {
        // unique_ptr<User> sam(new User());

        unique_ptr<User> Sam = make_unique<User>();


    }


    return 0;
}