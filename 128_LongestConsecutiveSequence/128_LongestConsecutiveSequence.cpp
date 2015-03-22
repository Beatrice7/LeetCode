/******************************************
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*******************************************/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
            unordered_map<int, bool> used;
            for(auto &item: num){
                    used[item] = false;
            }
            int maxlength = 0;
            for(auto &item: num){
                /*
                一个数字只会出现在一个相应的序列中， 
                因为序列是consecutive的，所以遍历过就无需再来遍历
                这句最关键，没有这句就超时
                */
                if(used[item]) continue;
                
                int length = 0;
                int j = item;
                /*先找比item大的数字*/
                while(used.find(j) != used.end()){
                    used[j++] = true;
                    length++;
                }
                /*再找比item小的数字*/
                j = item - 1;
                while(used.find(j) != used.end()){
                    used[j--] = true;
                    length++;
                }
                maxlength = max(maxlength, length);
            }
            return maxlength;
        } 
};
