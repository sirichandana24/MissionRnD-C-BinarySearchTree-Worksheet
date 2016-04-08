/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int distance_downwards(struct node*);
struct node* get_parent(struct node*, int);
int minimum(int, int);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int d = distance_downwards(temp);
	struct node *parent = get_parent(root, temp->data);
	int d1 = get_closest_leaf_distance(root, parent);
	if (d == d1)
		return d1;
	int m = minimum(d1, d);
	if (m == d1)
		return 1 + d1;
	return d;
}
struct node* get_parent(struct node* root, int x)
{
	struct node *lnode = NULL, *rnode = NULL;
	if (root == NULL)
		return NULL;
	if (root->left != NULL)
		if (root->left->data == x)
			return root;
	if (root->right != NULL)
		if (root->right->data == x)
			return root;
	if (root->left != NULL)
		lnode = get_parent(root->left, x);
	if (root->right != NULL)
		rnode = get_parent(root->right, x);
	if (lnode != NULL)
		return lnode;
	else
		return rnode;
}
int distance_downwards(struct node *root)
{
	int ld, rd;
	if (root == NULL)
		return -1;
	if (root->left == NULL && root->right == NULL)
		return 0;
	ld = distance_downwards(root->left);
	rd = distance_downwards(root->right);
	int m = minimum(ld, rd);
	return m + 1;
}
int minimum(int x, int y)
{
	if (x != -1 && y != -1)
		if (x > y)
			return y;
		else
			return x;

	if (x == -1){
		return y;
	}
	if (y == -1){
		return x;
	}
}