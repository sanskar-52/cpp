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
        shared_ptr<User> tim = make_shared<User>();
        shared_ptr<User> sim = tim;
        weak_ptr<User> wtim = tim;
        //when all the shared pointer done with their job then memory will be freed up.
    }

    return 0;
}