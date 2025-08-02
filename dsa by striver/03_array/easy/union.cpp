//this is the optimal way of finding union.
//a1 and a2 are sorted.

//different pattern of iterator
//both iterators are dependent on one another.


//if there are two iterator and one is independent and another is dependent i have noticed that we can iterate
//over the independent iterator through loops,declaring index for dependent iterator 
//and iterating it inside if() inside the loop of independent iterator loop.
//maybe i am generalising it too much?
#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> a1 = {1,1,1,2,3,4,5};
    vector<int> a2 ={1,1,3,4,5,5,6,7};
    vector<int> unionArr; 
    int n1 = a1.size();
    int n2 = a2.size();

    int i =0;
    int j =0;

    while(i < n1 && j < n2){
        if(a1[i] <= a2[j]){
            if(unionArr.size()==0 || a1[i] != unionArr.back()){
                unionArr.push_back(a1[i]);
            }
            i++;
        }
        else {
            if(unionArr.size()==0 || a2[j] != unionArr.back()){
                unionArr.push_back(a2[j]);
            }
            j++;
        }
    }

    while(j<n2) {
        if(unionArr.size()==0 || a2[j] != unionArr.back()){
                unionArr.push_back(a2[j]);
            }
            j++;
    }
    
    while(i<n1) {
        if(unionArr.size()==0 || a1[i] != unionArr.back()){
                unionArr.push_back(a1[i]);
            }
            i++;
    }

}