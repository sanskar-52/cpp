// vetctors are array like index start from 0 1 2 so on and so on
// vectors are dynamic in nature
// container of standard template library
//array size is fixed that is the isssue
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1,2,3};
    cout << "value of vector vec[0] is :"<< vec[0] <<endl;

    vector <int> seco(12,81); //in seco vector there will be 12 elements and each element is 81;
    //for each loop
    //type of iterator should be same as the type of data which is stored in vector
    for(int value : seco){
        cout << value << endl;
    }

    //functions of vector
    //1
    cout << "size of vector seco is: " << seco.size() << endl;
    //push back same as append

    seco.push_back(12);
    seco.push_back(24);
    seco.push_back(48);

    cout << "size of vector seco after push back is: " << seco.size() << endl;

    //pop back last element
    seco.pop_back();
    cout << "size of vector seco after pop back is: " << seco.size() << endl;

    //front and back

    cout << seco.front() << " and " << seco.back() <<endl;
    //at 
    cout << seco.at(13) << endl;
    return 0;
}