/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */

void inorder(Node* root, vector<int> &vec)
{
    if(root == NULL) return;
    
    if(root->left != NULL)
        inorder(root->left, vec);
        
    vec.push_back(root->data);
    
    if(root->right != NULL)
        inorder(root->right, vec);
}

void merge(Node *root1, Node *root2)
{
    vector<int> bst1, bst2;
    
    //inorder
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    //sorted print
    int a = 0, b = 0;
    for(int i = 1; i <= bst1.size()+bst2.size(); i++)
    {
        if(a == bst1.size())
        {
            while(b < bst2.size())
                cout << bst2[b++] << ' ';
                
            break;
        }
        
        if(b == bst2.size())
        {
            
            while(a < bst1.size())
                cout << bst1[a++] << ' ';
                
            break;
        }
        
        if(bst1[a] < bst2[b])
        {
            cout << bst1[a++] << ' ';
        }
        else
            cout << bst2[b++] << ' ';
    }
   //Your code here
}