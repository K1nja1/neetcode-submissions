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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levelorder=levelOrder(root);
        vector<int> res;
        for(int i=0;i<levelorder.size();i++){
            res.push_back(levelorder[i].back());
        }
        return res;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty()){
            vector<int> l;
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                l.push_back(curr->val);
            }
            res.push_back(l);

        }
        return res;
    }
};
