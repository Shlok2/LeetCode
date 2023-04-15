class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0, piles, k, dp);
    }

    int solve(int index,vector<vector<int>>& piles, int k,vector<vector<int>> &dp){
        if(index >= piles.size()){
            return 0;
        }
        int maxi = 0;int sum = 0;
        if(dp[index][k] != -1){
            return dp[index][k];
        }

        // Not Take
        maxi = max(maxi,solve(index+1, piles, k, dp));

        for(int i = 0; i < piles[index].size(); i++ ){
            sum += piles[index][i];
            if ( k - (i+1) >= 0 ){
                // Take
                maxi = max(maxi, sum + solve(index + 1, piles, (k - (i+1)), dp));
            }
        }

        return dp[index][k] = maxi;
    }
};