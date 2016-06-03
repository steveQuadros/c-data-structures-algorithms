#import <stdio.h>
#import <stdlib.h>

typedef struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;

BstNode* BstNodeCreate(int data) {
    BstNode* n = (BstNode*)malloc(sizeof(BstNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = BstNodeCreate(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int Search(BstNode* root, int n) {
    if (root == NULL) {
        return 0;
    }
    else if (n == root->data) {
        return 1;
    }
    else if (n < root->data) {
        return Search(root->left, n);
    }
    else {
        return Search(root->right, n);
    }
    return 0;
}

void Print(BstNode* root) {

}

int main(int argc, char* argv[]) {
    BstNode* root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);

    printf("Seaching 18 should be 0, is %d\n", Search(root, 18));
    printf("Searching 25 should be 1, is %d\n", Search(root, 25));
    return 0;
}

