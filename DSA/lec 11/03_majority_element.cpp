//majority element
//it is the element that appears more than n/2 times.
//brute force
#include <iostream>
#include <vector>
using namespace std;

int MajorityElement(vector<int> nums){
    int n = (nums.size())/2;
    for (int value : nums){
        int frequency = 0;
        for (int d : nums){
            if (d == value){frequency++;}
        }
        if(frequency > n){
            return value;
        }
    }
}


int main(){
    vector<int> nums = {1,2,3,4,1,1,1,2,2,2,2,2,2,2,1};
    int ans = MajorityElement(nums);
    cout << ans;
    return 0;
}