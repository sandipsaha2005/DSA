// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a tree node
// struct TreeNode {
//     int data;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// // Function to create a new tree node
// struct TreeNode* createNode(int value) {
//     struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//     newNode->data = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Function to convert a sorted array to a binary search tree
// struct TreeNode* arrayToBST(int arr[], int start, int end) {
//     if (start > end)
//         return NULL;

//     int mid = (start + end) / 2;
//     struct TreeNode* root = createNode(arr[mid]);

//     root->left = arrayToBST(arr, start, mid - 1);
//     root->right = arrayToBST(arr, mid + 1, end);

//     return root;
// }

// // Function to print the inorder traversal of a BST
// void inorderTraversal(struct TreeNode* root) {
//     if (root != NULL) {
//         inorderTraversal(root->left);
//         printf("%d ", root->data);
//         inorderTraversal(root->right);
//     }
// }

// int main() {
//     int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int n = sizeof(array) / sizeof(array[0]);

//     // Convert the array to a binary search tree
//     struct TreeNode* root = arrayToBST(array, 0, n - 1);

//     // Print the inorder traversal of the binary search tree
//     printf("Inorder Traversal of BST: ");
//     inorderTraversal(root);

//     return 0;
// }














// linked representation

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node ;


int main(){
    node *p;
    p=(node *)malloc(sizeof(node)); 
    return 0;
}