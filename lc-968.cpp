//https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
    int ans=0;
    int minCameraCover(TreeNode* root) {
        return ((dfs(root)==0)?1:0) + ans;
    }
    int dfs(TreeNode* root) {
        if(!root)
            return 2;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l == 0 || r == 0) {
            ans++;
            return 1;
        }
        return ((l==1 || r==1) ? 2 : 0);
    }
};