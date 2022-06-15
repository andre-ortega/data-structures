/* Define tree: A collection of entites, called nodes, linked together to simulate a heirarchy
 *   Nodes have children, each arrow in a tree is a link from parent to child node
 *   Nodes on the same level as others are sibling nodes, but they must have the same parent
 *   Nodes on the same level, not the same parent, but same grandparent, can be cousins
 *   Nodes without children are leaf nodes
 *
 *   If we can traverse the tree from A to B, then A is the ancestor of B, and B is descendant of A
 *
 *   Trees are recursive data structures. The root contains the link to all the subtrees.
 *   A tree with N nodes will have exactly N-1 edges
 *
 *   Depth of x node is length of path from root to x, or number of edges from root to x
 *
 *   Height of x node is number of edges in longest path from x to leaf
 *   Height of a tree is the height of the root node
 *
 *   Binary trees have at most two children
 *      - data
 *      - left child
 *      - right child
 *
 *   Maximum number of nodes in a BST at level i is 2^i
 *   A perfect BST that is completely filled will have  n =  2^(h+1) -1  nodes
 *   Therefore the height is  h = log2(n + 1) - 1  edges
 *
 *   A complete binary tree has all levels except possible the last completely filled and all 
 *   nodes are as far left as possible
 *
 *   Tree examples
 *     - Network routing applications
 *     - Computer file systems
 *     - Quick searche algorithms
 *
 *   Cost of operations on a Binary Tree is proportional to to the height of the tree, we 
 *   therefore would like the tree to be as close to complete as possible, otherwise we could
 *   just essentially be following a linked list. To get the time advantages, the tree must be
 *   sorted and balanced.
 *   
 *   We can implement binary trees using
 *      - Dynamically created nodes
 *      - Array
 *          - For node at index i
 *              - left-child  = 2i + 1
 *              - right-child = 2i + 2
 *
 *   BST Array
 *      - Search O(n) - must scan list, possibly until end
 *      - Insert O(1) - random access
 *      - Remove O(n) - may have to shift n-1 elements in worst case
 *
 *  A Sorted Balanced BST will have a time of O(logn)
 *
 *              Array(unsorted)     Linked List     Array(Sorted)
 *  Search(x)   O(n)                O(n)            O(logn)
 *  Insert(x)   O(1)                O(1)            O(logn)
 *  Remove(x)   O(n)                O(n)            O(logn)
 *
 *  All binary search trees must have BST subtrees
 *      - values of all nodes in left subtrees are less than all values in right subtrees
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode BstNode;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* Insert(BstNode* root, int data);
BstNode* GetNewNode(int data);

int main(int argc, char * argv[]){

    BstNode* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 7);
    root = Insert(root, 20);

    printf("tree %d %d %d", root->data, root->left->data, root->right->data);

    return 0;
}

BstNode* GetNewNode(int data){
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->data = data;
    return newNode;
}

BstNode* Insert(BstNode* root, int data){

    if(root == NULL){
        return GetNewNode(data);

    } else if (data <= root->data) {

        root->left = Insert(root->left, data);

    } else {

        root->right = Insert(root->right, data);
    }

    return root;
}