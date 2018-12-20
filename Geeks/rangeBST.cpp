/* https://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/ */

/*
The structure of a BST node is as follows:
struct Node {
int data;
Node * right, * left;
};
*/
int getCountOfNode(Node *root, int l, int h)
{
    if(root == NULL)    return 0;
    
    if(root->data < l)  return getCountOfNode(root->right, l, h);
    
    if(root->data > h)  return getCountOfNode(root->left, l, h);
    
    return (1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h));
    
  // your code goes here   
}