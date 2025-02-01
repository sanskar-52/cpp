//maximum subarray sum
//kadane's algo
//subarray is a continous part of array
//total number of subarray if the size is n = n*(n+1)/2
//each subray is continous so it can be defined from starting point to the ending part of array

#include <iostream>
using namespace std;

int main(){
    
    int arr[] = {1,2,3,4,5};
    int n = 5;
    for(int st = 0; st < n ; st++ ){
        for(int end=st; end< n ; end++){
            for(int i = st;i <= end;i++){
                cout << arr[i];
            }
            cout << " " ;
        }
        cout << endl;
    }
}