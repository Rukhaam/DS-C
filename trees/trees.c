#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *left;
  struct Node *right;
  int data;
};

struct Node *createNode(int data)
{

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
};

void inorder(struct Node *root)
{

  if (root == NULL)
    return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
  return root;
};
void preorder(struct Node *root)
{

  if (root == NULL)
    return;

  printf("%d", root->data);
  preorder(root->left);
  preorder(root->right);
};

void postorder(struct Node *root)
{

  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf(root->data);
};
int main()
{
  struct Node *root = createNode(10);

  root->left = createNode(20);
  root->right = createNode(30);

  root->left->left = createNode(40);
  root->left->right = createNode(50);

  printf("Preorder : ");
  preorder(root);

  printf("\nInorder : ");
  inorder(root);

  printf("\nPostorder : ");
  postorder(root);

  return 0;
}