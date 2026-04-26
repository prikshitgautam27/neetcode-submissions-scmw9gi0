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
unordered_map<int,int>inorderindex;
int preindex=0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            inorderindex[inorder[i]]=i;

        }
        return helper(preorder,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder,int left,int right){
        if(left>right) return nullptr;

        int rootval = preorder[preindex++];
        TreeNode* root= new TreeNode(rootval);

        int idx= inorderindex[rootval];

        root->left = helper(preorder,left,idx-1) ;
        root->right = helper(preorder,idx+1,right) ;

return root;
    }
    
};