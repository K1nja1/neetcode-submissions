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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(maxDepth(root->left)-maxDepth(root->right) )>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);

    }
    int maxDepth(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        int depthr=maxDepth(root->right);
        int depthl=maxDepth(root->left);
        return max(depthr,depthl)+1;
    }
};
