//finding second largest and second smallest number in an array
//this is optimal way of findind s smallest and s largest element.



#include <iostream>
#include <vector>
using namespace std;
//think about iterating over [3 4 3]
//iterating over value -> chote se bada aur phir bade se chota 
int second_largest(vector<int> &arr,int n){
    int slargest = INT16_MIN;
    int largest = arr[0];
    for (int i = 1; i < n ; i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    cout << "largest in array is " << largest <<endl;
    return slargest;
}

int second_smallest(vector <int> &arr , int n){
    int ssmallest = INT16_MAX;;                 //when array contains +ve numbers.
    int smallest =  arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]<ssmallest && arr[i]!=smallest){
            ssmallest = arr[i];
        }
    }

    cout << "smallest in array is " << smallest <<endl;
    return ssmallest;
}


int main(){
    vector<int> arr = {1,23,12,3,12,3,5,3,4,634,57,4,56,5,67,34,5,3,452,5,3,4,3,54,23,4,32,5,24,63,57,435,8,999,999,-12,-12};
    int n = arr.size();
    int slarget = second_largest(arr,n);
    int ssmallest = second_smallest(arr,n);
    cout << "second largest:"<< slarget << endl;
    cout << "second smallest:"<< ssmallest << endl;
}