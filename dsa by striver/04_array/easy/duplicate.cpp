#include <iostream>
#include <vector>
#include <set>
using namespace std;

int unique(int arr[],const set<int> &st){
    int index = 0;
    for(auto x:st){
        arr[index] = x;
        index++;
    }
    return index;
}

int main(){
    int arr[] = {1,1,1,2,2,3,3,3,3,3};
    set<int> st;
    for(int i =0;i< 10; i++){
        st.insert(arr[i]);
    }
    cout << "element of set are:" << endl;
    for(int n:st){
        cout << n <<endl;
    }
    
    int no_of_unique = unique(arr,st);
    cout << "no of unique elements:" << no_of_unique << endl;
    
}