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
    int goodNodes(TreeNode* root) {
        int maxval=-101;
        int count=0;
        goodNodefunc(root,maxval,count);
        return count;

    }
    void goodNodefunc(TreeNode* root, int maxval,int& count){
        if(!root) return;

        if(root->val>= maxval) {count++; maxval=root->val;}
       
        goodNodefunc(root->left,maxval,count);
        goodNodefunc(root->right,maxval,count);
        return;
    }
};
