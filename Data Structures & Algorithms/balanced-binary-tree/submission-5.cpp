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

bool halwa=true;
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return halwa;

    }
    int maxDepth(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        int depthr=maxDepth(root->right);
        int depthl=maxDepth(root->left);
        if (abs(depthr-depthl)>1) halwa=false;
        return max(depthr,depthl)+1;
    }
};
