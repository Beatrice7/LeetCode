#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string convertToTitle(int n){
    map<int, char> mapping;
    string title = "";
    for(int i = 0; i < 26; ++i){
        char ch = 'A' + i;
        mapping[i] = ch;
    }

    while(n){
        title.insert(title.begin(), mapping[(n-1) % 26]);
        // n /= 26;错了 如：26
        n = (n-1) / 26;
    }

   return title;
}

int main(int argc, const char *argv[])
{
    cout <<  convertToTitle(1111);

    return 0;
}
