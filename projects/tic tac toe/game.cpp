#include <iostream>
using namespace std;

//pahle 3 x 3 ka board banayenge
char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};


void displayboard(){
    for(int i=0;i<=2;i++){
        cout << "|";
        for (int j = 0;j <=2; j++){
            cout << board[i][j] << "|";

        }
        cout << endl;
    }
}

int row;
int column;

void locationofmove(int position){
    //loop through each row and in each column to check equality of ( position and the value of array[i][j] )
    for(int i = 0; i < 3 ; i++){
        for(int j = 0; j < 3; j++){
            if(position == board[i][j] - '0'){
                row = i;
                column = j;
                return;
            }
        }
    }
}

// a function to take input from player and then map it to 2d array
void makeMove(char player){
    while(true){
    int position;
    cout << "player " << player << " enter the (1-9)" << endl;
    cin >> position;


    //ab position se 2d array ka row and column nikalna hoga.
    //or us position par X or O mark karna hoga.
    locationofmove(position);

    if(position > 0 && position < 10 && board[row][column] != 'X' && board[row][column] != 'Y'){
        board[row][column] = player;
        break;     //pure function ko hi while(true) me daal do or move 2d array par assign hone par loop se break kar lo.
    }
    else{
        cout << "invalid input please enter a valid position" << endl;      //dubara input kaise le?
    }
    }

}

bool checkwin(){
    for(int i= 0 ; i < 3 ; i++){
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
            return true;
        }
        else if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
        {
            return true;
        }
    }
    if(((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))){
        return true;
    }
    return false;
}

bool checkdraw(){
    for (int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }

        }
    }
    return true;
}

int main(){
    cout << "is this going to change my files locally also?" << endl;
    cout << "welcome to tic tac toe" << endl;
    //ye game 2 players ke bich me hai X and O to loop me daalna hoga taaki alternatively move input le ek baar x se phir o se while checking condition for draw and win?/
    while(true){
        displayboard();
        makeMove('X');
        displayboard();
        if(checkwin()){
            cout << "player X won the game" << endl;
            return 0;
        }
        else if (checkdraw())
        {
            cout << "game is drawn" << endl;
            return 0;
        }
        makeMove('O');
        if(checkwin()){
            cout << "player O won the game" << endl;
            return 0;
        }
        else if (checkdraw())
        {
            cout << "game is drawn" <<endl;
            return 0;
        }
        

    }
}
