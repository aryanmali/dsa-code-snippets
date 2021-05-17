//https://leetcode.com/problems/longest-string-chain/

class Solution {
    vector<vector<int>> adj;
    vector<int> dp;
    
    int dfs(int curr) {
        if(dp[curr] > 0)
            return dp[curr];
        dp[curr] = 1;
        for(auto v:adj[curr])
            dp[curr] = max(dp[curr],dfs(v)+1);
        return dp[curr];
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        adj.clear(); adj.resize(n);    
        dp.clear(); dp.resize(n);
        
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++)
            mp[words[i]] = i;
        
        for(int i=0;i<n;i++) {
            string s = words[i];
            for(int j=0;j<s.size();j++) {
                string tmp = s.substr(0,j) + s.substr(j+1);
                if(mp.count(tmp))
                    adj[mp[tmp]].push_back(i);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans = max(ans,dfs(i));
        return ans;
    }
};