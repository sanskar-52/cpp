#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //i will try to learn methods of vector in this code.

    vector<int> inty = {1,2,3};

    //type 1 capacity
    inty.size(); //returns the number of element in the vector. 
    inty.capacity(); //return the capacity of vector. num of element it can hold before resizing.
    inty.empty();//output: 0 (false)
    inty.resize(5); //resizes the vector to hold n elements. 
    // Vector now has 5 elements, default-initialized

    cout << "5th element of vector is " << inty[4] <<endl; //5th element of inty vector

    inty.reserve(7); //increases vector capacity to atleast n. (doesn’t change size).

    //modifiers
    inty.push_back(4);
    inty.pop_back();

    inty.insert(inty.begin(),0); //insert 0 at the beginning.
    inty.erase(inty.begin());    //removes the first element.

    inty.clear();   //removes all element from the vector.

    cout << "size of vector after inty.clear() is: " << inty.size() <<endl;

    vector<int> v2 = { 10 ,20 ,30, 040};
    inty.swap(v2);

    cout << "size of vector after swapping it with vector v2 is: " << inty.size() << endl;
    cout << "4th element of inty is: " << inty[3] << endl;

    return 0;
}