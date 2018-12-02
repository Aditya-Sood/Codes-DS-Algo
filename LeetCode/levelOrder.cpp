/**
 * Level order traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

#include <queue>
#include <vector>

#define pb push_back
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> lvlord;
        
        if(root == NULL)
            return lvlord;
        
        queue<TreeNode*> treeq;
        treeq.push(root);
        treeq.push(NULL);
        
        while(treeq.size() > 1)
        {
            vector<int> levelnodes;
            
            TreeNode* node = treeq.front();
            treeq.pop();
            while(node != NULL)
            {
                levelnodes.pb(node->val);
                
                if(node->left != NULL)
                    treeq.push(node->left);
                
                if(node->right != NULL)
                    treeq.push(node->right);
                
                node = treeq.front();
                treeq.pop();
            }
            
            lvlord.pb(levelnodes);
            treeq.push(NULL);
        }
        
        return lvlord;
    }
};