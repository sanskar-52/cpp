//how to sort 0's 1's and 2's
//https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {0,2,1,1,1,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,1,2};
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i:arr){
        if(i == 0) cnt0++;
        else if ( i == 1) cnt1++;
        else cnt2++;
    }

    for(int i =0 ; i < cnt0 ; i++){
        arr[i] = 0;
    }
    for(int i = cnt0; i < cnt1;i++){
        arr[i] = 1;
    }

    for(int i = cnt1; i <cnt2;i++){
        arr[i] = 2;
    }

    for(int x:arr){
        cout << x << endl;
    }


}