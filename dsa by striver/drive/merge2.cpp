#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector <int> &arr,int low,int high){
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);

    int left = low;
    int right = mid + 1;
    vector <int> temp;
    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
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
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = 0; i < temp.size();i++){
        arr[low+i] = temp[i];
    }
    return;
}


int main(){
    vector <int> arr = {797,42,34,2,64,7,5,68,8,6,7,85,53,4,2,4,3,214,8,67,86};
    int low = 0;
    int high = arr.size()-1;
    merge_sort(arr,low,high);

    for(int n:arr){
        cout << n << endl;
    }
    return 0;
}