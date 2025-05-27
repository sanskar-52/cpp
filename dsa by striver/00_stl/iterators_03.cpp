#include <iostream>
#include <vector>  // Required for vector and iterator

using namespace std;

int main() {
    // Create a vector of integers
    vector<int> v = {10, 20, 30, 40};

    // Declare an iterator for the vector
    vector<int>::iterator it = v.begin();
    vector<int>::iterator ending = v.end();     //this points to the location after the last position of v vector

    // Use the iterator to access and print the elements of the vector
    cout << "The first element is: " << *it << endl;  // Dereferencing the iterator

    cout << "third element is: " << *(it+2) << endl;


    v.erase(v.begin());

for(auto it = v.begin(); it != v.end();it++){
    cout << *it << endl;
}
    vector <int> chicken = {10, 20 ,30 ,40 ,50, 60 ,70};

    chicken.erase(chicken.begin(),chicken.end());
    for(int each:chicken){
        cout << each << endl;
    }
    chicken.insert(chicken.begin(),300);   //{300}
    chicken.insert(chicken.begin()+1,2,600);  //{300,600,600}

    vector<int> copy(2,50);

    chicken.insert(chicken.begin(),copy.begin(),copy.end());

    return 0;
}   
