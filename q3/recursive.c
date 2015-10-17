#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

typedef struct TreeNode
{
//Definition for a binary tree node.
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeNode *newNode(int data)
{
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void flatten(TreeNode *root)
{
//each node's right child points to the next node of a pre-order traversal.
    struct TreeNode* test;
    while (root != NULL) {
        if (root->left != NULL) {
            test = root->left;
            flatten(test);
            while (test->right != NULL) {
                test = test->right;
                flatten(test);
            }
            test->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

void printTree(TreeNode *tree)
{
    if (tree->left) {
        printTree(tree->left);
    }
    printf("%d\n", tree->data);
    if (tree->right) {
        printTree(tree->right);
    }
}

int main()
{
    struct timespec start, end;
    double cpu_time1;
    clock_gettime(CLOCK_REALTIME, &start);
    struct TreeNode *root  = newNode(1);
    root->left             = newNode(2);
    root->right           = newNode(5);
    root->left->left     = newNode(3);
    root->left->right   = newNode(4);
    root->right->right  = newNode(6);

    printf("\nflattened binary tree is \n");
    flatten(root);
    printTree(root);
    printf("\n");
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    printf("execution time of iterative : %lf sec\n", cpu_time1);

    return 0;
}
