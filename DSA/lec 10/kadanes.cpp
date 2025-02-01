//maximumn subarray sum by kadane's algorithm

#include <iostream>
using namespace std;

int main()
{
    int arr[]={3,-4,5,4,-1,7,-8};
    int currsum = 0;
    int maxsum = INT8_MIN;
    for (int i = 0;i < 7 ; i++){
        currsum += arr[i];
        maxsum = max(currsum,maxsum);

        if (currsum < 0){currsum = 0;}
    }
    cout << "maximum subarray sum is: " << maxsum << endl;

    return 0;
}