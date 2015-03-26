/********************************************************************
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*********************************************************************/

class Solution {
public:
    void nextPermutation(vector<int> &num){
        int n = num.size();
        if(n<=1) return;
        int index = n-1;
        while(num[index] <= num[index-1] && index >= 1) --index; 
        if(index == 0){
            reverse(num.begin(), num.end());
            return;
        }
        /*从后面的数组(一定是升序了)中找出比num[index-1]大的数，而不是直接与num[index]交换！*/
    	for(int i = n-1; i >= index; --i){
            if(num[i] > num[index-1]) {
                int tmp = num[i];
                num[i] = num[index-1];
                num[index-1] = tmp;
                reverse(num.begin() + index, num.end());
                return;
            }
        }
       // for(auto it = num.begin(); it < num.end(); it++) cout << *it << " ";
        return;

    }
};