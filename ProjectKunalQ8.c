// trees insertion, deletion
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
        return;
    }

    if (data < (*root)->data)
    {
        insertNode(&(*root)->left, data);
    }
    else
    {
        insertNode(&(*root)->right, data);
    }
}

void deleteNode(struct node **root, int data)
{
    if (*root == NULL)
    {
        return;
    }

    if (data < (*root)->data)
    {
        deleteNode(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        deleteNode(&(*root)->right, data);
    }
    else
    {
        if ((*root)->left == NULL)
        {
            *root = (*root)->right;
        }
        else if ((*root)->right == NULL)
        {
            *root = (*root)->left;
        }
        else
        {
            struct node *temp = (*root)->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }

            (*root)->data = temp->data;
            deleteNode(&(*root)->right, temp->data);
        }
    }
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;

    int choice, data;

    while (1)
    {
        printf("\n1. Insert Node");
        printf("\n2. Delete Node");
        printf("\n3. Inorder Traversal");
        printf("\n4. Preorder Traversal");
        printf("\n5. Postorder Traversal");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            insertNode(&root, data);
            break;

        case 2:
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &data);
            deleteNode(&root, data);
            break;

        case 3:
            printf("\nInorder Traversal: ");
            inorderTraversal(root);
            break;

        case 4:
            printf("\nPreorder Traversal: ");
            preorderTraversal(root);
            break;

        case 5:
            printf("\nPostorder Traversal: ");
            postorderTraversal(root);
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}