//pair sum
//return pair in sorted array with target sum.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {2,7,11,15};
    int target = 9;
    vector<int> ans;
    for (int i = 0; i < 4 ; i++){
        for (int j =i + 1 ; j < 4 ; j++){
            if (arr[i] + arr[j] == target){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }
    cout << ans[0] <<" ans "<< ans[1] <<endl;
    return 0;
}