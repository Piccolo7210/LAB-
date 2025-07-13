#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert node in level-order (for general binary tree)
Node* insert(Node* root, int data) {
    Node* newNode = new Node(data);
    if (!root) return newNode;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front(); q.pop();
        if (!temp->left) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }
        if (!temp->right) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal
void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// Level-order traversal
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// Search a value (normal binary tree search)
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return search(root->left, key) || search(root->right, key);
}

// Height of tree
int height(Node* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}

// Diameter
int diameterRecur(Node* root, int& res) {
    if (!root) return 0;
    int lHeight = diameterRecur(root->left, res);
    int rHeight = diameterRecur(root->right, res);
    res = max(res, lHeight + rHeight);
    return 1 + max(lHeight, rHeight);
}

int diameter(Node* root) {
    int res = 0;
    diameterRecur(root, res);
    return res;
}

// Mirror the tree
void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

// Lowest Common Ancestor (LCA) in Binary Tree
Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data == n1 || root->data == n2) return root;
    Node* left = findLCA(root->left, n1, n2);
    Node* right = findLCA(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

// Check if two trees are identical
bool areIdentical(Node* a, Node* b) {
    if (!a && !b) return true;
    if (a && b)
        return (a->data == b->data) &&
               areIdentical(a->left, b->left) &&
               areIdentical(a->right, b->right);
    return false;
}

// Free memory
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
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

// MAIN
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);

    cout << "In-order traversal: ";
    inOrder(root); cout << "\n";

    cout << "Pre-order traversal: ";
    preOrder(root); cout << "\n";

    cout << "Post-order traversal: ";
    postOrder(root); cout << "\n";

    cout << "Level-order traversal: ";
    levelOrder(root); cout << "\n";

    cout << "Height of tree: " << height(root) << "\n";
    cout << "Diameter of tree: " << diameter(root) << "\n";

    int key = 50;
    cout << "Is " << key << " present? " << (search(root, key) ? "Yes" : "No") << "\n";

    int n1 = 40, n2 = 70;
    Node* lca = findLCA(root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << "\n";

    cout << "Mirroring tree...\n";
    mirror(root);
    cout << "In-order after mirror: ";
    inOrder(root); cout << "\n";

    freeTree(root);
    return 0;
}
