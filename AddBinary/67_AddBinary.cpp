#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
//遇到这种两个字符串有长短的，
//只需要在相加的时候将已经到末尾的字符处赋值为0即可
string addBinary(string a, string b){
    auto rit1 = s1.rbegin();
    auto rit2 = s2.rbegin();

    int carry = 0;
    string res;
    int cur1, cur2;

    for(; rit1 != a.rend() || rit2 != b.rend(); ){
        if(rit1 != a.rend()){
            cur1 = *rit1 - '0';
            rit1++;
        }else{
            cur1 = 0;
        }

        if(rit2 != b.rend()){
            cur2 = *rit2 - '0';
            rit2++;
        }else{
            cur2 = 0;
        }

        int cur = (cur1 + cur2 + carry) % 2;
        carry = (cur1 + cur2 + carry) / 2;
        res.insert(res.begin(), cur + '0');
    }

    if(carry == 1){
        res.insert(res.begin(), '1');
    }
    return res;

}


int main(int argc, const char *argv[])
{
    string a("111");
    string b("100");
    cout << addBinary(a, b);
    return 0;
}
