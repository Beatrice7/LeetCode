/********************************************************************************** 
* 
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* click to show follow up.
* 
* Follow up:
* 
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
* 
*               
**********************************************************************************/

//O(m + n) space
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
    	//O(m + n) space
        vector<bool> row_mask(row, false);
        vector<bool> col_mask(col, false);
    
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == 0){
                    col_mask[j] = row_mask[i] = true;
                }
            }
        }
    
    
        for(int i = 0; i < row; ++i){
            if(row_mask[i]){
               fill(&matrix[i][0], &matrix[i][col-1] + 1, 0);
            }
        }
    
        for(int j = 0; j < col; ++j){
            if(col_mask[j]){
                for(int i = 0; i < row; ++i){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//a constant space
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int firstrow = false;
        int firstcol = false;
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == 0){
                    if(i == 0) firstrow = true;
                    if(j == 0) firstcol = true;
                    matrix[i][0] = matrix[0][j] = 0;
                   
                }
            }
        }
        
        for(int i = 1; i < row; ++i){
            if(matrix[i][0] == 0){
                fill(&matrix[i][0], &matrix[i][0] + col, 0);
            }
        }
        
        for(int j = 1; j < col; ++j){
            if(matrix[0][j] == 0){
                for(int k = 0; k < row; ++k){
                    matrix[k][j] = 0;
                }        
            }
        }
        
        if(firstrow){
            fill(&matrix[0][0], &matrix[0][0] + col, 0);
        }
        if(firstcol){
            for(int k = 0; k < row; ++k){
                    matrix[k][0] = 0;
                }         
        }
        
    }
};