//select minimum and swap
//select the next minimum and swap
//swap at index 0, and min index
//next swap at index 1 and min index

#include <iostream>
using namespace std;

void selection_sort(int arr[] , int n){

    for(int i =0; i < n-1; i++){
        int min = i;
        for(int j = i; j < n ; j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[i],arr[min]);
        
    }
}

void bubble_sort(int arr[],int n){
    for(int i = n-1; i >= 1; i--){
        int didSwap = 0;
        for(int j = 0; j < i ;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        cout << "runs" <<endl;
        if(!didSwap) break;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i <n ; i++) cin >> arr[i];
    bubble_sort(arr,n);

    for(int i = 0; i < n ;i++){
        cout << arr[i] <<endl;
    }
    return 0;
}