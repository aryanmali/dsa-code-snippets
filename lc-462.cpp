https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0,i=0,j=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<j) 
            ans += nums[j--]-nums[i++];
        return ans;
    }
};