#include <iostream>
#include <string>
#include <map>
#include <stack>
/*一直纠结于将符号压入stack中！！
  实际上将序号i压入stack，这样就能计算长度了*/
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int len = 0;
        int last = -1; // the positio of the last ')'
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                stk.push(i);
            }else{
                if(stk.empty()){
                    last = i;  
                } //处理s的最开始是')'的情况, 以及当stk空时当前s[i] == ')'的情况
                else{
                    stk.pop();
                    if(stk.empty()){
                        len = max(len, i - last);
                    }else{
                        len = max(len, i - stk.top());
                    }
                }
            }
        }
        return len;
    }
};


int main(int argc, const char *argv[])
{
    string s("()(()");
    cout << longestValidParentheses(s);

    return 0;
}
