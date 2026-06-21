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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> arra;
        vector<int> subarra;
        toarray(root,arra);
        toarray(subRoot,subarra);
        vector<int> lps=buildlps(subarra);
        
        return match(arra,subarra,lps);
    }


    void toarray(TreeNode* root,vector<int>& arra){
    if(!root) { arra.push_back (-101); return;}
    arra.push_back(root->val);
    toarray(root->left,arra);
    toarray(root->right,arra);
    }

    vector<int> buildlps(vector<int> subarra){
        int n=subarra.size();
        vector<int> lps(n);
        int i=1;
        int len=0;
        while(i<n){
            if (subarra[i] ==subarra[len]) {
            len++;
            lps[i] = len;
            i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        
}
return lps;
}
bool match(vector<int> arra, vector<int> subarra, vector<int> lps){
    int i=0;
    int j=0;
    while(i<arra.size()){
        if(arra[i]==subarra[j]){
            i++;
            j++;            
            if(j==subarra.size()) return true;
            
        }
        else {
            if(j) j=lps[j-1];
            else i++;
        }
    }
    return false;
}}
;