#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    if(strs.size() == 0) return "";
    string res = strs[0];
    int minlen = strs[0].length();
    //find the minlen string
    for(auto &item: strs){
        if(item.length() < minlen){
            minlen = item.length();
            res = item;
        }
    }
    
    for(int i = 0; i < strs.size(); ++i){
        while(strs[i].compare(0, res.size(), res) != 0){ //此处要用while： [flower, flow, flight]
            res.pop_back();
        }
    }
    return res;
}

int main(int argc, const char *argv[])
{
    vector<string> vec;
    vec.push_back("");
 //   vec.push_back("aa");
    cout << longestCommonPrefix(vec);
    return 0;
}
