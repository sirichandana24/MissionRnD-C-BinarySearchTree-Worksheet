/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int get_height_of_bst(struct node*);
void traversal(struct node*, int, int*, int*);
int* BSTRighttoLeftRows(struct node* root)
{
	int height, i, index = 0, *arr;
	arr = (int*)malloc(100 * sizeof(int));
	if (root == NULL)
		return NULL;
	height = get_height_of_bst(root);
	for (i = 1; i <= height; i++)
		traversal(root, i, arr, &index);
	return arr;
}
void traversal(struct node *root, int k, int *arr, int *index)
{
	if (root == NULL)
		return;
	if (k == 1)
		arr[(*index)++] = root->data;
	else if (k>1)
	{
		traversal(root->right, k - 1, arr, index);
		traversal(root->left, k - 1, arr, index);
	}
}
int get_height_of_bst(struct node *root){
	int ld, rd;
	if (root == NULL)
		return 0;
	else
	{
		ld = get_height_of_bst(root->left);
		rd = get_height_of_bst(root->right);
	}
	if (ld > rd)
		return ld + 1;
	else
		return rd + 1;
}


