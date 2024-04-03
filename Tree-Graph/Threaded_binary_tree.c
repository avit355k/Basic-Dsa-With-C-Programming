
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int isThreaded;
} TreeNode;

// Function to create a new node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Function to perform in-order traversal
void inOrder(TreeNode* root) {
    TreeNode* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

// Function to perform pre-order traversal
void preOrder(TreeNode* root) {
    TreeNode* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == NULL) {
                printf("%d ", current->data); // Print before going to left child
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

// Function to perform post-order traversal
void postOrder(TreeNode* root) {
    if (root == NULL)
        return;
    TreeNode* dummy = createNode(-1);
    dummy->left = root;
    TreeNode* current = dummy;
    while (current != NULL) {
        if (current->left == NULL) {
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = NULL;
                TreeNode* temp = current->left;
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->right;
                }
                current = current->right;
            }
        }
    }
    free(dummy);
}

// Function to insert a node into threaded binary tree
void insert(TreeNode** root, int data) {
    TreeNode* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
    } else {
        TreeNode* current = *root;
        while (1) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    newNode->right = current;
                    newNode->isThreaded = 1;
                    return;
                } else {
                    current = current->left;
                }
            } else {
                if (current->isThreaded || current->right == NULL) {
                    newNode->right = current->right;
                    current->right = newNode;
                    current->isThreaded = 0;
                    newNode->isThreaded = 1;
                    return;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

int main() {
    TreeNode* root = NULL;
    int choice, data;
    
    printf("1. Insert\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Exit\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
