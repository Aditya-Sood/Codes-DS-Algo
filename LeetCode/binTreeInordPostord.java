// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    TreeNode root;
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        
        int m = inorder.length, n = postorder.length;
        
        root = getRoot(inorder, 0, m-1, postorder, 0, n-1);
        
        
        return root;
        
    }
    
    private TreeNode getRoot(int[] inorder, int li, int ri, int[] postorder, int lp, int rp) {
        // Traverse inorder until find rightmost match from the postorder
        
        // Validity of bounds
        
        TreeNode curr = null;
        
        if(li == ri) { // Leaf nodes
            curr = new TreeNode(inorder[li]);
            curr.left = null;
            curr.right = null;
            
            return curr;
        }
        
        int rootVal, i, j;
        
        for(i = rp; i >= lp; i--) {
            boolean found = false;
            
            for(j = li; j <= ri; j++) {
                if(inorder[j] == postorder[i]) {
                    found = true;
                    break;
                }
            }
            
            if(found) {
                rootVal = inorder[j];
                curr = new TreeNode(rootVal);
                curr.left = getRoot(inorder, li, j-1, postorder, lp, i-1);
                curr.right = getRoot(inorder, j+1, ri, postorder, lp, i-1);
                break;
            }
        }
        
        return curr;
    }
}

/*
FASTEST SOL:

**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 *
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(postorder.length-1, 0, inorder.length-1, inorder, postorder);
    }
    public TreeNode helper(int post, int inStart, int inEnd, int[] inorder, int[] postorder){
        if(post<0 || inStart>inEnd) return null;
        TreeNode root = new TreeNode(postorder[post]);
        int inIndex = 0;
        for(int i=inEnd; i>=inStart; i--){
            if(inorder[i]==postorder[post]){
                inIndex = i;
                break;
            }
        }
        root.left = helper(post+inIndex-inEnd-1, inStart, inIndex-1, inorder, postorder);
        root.right = helper(post-1, inIndex+1, inEnd, inorder, postorder);
        return root;
    }
}
*/