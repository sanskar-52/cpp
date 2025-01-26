#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "enter the number of elemetns in array" << endl;
    cin >> n;
    int array[n];
    int mx[n];
    for (int i = 0; i < n ; i++){
        cin >> array[i];
    }
    cout << "////////////////////////////////////////" << endl;
    mx[0] = array[0];
    for (int i = 0; i < n ; i++){
        if(i == 0) continue;
        else if ((array[i]) > (mx[(i-1)])){
            mx[i] = array[i];
        }
        else mx[i] = mx[i-1];
        cout << mx[i] << endl;
    }
    return 0;
}