#include <iostream>
using namespace std;

int main(){

    static const char *originalfile =  "originalfile.txt";
    static const char *editedfile =  "editedfile.txt";

    rename(originalfile,editedfile);
    remove(editedfile);

    // FILE * fh = fopen(originalfile, "w");
    // fclose(fh);

    return 0;
}