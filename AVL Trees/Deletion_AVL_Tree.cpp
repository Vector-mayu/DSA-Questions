// Calculation of Height
int getheight(Node *root)
{
    if(!root)
    return 0;
    
    return root->height;
}

// Calculation of Balance
int getbalance(Node *root)
{
    return getheight(root->left) - getheight(root->right);
}


// Left Rotation
Node* leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childRight = child->left;
    
    child->left = root;
    root->right = childRight;
    
    // Update the height of Child and root
    
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    
    
    return child;
}

Node* rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    
    child->right = root;
    root->left = childRight;
    
    // Update Height of Child and Root
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    
    
    return child;
}



Node* deleteNode(Node* root, int key) {
    // add code here,
    
    // If Root Dosent Exist
    if(!root)
    return NULL; // Base Case
    
    // If Key is Lesser GO LEFT
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    // If Key is Greater GO RIGHT
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // If we get the target Node  (Deleting Conditions)
    else
    {
        // Leaf Node 
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // Only Left child exist
        else if(root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Only Right Child exist
        else if(!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // If Both Sides Exist 
        else
        {
            // Go on the right side 
            //(find smallest Node ofc which will be on Left side) 
            // Find the smallest element 
            // And Replace it with the Node
            
            //Right side Smallest Element
            Node *curr = root->right;
            while(curr->left)
            {
                curr = curr->left;
            }
            
            //As Soon as u get it Replace root with the Smallest Element
            root->data = curr->data;
            // After replacing now recursively Delete the replaced Node
            root->right = deleteNode(root->right, curr->data);
        }
    }
    
    // After the Deletion Process Update the height of ROOT
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    
    // Now Check the Balance 
    int balance = getbalance(root);
    
    //Check for any Possible Rotations
    
    // Left Side Imbalance
    if(balance > 1)
    {
        // LL Rotation --> Right Rotation
        if(getbalance(root->left) >=0)
        return rightRotation(root); // Right Rotation
        
        // LR Rotation --> Left And Right Rotation
        else
        {
           root->left = leftRotation(root->left); // Left Rotation
           return rightRotation(root); // Right Rotation
        }
    }
    // Right Side Imbalance
    else if(balance < -1)
    {
        // RR Rotation --> Right Rotation
        if(getbalance(root->right) <= 0) 
        return leftRotation(root); // Left Rotation
        
        // RL Rotation --> Right And Left Rotation
        else
        {
            root->right = rightRotation(root->right); // Right Rotation
            return leftRotation(root); // Left Rotation
        }
    }
    else
    return root; 
}