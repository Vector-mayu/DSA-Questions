// GeeksForGeeks Hard Problem 
// Companies :- Morgan Stanley, Amazon Snapdeal, MakeMyTrip, Oracle, Oxigen Wallet, Informatica, Citicorp


// Code 

class Solution {
  public:
  
    // Calculation of Height
        int getheight(Node *root)
        {
        	if(!root)
        	return 0;
        
        	return root->height;
        }
        
        // Calculation of Balance
        int getBalance(Node *root)
        {
        	return getheight(root->left) - getheight(root->right);
        }
        
        
        // Left Rotation
        Node* leftRotation(Node *root)
        {
        	Node *child = root->right;
        	Node *childLeft = child->left;
        
        	child->left = root;
        	root->right = childLeft;
        
        	// Update Height of Child and Root
        
        	root->height = 1 + max(getheight(root->left), getheight(root->right));
        	child->height = 1 + max(getheight(child->left), getheight(child->right));
        
        	// return this operation to OG Node 
        	return child;
        }
        
        // Right Rotation
        Node* rightRotation(Node *root)
        {
        	Node *child = root->left;
        	Node *childRight = child->right;
        
        	child->right = root;
        	root->left = childRight;
        
        	// Update height of Child and Root
        
        	root->height = 1 + max(getheight(root->left), getheight(root->right));
        	child->height = 1 + max(getheight(child->left), getheight(child->right));
        
        	// return this operation to OG Node 
        	return child;
        }
  
    /*You are required to complete this method */
    Node* insertToAVL(Node* root, int key) {
        // Your code here
        
        // If Root Doesnt Exist
    	if(!root)
    	return new Node(key);
    
    	//If Root Exist
    	// Left Insertion
    	if(key < root->data)
    	root->left = insertToAVL(root->left, key);
    
    	//Right Insertion
    	else if(key > root->data)
    	root->right = insertToAVL(root->right, key);
    
    	//If duplicate Value (Not Allowed)
    	else
    	return root;
    
    
    	// Updation of height
    	root->height = 1 + max(getheight(root->left), getheight(root->right));
    
    	//Balancing Check
    	int balance = getBalance(root);
    
    	//CASES
    
    	//Left Left Case
    	if(balance > 1 && key < root->left->data)
    	return rightRotation(root);
    
    	//Right Right Case
    	else if(balance < -1 && key > root->right->data)
    	return leftRotation(root);
    
    	//Left Right Case
    	else if(balance > 1 && key > root->left->data)
    	{
    		root->left = leftRotation(root->left);
    		return rightRotation(root);
    	}
    
    	// Right Left Case
    	else if(balance < -1 && key < root->right->data)
    	{
    		root->right = rightRotation(root->right);
    		return leftRotation(root);
    	}
    	//No Unbalancing
    	else
    	return root;
    }
};