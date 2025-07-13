// Binary Search Tree implementation in C++
#include<bits/stdc++.h>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
int maxWidth(Node* root) {
    if (root == nullptr) return 0;
    
    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;
    
    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);
        
        while (count--) {
            Node* current = q.front();
            q.pop();
            
            if (current->left != nullptr)
                q.push(current->left);
                
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
    
    return maxWidth;
}
// Convert a sorted array to a balanced BST
Node* sortedArrayToBST(int arr[], int start, int end) {
    // Base case
    if (start > end) return nullptr;
    
    // Get the middle element and make it root
    int mid = (start + end) / 2;
    Node* root = createNode(arr[mid]);
    
    // Recursively construct the left subtree
    root->left = sortedArrayToBST(arr, start, mid - 1);
    
    // Recursively construct the right subtree
    root->right = sortedArrayToBST(arr, mid + 1, end);
    
    return root;
}
// Search for a key in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
Node* invertTree(Node* root){
    if(root == nullptr) return nullptr;
    Node* left = invertTree(root->left);
    Node* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Post-order traversal
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Pre-order traversal
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Find the minimum value node
Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Check if BST is valid
bool isBSTUtil(Node* root, int min_val, int max_val) {
    // Empty tree is valid
    if (root == nullptr) 
        return true;
    
    // Check if current node violates the min/max constraints
    if (root->data <= min_val || root->data >= max_val)
        return false;
    
    // Check recursively for left and right subtrees
    return isBSTUtil(root->left, min_val, root->data) && 
           isBSTUtil(root->right, root->data, max_val);
}

// Function to check if a binary tree is a valid BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
// Find Lowest Common Ancestor of two nodes
Node* findLCA(Node* root, int n1, int n2) {
    // Base case
    if (root == nullptr) return nullptr;
    
    // If either n1 or n2 matches with root's data, return root
    if (root->data == n1 || root->data == n2) return root;
    
    // Look for LCA in left and right subtrees
    Node* left = findLCA(root->left, n1, n2);
    Node* right = findLCA(root->right, n1, n2);
    
    // If both left and right subtrees return non-null, root is the LCA
    if (left != nullptr && right != nullptr) return root;
    
    // Otherwise, return the non-null result
    return (left != nullptr) ? left : right;
}
bool areIdentical( Node* a,  Node* b) {
    if (a == NULL && b == NULL)
        return true;
    if (a != NULL && b != NULL) {
        return (a->data == b->data) &&
               areIdentical(a->left, b->left) &&
               areIdentical(a->right, b->right);
    }
    return false;
}

// Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    // Loop until queue is empty
    while (!q.empty()) {
        // Dequeue a node and print it
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        
        // Enqueue left child
        if (current->left != nullptr)
            q.push(current->left);
            
        // Enqueue right child
        if (current->right != nullptr)
            q.push(current->right);
    }
}

// Calculate height of the tree
int height(Node* root) {
    // Base case: empty tree has height -1
    if (root == nullptr) 
        return -1;
    
    // Recursively calculate height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Height is the maximum of left and right subtree heights, plus 1
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Mirror the tree
void mirror(Node* root) {
    if (root == nullptr) return;
    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively call mirror on left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

int diameterRecur(Node* root, int &res) {
  
    // Base case: tree is empty
    if (root == nullptr)
        return 0;
    
    // find the height of left and right subtree
    // (it will also find of diameter for left 
    // and right subtree).
    int lHeight = diameterRecur(root->left, res);
    int rHeight = diameterRecur(root->right, res);
    
    // Check if diameter of root is greater
    // than res.
    res = max(res, lHeight+rHeight);
    
    // return the height of current subtree.
    return 1 + max(lHeight, rHeight);
}

// Function to get diameter of a binary tree
int diameter(Node* root) {
  
    int res = 0;
    diameterRecur(root, res);
    return res;
}

// Free the memory of the BST
void freeTree(Node* root) {
    if (root == nullptr) return;
    
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
bool findPath(Node* root, int key, int path[], int* pathLen) {
    if (root == nullptr) return false;
    
    // Store this node in path
    path[*pathLen] = root->data;
    (*pathLen)++;
    
    // If this is the required node, return true
    if (root->data == key) return true;
    
    // Check if the key exists in left or right subtree
    if (findPath(root->left, key, path, pathLen) || 
        findPath(root->right, key, path, pathLen))
        return true;
    
    // If we reach here, the key was not found in this subtree
    // Remove current node from path and return false
    (*pathLen)--;
    return false;
}
// Iterative Pre-order Traversal (Root, Left, Right)
void preOrderIterative(Node* root) {
    if (root == nullptr) return;
    
    stack<Node*> s;
    s.push(root);
    
    while (!s.empty()) {
        // Pop the top item from stack and print it
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";
        
        // Push right child first so that left is processed first
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
}

// Iterative In-order Traversal (Left, Root, Right)
void inOrderIterative(Node* root) {
    stack<Node*> s;
    Node* current = root;
    
    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        
        // Current is NULL at this point
        current = s.top();
        s.pop();
        
        // Print the node's value
        cout << current->data << " ";
        
        // Visit the right subtree
        current = current->right;
    }
}

// Iterative Post-order Traversal (Left, Right, Root)
void postOrderIterative(Node* root) {
    if (root == nullptr) return;
    
    stack<Node*> s1, s2;
    s1.push(root);
    
    // The first stack is used to get nodes in (Root, Right, Left) order
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        
        // Push left and right children of removed item to s1
        if (current->left)
            s1.push(current->left);
        if (current->right)
            s1.push(current->right);
    }
    
    // Print all elements of second stack (gives Left, Right, Root)
    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        cout << current->data << " ";
    }
}

bool areMirrors( Node* a,  Node* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return (a->data == b->data) &&
           areMirrors(a->left, b->right) &&
           areMirrors(a->right, b->left);
}
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;
    
    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;
    
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;
    
    cout << "Level-order traversal: ";
    levelOrder(root);
    cout << endl;
    
    cout << "\nIs the tree a valid BST? " << (isBST(root) ? "Yes" : "No") << endl;
    
    cout << "Height of the tree: " << height(root) << endl;
    
    cout << "Diameter" <<diameter(root) << endl;

    Node* lca = findLCA(root, 70, 40);
    if (lca != nullptr)
        cout << "LCA of 70 and 40 is: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* balancedRoot = sortedArrayToBST(arr, 0, n - 1);
    cout << "In-order traversal of balanced BST: "; 
    inOrder(balancedRoot);
    cout << endl;
    
    // Test findPath function
// int path[100];  // Array to store path
// int pathLen = 0;
// int targetKey = 40;

// cout << "\nFinding path to node " << targetKey << ": ";
// if (findPath(root, targetKey, path, &pathLen)) {
//     cout << "Path exists: ";
//     for (int i = 0; i < pathLen; i++) {
//         cout << path[i];
//         if (i < pathLen - 1) cout << " -> ";
//     }
//     cout << endl;
// } else {
//     cout << "No path found" << endl;
// }

    /*
    root = deleteNode(root, 70);
    cout << "In-order traversal after deletion: ";
    inOrder(root);
    cout << endl;
    
    Node* found = search(root, 60);
    if (found != nullptr)
        cout << "Element 60 found in the BST." << endl;
    else
        cout << "Element 60 not found in the BST." << endl;
    */
    
    // Clean up memory
    freeTree(root);
    
    return 0;
}