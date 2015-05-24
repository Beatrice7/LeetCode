#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s){
    string curString;
    int maxlen = -1;
    for(int i = 0; i < s.size();){
        int pos = curString.find(s[i]);
        if(pos == string::npos){
            curString += s[i++];
        }else{
            int len = curString.size();
            maxlen = std::max(maxlen, len);
            //遇到重复的就把重复的字符及其之前的字符删掉
            curString.erase(curString.begin(), curString.begin()+pos+1);
        }
    }
    int len = curString.size();
    return max(maxlen, len); 
    //max()的两个数据类型必须一致，所以要将size_t转换为int
    //而且这里要再次与curString.size()比较,为了将最后添加的字符串与maxlen比较
}


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) { //lastRepeatPos < m[s[i]]必须有，确保lastRepeatPos不回退；如：abba 
                lastRepeatPos = m[s[i]];
            }
            if ( i - lastRepeatPos > maxLen ){
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }
};

int main(int argc, const char *argv[])
{
    string a("dvdf");
    string b("abca");
    cout << lengthOfLongestSubstring(a) << endl;
   // cout << lengthOfLongestSubstring(b) << endl;
    return 0;
}


