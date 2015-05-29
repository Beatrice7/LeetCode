class Solution {
    public:
        bool isValid(string s){
            stack<char> stk;
            string left = "({[";
            string right = ")}]";
            for(auto &item: s){
                if(left.find(s[i]) != string::npos){
                    stk.push(item);
                }else if(stk.empty() || stk.top() != left[right.find(c)]){
                    return false;
                }else{
                    stk.pop();
                }
            }
            return stk.empty();
        }

};
