class Solution {
public:
    
    void dfs(int i ,int j ,vector<vector<int>> &vis, vector<vector<char>> board){
        int m = board.size();
        int n = board[0].size();
        if(i >= m || i < 0 || j < 0 || j >= n){
            return;
        }
        if(board[i][j] == 'X' || vis[i][j] == 1){
            return;
        }
        
        vis[i][j] = 1;
        dfs(i+1,j,vis,board);
        dfs(i-1,j,vis,board);
        dfs(i,j+1,vis,board);
        dfs(i,j-1,vis,board);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'X' && (i == 0 || i == m-1 || j == 0 || j == n-1) ){
                    vis[i][j] = 1;
                }
                else if(board[i][j] == 'O' && (i == 0 || i == m-1 || j == 0 || j == n-1)){
                    dfs(i,j,vis,board);
                }
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};