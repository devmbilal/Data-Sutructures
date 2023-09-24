// Get Height  
int height(TreeNode* r)
{
    if (r == NULL)
        return -1;
    else {
        /* compute the height of each subtree */
        int lheight = height(r->left);
        int rheight = height(r->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

// Get Balance factor of node N  
int getBalanceFactor(TreeNode* n) {
    if (n == NULL)
        return -1;
    return height(n->left) - height(n->right);
}

TreeNode* rightRotate(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    // Perform rotation  
    x->right = y;
    y->left = T2;

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    // Perform rotation  
    y->left = x;
    x->right = T2;

    return y;
}

TreeNode* insert(TreeNode* r, TreeNode* new_node) {
    if (r == NULL) {
        r = new_node;
        cout << "Value inserted successfully" << endl;
        return r;
    }

    if (new_node->value < r->value) {
        r->left = insert(r->left, new_node);
    }
    else if (new_node->value > r->value) {
        r->right = insert(r->right, new_node);
    }
    else {
        cout << "No duplicate values allowed!" << endl;
        return r;
    }

    int bf = getBalanceFactor(r);
    // Left Left Case  
    if (bf > 1 && new_node->value < r->left->value)
        return rightRotate(r);

    // Right Right Case  
    if (bf < -1 && new_node->value > r->right->value)
        return leftRotate(r);

    // Left Right Case  
    if (bf > 1 && new_node->value > r->left->value) {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    // Right Left Case  
    if (bf < -1 && new_node->value < r->right->value) {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;

}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* r, int v) {
    // base case 
    if (r == NULL) {
        return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r->value) {
        r->left = deleteNode(r->left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r->value) {
        r->right = deleteNode(r->right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
        // node with only one child or no child 
        if (r->left == NULL) {
            TreeNode* temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL) {
            TreeNode* temp = r->left;
            delete r;
            return temp;
        }
        else {
            // node with two children: Get the inorder successor (smallest 
            // in the right subtree) 
            TreeNode* temp = minValueNode(r->right);
            // Copy the inorder successor's content to this node 
            r->value = temp->value;
            // Delete the inorder successor 
            r->right = deleteNode(r->right, temp->value);
            //deleteNode(r->right, temp->value); 
        }
    }

    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation 
    if (bf == 2 && getBalanceFactor(r->left) >= 0)
        return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation 
    else if (bf == 2 && getBalanceFactor(r->left) == -1) {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation	
    else if (bf == -2 && getBalanceFactor(r->right) <= -0)
        return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation 
    else if (bf == -2 && getBalanceFactor(r->right) == 1) {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}
