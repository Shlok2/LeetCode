using ll=long long;
class Solution {
public:
    
    ll m=(long long)1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<ll,ll>>adj[n];
        
        
        for(auto itr:roads)
        {
           adj[itr[0]].push_back({itr[1],itr[2]}); 
           adj[itr[1]].push_back({itr[0],itr[2]}); 
        }
        
        
       
        priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        greater<pair<ll,ll>>>pq;
        
        
        // distance node
        pq.push({0,0});
        
        vector<ll>paths(n,0);
        paths[0]=1;
        vector<ll>distance(n,LONG_MAX);
        distance[0]=0;
        
        while(!pq.empty())
        {
            
            ll dis=pq.top().first;
            ll node=pq.top().second;
            
            pq.pop();
            
            for(auto ele:adj[node])
            {
                ll n_node=ele.first;
                ll n_dis=ele.second;
                if(dis+n_dis<distance[n_node])
                {
                    distance[n_node]=(dis+n_dis);
                    pq.push({(dis+n_dis),n_node});
                    paths[n_node]=paths[node];
                }
                else if(dis+n_dis==distance[n_node])
                {
                    paths[n_node]=(paths[node]+paths[n_node])%m;
                }
            }
            
        }
        
        return paths[n-1]%m;
    }
    
    
};