//majority element
//optimized way
//arrays are sorted.

//? how to sort an array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MajorityElement(vector<int> nums){

    int n = nums.size();
    int m = (nums.size())/2;


    int freq = 1;
    for(int i= 1; i < n; i++){
        if(nums[i] == nums[i-1]){
            freq++;
            if(freq > m){return nums[i];}
        }
        else{freq = 1;}
    }
    return -1;

}

int main(){
    vector<int> nums = {1,2,3,4,5,5,5,5,5,5,5,12,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
    //sorting the array
    sort(nums.begin(), nums.end());

    int ans = MajorityElement(nums);

    cout << ans << endl;
    return 0;
}