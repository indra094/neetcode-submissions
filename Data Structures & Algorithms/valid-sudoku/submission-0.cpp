class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int &mask) {
        if(board[row][col]=='.') {
            return true;
        }
        int num = board[row][col]-'0';
        if(mask&(0x1<<num)) {
            cout<<" "<<mask<<" "<<(0x1<<num)<<'\n';
            return false;
        }
        cout<<num<<" "<<(0x1<<num)<<" ";
        mask |=(0x1<<num);
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int box=0; box<9; box++) {
            int mask = 0x0;
            for(int row=0; row<3; row++) {
                for(int col=0; col<3; col++) {
                    int boxRow = (box/3) *3 +row;
                    int boxCol = (box%3)*3 + col;
                    if(!isValid(board, boxRow, boxCol, mask)) {
                        cout<<"box "<<box<<'\n';
                        return false;
                    }
                    
                }
            }
        }

        for(int row=0; row<9; row++) {
            int mask = 0;
            for(int col=0; col<9; col++) {
                if(!isValid(board, row, col, mask)) {
                    cout<<"row "<<row<<'\n';
                    return false;
                }
                
            }
        }

        for(int col=0; col<9; col++) {
            int mask = 0;
            for(int row=0; row<9; row++) {
                if(!isValid(board, row, col, mask)) {
                    cout<<"col "<<col<<'\n';
                    return false;
                }
                
            }
        }
        return true;
    }
};
