//now i am going to reverse an array using one pointer

#include <iostream>
using namespace std;

void reverse(int i,int arr[],int n){
    if(i >= n/2) return;
    swap(arr[i],arr[n-1-i]);
    reverse(i+1,arr,n);
}

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }

    cout << "printing reverse array" << endl;
    reverse(0,arr,n);
    for(int i =0;i < n; i++){
        cout << arr[i] << endl;
    }



    return 0;
}