class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        if(len <= 1)return s;
        int start, maxLen = 0;
        string res;
        for(int i = 1; i < len; i++)
        {
            //寻找以i-1,i为中点偶数长度的回文
            int low = i-1, high = i;
            while(low >= 0 && high < len && s[low] == s[high])
            {
                low--;
                high++;
            }
            if(high - low - 1 > maxLen) //巧妙之处，虽然while循环之后low--，high++了，但是通过high-low—1得出的正是maxlen
            {
                maxLen = high - low -1;
                start = low + 1; //不需要每次都赋值res, 只需要记录start位置就行了
            }
             
            //寻找以i为中心的奇数长度的回文
            low = i- 1; high = i + 1;
            while(low >= 0 && high < len && s[low] == s[high])
            {
                low--;
                high++;
            }
            if(high - low - 1 > maxLen)
            {
                maxLen = high - low -1;
                start = low + 1; 
            }
        }
        return res.assign(s, start, maxLen);//可以直接用s.substr(start, maxlen);
    }
};