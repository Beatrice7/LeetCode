class Solution {
public:
    int find_kth(int A[], int m, int B[], int n, int k){
	if (m > n) return find_kth(B, n, A, m, k);
	if (m == 0) return B[k - 1];
	if (k == 1) return std::min(A[0], B[0]);

	int ka = std::min(m, k / 2);
	int kb = k - ka;
	if (A[ka - 1] == B[kb - 1]) return A[ka - 1];

	if (A[ka - 1] < B[kb - 1]){
		return find_kth(A + ka, m - ka, B, n, kb);
	}
	else{
		return find_kth(A, m, B + kb, n - kb, ka);
	}
}




//((m + n) >> 1) + 1 这种情况在使用移位符号时，要注意括号，否则无法自动判断优先级
double findMedianSortedArrays(int A[], int m, int B[], int n) {
	assert((m != 0) || (n != 0));
	if ((m + n) & 0x1){//odd;
		return find_kth(A, m, B, n, ((m + n) >> 1) + 1);
	}else{
		return (find_kth(A, m, B, n, (m + n) >> 1) + find_kth(A, m, B, n, ((m + n) >> 1) + 1)) / 2.0;
	}
}

};