//merge sort me divide and conquer
//pahle divide then sort then return to merge

#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[],int min,int mid,int high){
    vector<int> temp;
    int left = min;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[high]);
    }
    for(int i = min; i <= high;i++){
        arr[i] = temp[i - min];
    }
    
}

void merge_sort(int arr[],int low,int high){
    int mid = (high + low)/2;
    if(low == high) return;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);

}


int main()
{
    int arr[] = {12,1,23,1,23,1,2412,4,23,74,35,3,564,231,74,745};
    
    
    return 0;
}