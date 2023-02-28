class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,1e9));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,-1,0,+1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == m-1 && col == n-1){
                return diff;
            }

            for(int i = 0;i<4;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr >= 0 && newr < m && newc >= 0 && newc < n){
                    int maxi = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if(maxi < dist[newr][newc]){
                        dist[newr][newc] = maxi;
                        pq.push({maxi,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};