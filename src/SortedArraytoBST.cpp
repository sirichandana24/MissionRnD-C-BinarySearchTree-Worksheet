/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node* to_array(int*, int, int);
struct node* create_node(int data);
struct node * convert_array_to_bst(int *arr, int len){
	int first = 0, last = len - 1;
	if (arr == NULL)
		return NULL;
	struct node* tree_start;
	tree_start = to_array(arr, first, last);
	return tree_start;
}
struct node* to_array(int *arr, int first, int last)
{
	if (first > last)
		return NULL;
	int mid = (first + last) / 2;
	struct node *root = create_node(arr[mid]);
	root->left = to_array(arr, first, mid - 1);
	root->right = to_array(arr, mid + 1, last);
	return root;
}
struct node* create_node(int data)
{
	struct node *n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}
