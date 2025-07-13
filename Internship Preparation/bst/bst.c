#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        // printf("%d ", root->data);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int isBSTUtil(struct Node* root, int min_val, int max_val) {
    // Empty tree is valid
    if (root == NULL) 
        return 1;
    
    // Check if current node violates the min/max constraints
    if (root->data <= min_val || root->data >= max_val)
        return 0;
    
    // Check recursively for left and right subtrees
    // - Left subtree values must be between min_val and root->data
    // - Right subtree values must be between root->data and max_val
    return isBSTUtil(root->left, min_val, root->data) && 
           isBSTUtil(root->right, root->data, max_val);
}

// Function to check if a binary tree is a valid BST
int isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
// Level Order Traversal (BFS)
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;
    
    // Enqueue root
    queue[rear++] = root;
    
    // Loop until queue is empty
    while (front < rear) {
        // Dequeue a node and print it
        struct Node* current = queue[front++];
        printf("%d ", current->data);
        
        // Enqueue left child
        if (current->left != NULL)
            queue[rear++] = current->left;
            
        // Enqueue right child
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    
    free(queue);
}
// Function to calculate the height of a binary tree
int height(struct Node* root) {
    // Base case: empty tree has height -1
    if (root == NULL) 
        return -1;
    
    // Recursively calculate height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Height is the maximum of left and right subtree heights, plus 1
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
void mirror(struct Node* root) {
    if (root == NULL) return;
    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively call mirror on left and right subtrees
    mirror(root->left);
    mirror(root->right);
}
int diameter(struct Node* root, int* height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = diameter(root->left, &lh);
    int rdiameter = diameter(root->right, &rh);
    
    *height = (lh > rh ? lh : rh) + 1;
    
    return (lh + rh + 1 > ldiameter ? (lh + rh + 1) : (ldiameter > rdiameter ? ldiameter : rdiameter));
}
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal: ");
    inOrder(root); // Output: 20 30 40 50 60 70 80
    printf("\n");
    printf("Post-order traversal: ");
    postOrder(root); 
    printf("\n");
    printf("Pre-order traversal: ");   
    preOrder(root); // Output: 50 30 20 40 70 60 80
    printf("\n");
    printf("Level-order traversal: ");
levelOrder(root); // Output: 50 30 70 20 40 60 80
printf("\n");
printf("\nIs the tree a valid BST? %s\n", 
       isBST(root) ? "Yes" : "No");

    // root = deleteNode(root, 70);
    // printf("In-order traversal after deletion: ");
    // inOrder(root); // Output: 20 30 40 50 60 80
    // printf("\n");

    // struct Node* found = search(root, 60);
    // if (found != NULL)
    //     printf("Element 60 found in the BST.\n");
    // else
    //     printf("Element 60 not found in the BST.\n");

    return 0;
}