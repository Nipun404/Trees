#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct tree
{
    struct tree *lch;
    int data;
    struct tree *rch;
};
typedef struct tree node;
node *root = NULL, *cur, *left, *right, *new1;
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void main()
{
    int ch;
    char c;
    system("cls");
    do
    {
        printf("\n\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n");
        printf("\nEnter option\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            new1 = (node *)malloc(sizeof(node));
            printf("\nEnter data\n");
            scanf("%d", &new1->data);
            new1->lch = new1->rch = NULL;
            if (root == NULL)
                root = new1;
            else
                insert(root, new1);
            break;
        case 2:
            if (root == NULL)
                printf("\nList is empty\n");
            else
            {
                printf("\nInorder traversal is: ");
                inorder(root);
            }
            break;
        case 3:
            if (root == NULL)
                printf("\nList is empty\n");
            else
            {
                printf("\nPreorder traversal is: ");
                preorder(root);
            }
            break;
        case 4:
            if (root == NULL)
                printf("\nList is empty\n");
            else
            {
                printf("\nPostorder traversal is: ");
                postorder(root);
            }
            break;
        default:
            printf("\nWrong option\n");
        }
        printf("\nDo you want to continue?(y/n)\n");
        c = getche();
    } while (c == 'y');
    getch();
}
void insert(node *cur, node *new1)
{
    if (new1->data > cur->data)
    {
        if (cur->rch != NULL)
            insert(cur->rch, new1);
        else
            cur->rch = new1;
    }
    else if (new1->data < cur->data)
    {
        if (cur->lch != NULL)
            insert(cur->lch, new1);
        else
            cur->lch = new1;
    }
}
void inorder(node *cur)
{
    if (cur != NULL)
    {
        inorder(cur->lch);
        printf("%d  ", cur->data);
        inorder(cur->rch);
    }
}
void preorder(node *cur)
{
    if (cur != NULL)
    {
        printf("%d  ", cur->data);
        preorder(cur->lch);
        preorder(cur->rch);
    }
}
void postorder(node *cur)
{
    if (cur != NULL)
    {
        postorder(cur->lch);
        postorder(cur->rch);
        printf("%d  ", cur->data);
    }
}