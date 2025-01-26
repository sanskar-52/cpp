#include <iostream>
using namespace std;

int main(){
    int infinity = INT8_MAX;
    cout <<"size of int is " << sizeof(int) << endl;
    int smallest;
    //creating array of size 
    int nums[]= {5,15,22,1,-15,24};
    //size of nums
    int sizenum = sizeof(nums)/sizeof(int);
    cout << "size of nums is " << sizenum <<endl;
    smallest = nums[0];

    for(int i=0;i < 6;i++){
        if(nums[i] < smallest){
            smallest = nums[i];
        }
    }
    cout << "smallest num in nums is " << smallest << endl;
}