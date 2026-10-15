/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxiTree(root,maxi);
        return maxi;
    }

    int maxiTree(TreeNode* root, int& maxi){
        if(root == NULL){
            return 0;
        }

        int l = max(0,maxiTree(root->left,maxi));
        int r = max(0,maxiTree(root->right,maxi));

        maxi = max(maxi,root->val + r + l);

        return root->val + max(r , l);
    }
};