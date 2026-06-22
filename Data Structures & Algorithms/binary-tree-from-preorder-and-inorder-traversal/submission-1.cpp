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
    unordered_map<int,int> mp;
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int curr=0;
        return build(preorder,inorder,0,preorder.size()-1,curr);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int left,int right,int& curr){
        
        if(left>right) return nullptr;
        TreeNode* root=new TreeNode(preorder[curr]);
        int currcurr=curr;
        curr++;
        if(left==right) return root;
        root->left=build(preorder,inorder,left,mp[preorder[currcurr]]-1,curr);
        root->right=build(preorder,inorder,mp[preorder[currcurr]]+1,right,curr);
        return root;
    }
};
