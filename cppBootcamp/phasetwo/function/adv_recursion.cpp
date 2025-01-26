#include <iostream>
#include <string>

using namespace std;

template <typename T>
void func(T t){
    cout << "by function 1: "<< t << endl;
}

template <typename T,typename... Args>
void func(T t,Args... arg){
    cout << "by function 2: " << t << endl;
    func(arg...);
}

int main(){
    string my_name = "sanskar";

    func(1, 2, 3, my_name);

    return 0;
}