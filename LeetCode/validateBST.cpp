/** Validate BST
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inordtrav(TreeNode* root, vector<int> &vec)
    {
        if(root->left != NULL)
            inordtrav(root->left, vec);
        
        vec.push_back(root->val);
        
        if(root->right != NULL)
            inordtrav(root->right, vec);
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        
        vector<int> inord;
        inordtrav(root, inord);
        
        for(int i = 0; i < inord.size()-1; i++)
            if(inord[i] >= inord[i+1])
                return false;
        
        return true;
        
    }
};