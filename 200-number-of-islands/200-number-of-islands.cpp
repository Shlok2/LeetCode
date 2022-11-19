class Solution {
public:
    
    // 0 -> water
    // 1 -> island (land)
    // 2 -> visited land
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(grid[i][j] == '2' || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '2';
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};