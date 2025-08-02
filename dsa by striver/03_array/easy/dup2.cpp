#include <iostream>
using namespace std;

int main(){
    int arr[] = {1,1,1,2,2,2,3,3,3,3};
    int i =0;
    for(int j =1; j < 10 ; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout << "number of unique elemets are:" << i +1  << endl;

}