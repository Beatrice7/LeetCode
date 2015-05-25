#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string intToRoman(int num){
    map<int, string> M;
    M[1] = "I";
    M[4] = "IV";
    M[5] = "V";
    M[9] = "IX";
    M[10] = "X";
    M[40] = "XL";
    M[50] = "L";
    M[90] = "XC";
    M[100] = "C";
    M[400] = "CD";
    M[500] = "D";
    M[900] = "CM";
    M[1000] = "M";
    
    string res;
    for(auto item = M.crbegin(); item != M.crend();){
        if(num / item->first != 0)
        {
            res += item->second;
            num -= item->first;
        }else{
            item++;
        }
    }
    return res;
}

string intToRoman1(int num) {
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res;
    for(int i = 0; i < 13; ){
        if(num / value[i]){
            res += roman[i];
            num -= value[i];
        }else{
            ++i;
        }
    }
    return res;
}


int main(int argc, const char *argv[])
{
    cout << intToRoman(1900);
    return 0;
}
