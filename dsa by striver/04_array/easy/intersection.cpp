//intersection of two arrays
//given arrays will be sorted
//intersection array can contain duplicate elements
//return intersection array

#include <bits/stdc++.h>
using namespace std;


//solving on my own by two pointer approach
vector<int> arrayIntersection(vector<int> &A,vector<int> &B){
    vector<int> ans;
    int n1 = A.size();
    int n2 = B.size();
    int i = 0; //iterator for A
    int j = 0; //iterator for B

    while(i<n1 && j<n2){
        if(A[i] < B[j]){
            i++;
        }
        else if(A[i] == B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> A = {1,1,1,2,2,3,4,5,5,5,6,6,7,7,8,8,9,9,10,12,15,15,17};
    vector<int> B = {2,2,3,4,5,6,6,8,8,9,9,10,11,11,12,12,14,15,15,17};

    vector<int> ans = arrayIntersection(A,B);
    for(auto x:ans){
        cout << x << endl;
    }
}