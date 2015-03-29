// 思路2，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int trap(int A[], int n) {
        int max = 0;
        for(int i = 0; i < n; ++i){
            if(A[i] > A[max]) max = i; //先找到最大值，然后两边往中间靠拢
        }
        int units = 0;
        for(int left = 0, maxleft = 0; left < max; ++left){
            if(A[left] > maxleft) {maxleft = A[left]; continue;}//不加花括号是错的
            units += (maxleft - A[left]);
        }
        for(int right = n - 1, maxright = 0; right > max; --right){
            if(A[right] > maxright) {maxright = A[right]; continue;}
            units += (maxright -A[right]);
        }
        return units;
    }
};

