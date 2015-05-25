#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int romanToInt(string s){
    if(s.size() == 0) return 0;
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int res = m[s[s.size()-1]];

    for(int i = s.size()-2; i >= 0; --i){
        cout << m[s[i]] << endl;
        if(m[s[i]] >= m[s[i+1]])
        {
            res += m[s[i]];
        }else{
            res -= m[s[i]];
        }
        cout << "res:" << res << endl;
    }
    return res;

}


int main(int argc, const char *argv[])
{
    cout << romanToInt("DCXXI");
    return 0;
}
