/*
 * this solution is so-called three times rotate method
 * because (X^TY^T)^T = YX, so we can perform rotate operation three times to get the result
 * obviously, the algorithm consumes O(1) space and O(n) time
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        reverse(nums.begin(), nums.begin() + s - k % s);
        reverse(nums.begin() + s - k % s, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

//STL
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size(); 
        nums.insert(nums.begin(), nums.begin() + s - k%s, nums.end());
        nums.erase(nums.begin() + s, nums.end());
    }
};
