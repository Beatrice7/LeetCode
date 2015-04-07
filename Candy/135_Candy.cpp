/********************************************************************************** 
* 
* Given an array of integers, every element appears three times except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int children = ratings.size();
        vector<int> candies(children, 1);
        
        for(int i = 1; i < children; ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }
        
        for(int i = children-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i+1]+1, candies[i]);
            }
        }
        
        return accumulate(candies.begin(), candies.begin()+children, 0);
    }
};
