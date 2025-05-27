//reverse a array by two variable using recusrion

#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int l,int r,int *arr){
    if (l>=r) return;
    swap(&arr[l],&arr[r]);
    reverse(l+1,r-1,arr);

}

int main(){
    int n;
    cout << "enter the size of array: ";
    cin >> n;
    cout << "eneter the elements one by one: ";
    
    int arr[n];
    for(int i =0; i < n; i++) cin >> arr[i];


    //calling the reverse function
    reverse(0,n-1,arr);

    //printing the reverse array
    cout << "printing the reverse array" << endl;
    for(int i =0;i < n; i++){
        cout << arr[i] << endl;
    }
    


    return 0;
}