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
        int dum=root->val;
        pathSum(root,dum);
        return dum;
    }
    int pathSum(TreeNode* root,int& dum){
        if(!root) return 0; 

        int left=pathSum(root->left,dum);
        if(left<0) left =0;
        int right=pathSum(root->right,dum);
        if(right<0) right=0;
        dum=max(dum,root->val+left+right);
        return root->val+max(left,right);
    }

};
