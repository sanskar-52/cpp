#include <iostream>
using namespace std;

void insertion_sort(int arr[],int n){
    int count = 0;
    for(int i = 1;i < n;i++){
        count++;
        int j = i;
        while(j > 0 && (arr[j] < arr[j-1])){        //check i > 0 first. nahi to agar i==0 hoga to condition me arr[i-1] == arr[-1] ho jayega,that will lead to undefined behaviour.
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }
    cout << "count is: " << count <<endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0; i < n ; i++){
        cin >> arr[i];
    }

    insertion_sort(arr,n);

    for(int i =0; i < n;i++){
        cout << arr[i] << endl;
    }

    return 0;
}