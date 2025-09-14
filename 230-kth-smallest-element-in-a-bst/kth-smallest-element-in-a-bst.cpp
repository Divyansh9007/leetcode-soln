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
    void inorder(TreeNode*root,int k,int &count,int &smallest){
        if(root==NULL || count>=k){
            return;
        }
        inorder(root->left,k,count,smallest);
        count++;
        if(count==k){
            smallest=root->val;
            return;
        }
        inorder(root->right,k,count,smallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int smallest=INT_MIN;
        inorder(root,k,count,smallest);
        return smallest;
    }
};