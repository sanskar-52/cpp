//pair sum optimised
//two pointer approach
//array are sorted
//finding only one pair

#include <iostream>
#include <vector>
using namespace std;

vector<int> PairSum(vector<int> nums, int target){
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n-1;

    while (i < j)
    {
        int PairSum = nums[i] + nums[j];
        if(PairSum > target){j--;}
        else if(PairSum < target){i++;}
        else{
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            break;
        }
        
    }
    return ans;
    

}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 18;

    vector<int> ans = PairSum(nums, target);
    cout << ans[0] << " and " << ans[1] <<endl;
    return 0;
}