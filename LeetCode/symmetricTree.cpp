/**
 * Symmetric Trees
 * https://leetcode.com/problems/symmetric-tree/description/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool res = true;
public:
    
    void parallelcheck(TreeNode* lsn, TreeNode* rsn)
    {
        if(!res)
            return;
        
        if(lsn->val != rsn->val ||
           (lsn->left == NULL && rsn->right != NULL) || (lsn->left != NULL && rsn->right == NULL) ||
           (lsn->right == NULL && rsn->left != NULL) || (lsn->right != NULL && rsn->left == NULL))
        {
            res = false;
            return;
        }
        
        if(lsn->left != NULL && rsn->right != NULL)
            parallelcheck(lsn->left, rsn->right);
        
        if(lsn->right != NULL && rsn->left != NULL)
            parallelcheck(lsn->right, rsn->left);
        
    }
    
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL || (root->left == NULL && root->right == NULL))   
            return true;
        
        if(root->left != NULL && root->right != NULL)
            parallelcheck(root->left, root->right);
        else
            res = false;
        
        return res;
    }
};