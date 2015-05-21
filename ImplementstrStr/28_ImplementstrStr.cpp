class Solution {
public:
    int strStr(string haystack, string needle) {
        //auto it_haystack = haystack.begin();
        //auto it_needle = needle.begin();
        if(needle.length() == 0) return 0;
        for(int index = 0; index + needle.length() <= haystack.length(); index++){
            if(haystack[index] == needle[0]  && !haystack.compare(index, needle.length(), needle)){
                return index;
            }
        }
        return -1;
    }
};
