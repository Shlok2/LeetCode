class Solution {
public:

    // No PQ required, instead we can use Q -> As stops increase by 1 each time (not at
    // irregular intervals like 3,6,8, etc ), hence there is no need of PQ and Q can do
    // the work.
    // If increase is constant -> use Q
    // If increase in random -> use PQ

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // distance is us node tak ki cost.
        // {Stops, {node,distance}}, because stops is the most important criteria according
        // to which this question will be solved.
        // Note -> NOT {dis,{node,stops}}
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stops > k){
                continue;
            }
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjNodeCost = it.second;
                if(cost + adjNodeCost < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + adjNodeCost;
                    q.push({stops + 1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};