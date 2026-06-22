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
    bool isValidBST(TreeNode* root) {
        return goodNodefunc(root, LLONG_MAX, LLONG_MIN);
    
    }
    bool goodNodefunc(TreeNode* root, long long maxval,long long minval){
        if(!root) return true;
        if (root->val <= minval || root->val >= maxval) return false;
        bool left=goodNodefunc(root->left,root->val,minval);
        bool right=goodNodefunc(root->right,maxval,root->val);
        return left && right;
    }
};
