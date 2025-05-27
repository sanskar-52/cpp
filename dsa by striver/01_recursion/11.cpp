#include <iostream>
#include <string>
using namespace std;

bool f(string s,int i){
    int n = s.length();
    if(i >= n) return true;
    else if(s[i] != s[n-1-i]) return false;
    return (f(s,i+1));

}


int main()
{
    string pal = "mhadahm";
    cout << f(pal,0);       
    return 0;
}