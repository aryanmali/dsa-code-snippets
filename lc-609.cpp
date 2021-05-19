//https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto path : paths) {
            stringstream ss(path);
            string root,s;
            getline(ss,root,' ');
            while(getline(ss,s,' ')) {
                string filepath = root + '/' + s.substr(0, s.find('('));
                string filecontent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                mp[filecontent].push_back(filepath);
            }
        }
        for(auto x:mp) {
            if(x.second.size()>1)
                ans.push_back(x.second);
        }
        return ans;
    }
};