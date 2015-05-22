#include <iostream>
#include <string>
#include <vector>
using namespace std;

//zigZag则是采用一种迂回的赋值方法，设置一个step
string convert(string s, int numRows){
    if(numRows <= 1 || s.size() <= numRows) return s;
    string res;
    vector<string> v(numRows);
    int cur_row = 0;
    int step = 1;
    for(int i = 0; i < s.size(); ++i){
        if(cur_row == 0) step = 1;
        if(cur_row == numRows - 1) step = -1;
        v[cur_row] += s[i];
        cur_row += step;
    }

    for(auto &item: v){
            res += item;
    }
    return res;
}


int main(int argc, const char *argv[])
{
    cout << convert("ABC", 2);
    return 0;
}
