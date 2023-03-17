class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        // Building matrix (not adjList) for starting of floydWarshall algo.
        for(auto it: edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // FloydWarshall to form the matrix with shortest distances.
        for(int i = 0;i<n;i++) dist[i][i] = 0;
        for(int via = 0;via<n;via++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][via] == 1e9 || dist[via][j] == 1e9){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], (dist[i][via] + dist[via][j]) );
                }
            }
        }

        // Now we move through every row and find the row no. with min number of cities(cols)
        // whose distance which are lower than threshold.

        // cityNo will stores ans city number with min cnt.
        // cntCity will store min cnt.
        int cntCity = 1e9;
        int cityNo = -1;
        for(int city = 0;city<n;city++){
            int cnt = 0;
            for(int adjCity = 0;adjCity < n;adjCity++){
                if(dist[city][adjCity] <= distanceThreshold){
                    cnt++;
                }
            }

            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};