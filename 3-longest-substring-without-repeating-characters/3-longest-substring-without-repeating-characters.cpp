class Solution {
public:
//     int lengthOfLongestSubstring(string s) 
// 	{
// 		unordered_set<char> set;
    
// 		int i = 0, j = 0, n = s.size(), ans = 0;
    
// 		while( i<n && j<n)
// 		{
// 			if(set.find(s[j]) == set.end()) 
// 			{
// 				set.insert(s[j++]);
// 				ans = max(ans, j-i); 
// 			}
// 			else
// 			{
// 				set.erase(s[i++]); 
				
// 			}
// 		}
    
// 		return ans;
// 	}



    // vector<int> mp(256,-1);
    //     int left = 0;
    //     int right = 0;
    //     int n = s.size();
    //     int len = 0;
    //     while(right<n){
    //         if(mp[s[right]] != -1){
    //             left = max(left,mp[s[right]] + 1);
    //         }
    //         mp[s[right]] = right;
    //         len = max(len,right-left+1);
    //         right++;
    //     }
    //     return len;
    
    
    
    int lengthOfLongestSubstring(string s) 
	{
        if(s == ""){
            return 0;
        }
        
        int j = 0;
        unordered_map<char,int> m;
        int maxi = INT_MIN;
        for(int i = 0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]] > 1){
                while(m[s[i]] > 1){
                    m[s[j]]--;
                    if(m[s[j]] == 0){
                        m.erase(s[j]);
                    }
                    j++;
                }
            }
            
            cout<<endl<<endl<<endl;
            int temp = m.size();
            maxi = max(maxi,temp);
        }
        return maxi;
    }
	
};