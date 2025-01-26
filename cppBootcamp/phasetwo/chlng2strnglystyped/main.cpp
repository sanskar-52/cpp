#include <iostream>
#include <string>
using namespace std;

string api_call(){
    return "got some data from web\n";
}

int another_api_call(){
    return 5;
}

int main() {
    auto response = api_call();
    cout << "API CALL VALUE: " << response;
    if (typeid(string) == typeid(response)) {
        puts("type of both id is same\n");
    }

    auto rep = another_api_call();
    cout << "another api call vall value " << rep << endl;
    if (typeid(rep) == typeid(int)) {
        puts("type of both id is int\n");
    }
    return 0;
}