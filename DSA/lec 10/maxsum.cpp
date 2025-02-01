//program to find maximum sub-array sum

#include <iostream>
using namespace std;

int main()
{
    //brute force approach
    int arr[]={3,-4,5,4,-1,7,-8};
    int size = 7;
    int ans = 0;
    for (int start = 0; start < size; start++ ){
        int cs = 0;
        for(int i = start; i < size ; i++ ){
            cs += arr[i];
            if(cs > ans){ans = cs;}
        }
    }
    cout <<"maximum subarray sum is: "<< ans <<endl ;
    return 0;
}