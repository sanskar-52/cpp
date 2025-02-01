#include <iostream>
#include <string>
using namespace std;

int globalvar = 0;

int minimax(int array[][4],int row,int column){
    globalvar = globalvar + (array[row][column]);
    int above = 0;
    int below= 0;
    int left= 0;
    int right= 0;
    if(row > 0 && (array[row-1][column]) > 0 ){
        //you can check above(jab above == 1)
        above += 1;
    }
    if(row < 3 && (array[row+1][column]) >0){
        //you can check below
        below += 1;
    }
    if(column > 0 && (array[row][column -1]) > 0){
        //you can check left
        left += 1;
    }
    if(column < 3 && (array[row][column +1]) > 0){
        //you can check right
        right += 1;
    }


    if(above > 0){
        above -= above;
        minimax(array,row -1,column);
    }
    if(below > 0){
        below -= below;
        minimax(array,row+1,column);
    }
    return 0;
}

int main(){
    int array[4][4]={
        {0,2,7,0},
        {8,4,0,10},
        {0,6,0,1},
        {0,1,2,4}
    };

    for(int r = 0; r  < 4 ; r++){
        for(int c=0; c < 4 ; c++){
            if(array[r][c] != 0){
                minimax(array,r,c);
            }
        }
    }

    return 0;
}