class Solution {
public:
    bool search(int A[], int n, int target) {
	assert(n != 0);
	int left = 0;
	int right = n - 1;
	int mid = (left + right) >> 1;

	while (left <= right){
		if (A[mid] == target) return true;
		if (A[left] < A[mid]){
			if (target >= A[left] && target < A[mid]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		else if (A[mid] < A[right]){
			if (target > A[mid] && target <= A[right]){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		else if (A[mid] == A[left]){ //[3,1,2,3,3,3,3]中间的与左边相等时一定和右边也相等
			left++;
		}
		else{//[1,1,2,2,2]中间和右边相等时就不一定和左边相等了
			right--;
		}
		mid = (left + right) >> 1;
	}
	return false;

}
};