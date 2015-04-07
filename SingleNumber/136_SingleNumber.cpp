/********************************************************************************** 
* 
* Given an array of integers, every element appears twice except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
*               
**********************************************************************************/

class Solution {
    public:
        int singleNumber(int A[], int n) {
            return accumulate(A, A+n, 0, bit_xor<int>());       
        }

        int singleNumber2(int A[], int n) {
            int s = 0;
            for(int i=0; i<n; i++){
                s = s^A[i];
            }
            return s;
        }
};
