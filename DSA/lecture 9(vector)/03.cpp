//finding unique number in an array if every other element exist as a pair
//by using xor the element pairs will get cancelled n^n= 0 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> stuff = {1,1,0,0,1,12,1};
    int ans = 0;
    for(int i : stuff){
        ans = ans ^ i;
    }

    cout << ans << endl;
}