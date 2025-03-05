#include <iostream>
#include <vector>
using namespace std;

int f(vector <int> arr,int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<pivot && i <= high){
            i++;
        }
        while(arr[j]>pivot && j <= low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}


void quick_sort(vector <int> arr,int low, int high){
    if(low<high){
        int partition = f(arr,low,high);
        quick_sort(arr,low,partition-1);
        quick_sort(arr,partition+1,high);
    }
}

int main(){
    vector<int> arr = {2,324,3478,25,3,6,4,6,4,57,65,8,7,59,789,57,5,3,4534,1};
    int low = 0;
    int high = arr.size()-1;
    quick_sort(arr,low,high);

    return 0;
}