class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(m,1e9));

        // Src = 0
        dist[0][0] = 0;

        // Push {src,{row,col}} in queue
        q.push({0,{0,0}});

        int dr[] = {-1,-1,-1,0,0,+1,+1,+1};
        int dc[] = {-1,0,+1,-1,+1,-1,0,+1};

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }

        // For edge case matrix -> {{0}}
        if(m == 1 && n == 1){
            return 1;
        }

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            for(int i = 0;i<8;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                if(newr >= 0 && newr < m && newc >= 0 && newc < n && 
                dis + 1 < dist[newr][newc] && grid[newr][newc] == 0){
                    dist[newr][newc] = dis + 1;
                    if(newr == m-1 && newc == n-1){
                        return dis + 2;
                    }
                    q.push({1+dis,{newr,newc}});
                }
            }
        }
        for(int i= 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        return -1;
    }
};