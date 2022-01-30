int tot(Node *root){
        if(!root) return 0;
        
        return tot(root->left) + tot(root->right) + root->data;
    }
    void toSumTree(Node *node)
    {
        if(!node)
          return;
          
        int sum = tot(node) - node->data;
        node->data = sum;
        
        toSumTree(node->left);
        toSumTree(node->right);
    }