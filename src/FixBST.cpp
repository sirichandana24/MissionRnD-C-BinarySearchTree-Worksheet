/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void bst_fixed(struct node*, struct node**, struct node**, struct node**, struct node**);
void swap(int*, int*);
void fix_bst(struct node *root)
{
	struct node *start, *middle, *end, *prev;
	start = middle = end = prev = NULL;
	bst_fixed(root, &start, &middle, &end, &prev);
	if (start != NULL && end != NULL)
		swap(&(start->data), &(end->data));
	else if (start != NULL && middle != NULL)
		swap(&(start->data), &(middle->data));
}
void bst_fixed(struct node* root, struct node** start, struct node** middle, struct node** end, struct node** prev)
{
	if (root != NULL)
	{
		bst_fixed(root->left, start, middle, end, prev);
		if (*prev && root->data < (*prev)->data)
		{
			if (*start == NULL)
			{
				*start = *prev;
				*middle = root;
			}
			else
				*end = root;
		}
		*prev = root;
		bst_fixed(root->right, start, middle, end, prev);
	}
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
