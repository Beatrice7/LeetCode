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
    int singleNumber(int A[], int n) {
        const int L = sizeof(int) * 8;
        int count[L];
        fill_n(&count[0], L, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < L; ++j){
                count[j] += (A[i] >> j) & 1;
                count[j] %= 3;
            }
        }
        int result = 0;
        for(int i = 0; i < L; ++i){
            result |= count[i] << i;
        }
        return result;
    }
};


