#include <iostream>
#include <vector>
using namespace std;

struct corners{
    float a, b, c, d;
};

int main(){

    vector<int> inty;

    inty.push_back(2);
    inty.push_back(4);
    inty.push_back(8);
    inty.push_back(16);
    inty.push_back(32);
 
    //i=inty.begin(); is the reference to the begin 
    //i = inty.end(); is the reference to the end
    for(auto i = inty.begin(); i != inty.end(); ++i){
        cout << *i << endl; //thats why we can dereference it.
    }

    vector<corners> corners;
    //ek vector hai corn naam se jo store karta hai objects of struct corners.

    corners.push_back({1,2,3,4});
    corners.push_back({5,6,7,8});

    cout << "size of vector corners is " << corners.size() << endl <<endl; 

    cout << "third element of first object stored in vector is " << corners[0].c << endl;
    cout << "second element of second object stored in vector is " << corners[1].b << endl <<endl;
 

    // for(int i = 0; i < corners.size();++i){               this can be done to access all object stored in corners vector by using operator over riding
    //     cout << corners[i] << endl;                          but i didnt include that part bcz i didnt understand a single thing, might check it later.
    // }

    return 0;
}