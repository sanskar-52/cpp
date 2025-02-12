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
        Sam->testfunc();

        // unique_ptr<User> tam = Sam;   this does not work. both tam and sam can not points to the same object of type User.
        //agar traditional pointer hota instead of unique pointer to ye allowed hota and both tam and same could points to same obj.

        //int *ptr2 = ptr1; //iska matlab hua ki int pointer ptr2 me ptr1 me jo address store hai vo assign kar do.

    }

    cout << "outside code\n";


    return 0;
}