#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
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
    for(int i = 0;i <temp.size();i++){
        arr[low + i] = temp[i];
    }

    return;
}


void merge_sort(vector <int> &arr,int low,int high){
    if(low==high) return;
    int mid = (low + high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

int main(){
    vector <int> vec = {12,31,23,1,23,124,421,235,3,5,34,15,34,5,345,3};
    int low = 0;
    int high = vec.size() - 1;

    merge_sort(vec,low,high);

    for(int n: vec){
        cout << n << endl;
    }




    return 0;
}
