#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the size of arr[i]: ";   
    cin >> n;
    int arr[n];
    cout << "enter each element at a time" << endl;
    for(int i = 0; i < n; i++){
        cout << i << "th index element: ";
        cin >> arr[i];
        // cout << endl;
    }    

    //precompute

    int hash[100000] = {0};  //12 be the max of arr[i] , 13 size ka hash[] to get the index 12 which is max of arr[i]
    for(int i= 0; i < n; i++){
        hash[arr[i]] += 1;
    }



    int q;      //q be the number of element jo kisi array me kitne baar aata ho.
    cin >> q;
    while(q--){
        int number;
        cout << "enter the number which u want to count in arr[i]: "; 
        cin >> number;
        //fetch

        printf("number of times %d appear in arr[i] is: %d\n" ,number  ,hash[number] );


    }

    return 0;
}