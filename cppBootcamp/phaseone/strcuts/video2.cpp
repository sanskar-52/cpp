//pre processor constant and enums

#include <iostream>
#include <cstdint>
using namespace std;
// #define pi 3.14
enum MsOffice: uint8_t {   //uint8_t used for saving memory idk how
    BOLD = 0,
    ITALICS = 2,
    UNDERLINE,
    CROSSED
};

int main() {
    int myAttributes = ITALICS;

    cout << myAttributes << endl;

    return 0;
}