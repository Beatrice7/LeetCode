/********************************************************************************** 
* 
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* 
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
* 
* A partially filled sudoku which is valid.
* 
* Note:
* > A valid Sudoku board (partially filled) is not necessarily solvable. 
*   Only the filled cells need to be validated.
* 
* 不用管当前填数字的方法最后能不能成功，只要判断现在的符不符合即可             
**********************************************************************************/

class Solution {
public:
bool isValidSudoku(vector<vector<char> > &board){
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool area[9][9] = {false};//把每一个小9宫格子对应二维数组中的一行
    
    for(int r = 0; r < 9; ++r){
        for(int c = 0; c < 9; ++c){
            if(!isdigit(board[r][c])) continue;
            
            int num = board[r][c] - '0';
            int a = (r / 3) * 3 + c / 3;//判断是第几个小9宫格，也就是第几行
            if(row[r][num-1] || col[num-1][c] || area[a][num-1]) return false;
            //board[r][c]是数字几，就将该数字的位置改为true
            row[r][num-1] = true;
            col[num-1][c] = true;
            area[a][num-1] = true;
        }
    }
    return true;
    
}
};
