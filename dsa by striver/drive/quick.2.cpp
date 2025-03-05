#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector <int> arr = {9819,142,67,24,1,34,63,6,3,7,35,21,13,1,3,65,8,9,7,35,8,64,8,9};
    int pivot = 0;
    int i = 0;
    int j = arr.size() -1;
    while(i<j){
        while(arr[i]< arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }
        if(i < j) {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    int partition = j;
}