/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void get_sum_ltree(struct node*, int);
void get_sum_rtree(struct node*, int);
int get_height(struct node *root){
	int ld, rd;
	if (root == NULL)
		return 0;
	else
	{
		ld = get_height(root->left);
		rd = get_height(root->right);
	}
	if (ld > rd)
		return ld + 1;
	else
		return rd + 1;
}

int get_left_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	int sum = root->left->data;
	get_sum_ltree(root->left, sum);
	return sum;
}

int get_right_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	int sum = root->right->data;
	get_sum_rtree(root->right, sum);
	return sum;
}
void get_sum_ltree(struct node* root, int sum)
{
	if (root != NULL){
		if (root->left != NULL)
			sum = sum + root->left->data;
		if (root->right != NULL)
			sum = sum + root->right->data;
		get_sum_ltree(root->left, sum);
	}
}
void get_sum_rtree(struct node* root, int sum)
{
	if (root != NULL){
		if (root->left != NULL)
			sum = sum + root->left->data;
		if (root->right != NULL)
			sum = sum + root->right->data;
		get_sum_rtree(root->right, sum);
	}
}