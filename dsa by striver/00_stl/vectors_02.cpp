#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    //vector of pair data type
    vector<pair<int, int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(3,4);        //emplace back will assume the 3,4 as a pair but in push back you have to give it as a pair

    vector<string> bats(5,"bats");    //declaring vector with arguement in which size and element is given.
    for(string n:bats){
        cout << n << endl;
    }
    //how to copy a vector into another vector?

    vector<string> bets(bats);
    for(string n:bats){
        cout << n << " copyed from bats into bets " << endl;
    }


    return 0;
}