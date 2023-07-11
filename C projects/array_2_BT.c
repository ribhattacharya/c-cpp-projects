/*
Read array and process into binary tree
C for Everyone: Structured Programming
Week 4
Rishabh Bhattacharya
Jul 10th, 2023


Program description: Read a file of intergers and store it as a binary tree. Print the inorder traversal of the tree.

--------------------INPUT------------------------
6 90 34 67 21 33 71

--------------------OUTPUT-----------------------
Input array:            90 34 67 21 33 71 
Inorder traversal:      21 34 33 90 71 67 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int val, Node *left, Node *right) {
    /*
    DESC: Create node with given value.
    
    INPUTS:
        int val: Node value. 
        Node *left: Left child of current node.
        Node *right: Right child of current node.
    
    OUTPUTS:
        Node *new_node: Pointer to the newly created node.
    */
    
    Node *new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->left = left;
    new_node->right = right;

    return new_node;

}

Node* createBT(int i, int data[], int SIZE) {
    /*
    DESC: Recursively create BT given the array data.
    
    INPUTS:
        int i: Current element index.
        int data[]: Data array.
        int SIZE: Data array size.
    
    OUTPUTS:
        Node *root: Root pointer of the BT.
    */
    if (i >= SIZE) return NULL;
    
    Node *root = createNode(data[i], NULL, NULL);
    root->left = createBT(2*i + 1, data, SIZE);     // left_child = data[2*i + 1]
    root->right = createBT(2*i + 2, data, SIZE);    // right_child = data[2*i + 2]
    
    return root;
}

void inOrder(Node *root) {
    /*
    DESC: Recursively print the inorder traversal of the BT.
    
    INPUTS:
        Node *root: Root node of the BT.
    */
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

int main(int argc, char **argv) {
    
    char *input_filename = "input.txt";

    // Use input arguments if provided
    if (argc == 2) 
        input_filename = argv[1];
    
    FILE* inputFile = fopen(input_filename, "r");
    
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    int size = 0;
    fscanf(inputFile, "%d", &size); // Read the size of the array

    int *data = (int*)malloc(size * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Input array:\t\t");
    // Read the integers into the array
    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &data[i]);
        printf("%d ", data[i]);
    }
    printf("\n");

    fclose(inputFile);

    // Create BT from array and print inorder traversal.
    Node *root = createBT(0, data, size);
    printf("Inorder traversal:\t");
    inOrder(root);
    printf("\n");

    free(data);
    data = NULL;

    return 0;
}