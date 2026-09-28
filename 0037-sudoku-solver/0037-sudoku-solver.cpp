class Solution {
public:
    bool issafe(int index,char ch,vector<vector<char>> &board){
        int row=index/9;
        int col=index%9;
        for(int j=0;j<9;j++){
            if(board[row][j]==ch){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==ch){
                return false;
            }
        }
        int startrow=(row/3)*3;
        int startcol=(col/3)*3;
        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(board[i][j]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int index,vector<vector<char>> & board){
        if(index==81){
            return true;
        }
        int n=board.size();
        int row=index/n;
        int col=index%n;
        if(board[row][col]!='.'){
            return solve(index+1,board);
        }
        for(char ch='1';ch<='9';ch++){
            if(issafe(index,ch,board)){
                board[row][col]=ch;
                if(solve(index+1,board)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,board);
    }
};