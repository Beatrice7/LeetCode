/********************************************************************************** 
* 
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*               
**********************************************************************************/
/*my solution*/
class Solution {
public:
    void swapvec(vector<int> &a, vector<int> &b){
        vector<int> tmpvec(a);
        a.assign(b.begin(), b.end());
        b.assign(tmpvec.begin(), tmpvec.end());   
    }

    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n == 1) return ;
        //先行交换
        for(int i = 0; i < n/2; ++i) swapvec(matrix[i], matrix[n-1-i]);
        //再对角线交换
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n; ++j)
                    swap(matrix[i][j], matrix[j][i]);
    }

};


/*other solution*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        
        for (int i = 0; i < n; ++i)  // 沿着副对角线反转
            for (int j = 0; j < n - i; ++j)
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
 
        for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
            for (int j = 0; j < n; ++j)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
    }
};

