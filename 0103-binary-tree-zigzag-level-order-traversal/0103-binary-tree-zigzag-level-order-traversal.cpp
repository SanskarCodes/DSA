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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>nodes;
        bool flag = 1;
        vector<vector<int>>result;
        if(root == NULL){
            return result;
        }
        nodes.push(root);

        while(!nodes.empty()){
            int size = nodes.size();
            vector<int>row(size);
            for(int i = 0 ; i < size ; i ++){
                TreeNode* node = nodes.front();
                nodes.pop();
                int index = (flag) ? i : (size - i -1);
                
                row[index] = node->val;
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
            flag = !flag;
            result.push_back(row);
        }
        return result;
    }
};