class Solution {
    public:
    int lengthOfLastWord(string s) {
            int length = 0;
        
            std::string::reverse_iterator wordend = s.rbegin();
            while(!isalpha(*wordend) && wordend != s.rend()){
                        wordend++;
                    }
           std::string::reverse_iterator wordbegin = wordend;
            while(isalpha(*wordbegin) && wordbegin != s.rend()){
                        length++;
                        wordbegin++;
                    }
            distance(wordbegin, wordend);
            
            return length;
        }
};

//STL
class Solution {
    public:
    int lengthOfLastWord(string s) {
            auto begin = find_if(s.rbegin(), s.rend(), ::isalpha);
            auto last = find_if_not(begin, s.rend(), ::isalpha);
            return distance(begin, last);
    
        }
};
