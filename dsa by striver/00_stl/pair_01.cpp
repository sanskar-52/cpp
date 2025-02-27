#include <iostream>
using namespace std;

int main(){
    pair<int, int> p = {1,3};
    cout << p.first << " " << p.second <<endl;

    //how to store 3 variable in a pair?
    pair<int , pair<int,int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    //array of pairs
    pair<int, int> arr[] = {{1,2},{4,5},{6,7}};
    for(int i =0; i < 3 ; i++){
        //cout << arr[i] <<endl;   you cant access the pair array like this
        cout << arr[i].first << " <- 1st and the second element is -> " << arr[i].second << endl;
    }

    return 0;
}