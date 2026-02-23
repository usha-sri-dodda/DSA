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
    void func(TreeNode*  root, string path, vector<string>& res){
        if(!root)   return;
        if(!root->left&&!root->right)   {
            string temp=path+to_string(root->val);
            res.push_back(temp);
        }
        path=path+to_string(root->val)+"->";
        func(root->left,path,res);
        func(root->right,path,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path="";
        func(root,path,res);
        return res;
    }
};
