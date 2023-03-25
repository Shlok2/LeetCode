class Dsu{
    
    public:
    vector<int>parent;
    vector<int>size;
    Dsu(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find_ulp(int node){
        if(node==parent[node])return node;
        return parent[node]=find_ulp(parent[node]);
    }
    void disjoint_set(int n,int v){
        int up_n=find_ulp(n);
        int up_v=find_ulp(v);
        if(up_n==up_v)return ;
        if(size[up_n]>size[v]){
            size[up_n]+=size[up_v];
            parent[up_v]=up_n;

        }
        else{
            size[up_v]+=size[up_n];
            parent[up_n]=up_v;
        }
    

    }
};

class Solution {
public:
 



    int removeStones(vector<vector<int>>& stones) {
        int max_row=0;
        int max_col=0;
        for(auto i:stones){
            max_row=max(max_row,i[0]);
            max_col=max(max_col,i[1]);
        };
        Dsu ds(max_row+max_col+1);
        for(auto it:stones){
            int node_row=it[0];
            int node_col=it[1]+max_row+1;
            ds.disjoint_set(node_row,node_col);

        }
        int count =0;
        for(int i=0;i<=max_row+max_col+1;i++){
            if(ds.parent[i]==i and ds.size[i]>1)count++;
        };
        return stones.size()-count;

    }
};