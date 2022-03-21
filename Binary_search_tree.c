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
node *root = NULL, *cur, *left, *right, *new1, *temp;
void insert(node *, node *);
void traverse(node *);
void del(int, node *);
void main()
{
    int ch, key, val;
    char c;
    system("cls");
    do
    {
        printf("\n\n1.Insert\n2.Delete\n3.Traverse\n");
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
            if (root != NULL)
            {
                printf("\nEnter node to be deleted\n");
                scanf("%d", &key);
                del(key, root);
            }
            else
            {
                printf("\nTree is empty.\n");
            }
            break;
        case 3:
            if (root != NULL)
            {
                printf("\nElements are: ");
                traverse(root);
            }
            else
            {
                printf("\nTree is empty.\n");
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
void traverse(node *cur)
{
    if (cur != NULL)
    {
        traverse(cur->lch);
        printf("%d  ",cur->data);
        traverse(cur->rch);
    }
}
void del(int k, node *cur)
{
    node *r1, *par, *cur1, *bak;
    par = cur;
    // search
    while (cur != NULL)
    {
        if (k > cur->data)
        {
            par = cur;
            cur = cur->rch;
        }
        else if (k < cur->data)
        {
            par = cur;
            cur = cur->lch;
        }
        else if (k == cur->data)
            break;
    }
    if (cur == NULL)
    {
        printf("\n%d element is not present in the tree.\n", k);
    }
    else
    {
        // no child
        if ((cur->lch == NULL) && (cur->rch == NULL) && par == cur)
        {
            root = NULL;
        }
        else if ((cur->lch == NULL) && (cur->rch == NULL) && par != cur)
        {
            if (par->lch == cur)
                par->lch = NULL;
            else
                par->rch = NULL;
        }
        // one child(lch)
        else if ((cur->lch != NULL) && (cur->rch == NULL))
        {
            if (par != cur)
            {
                if (par->lch == cur)
                    par->lch = cur->lch;
                else
                    par->rch = cur->lch;
            }
            else
            {
                root = cur->lch;
            }
        }

        // one child(rch)
        else if ((cur->lch == NULL) && (cur->rch != NULL))
        {
            if (par != cur)
            {
                if (par->lch == cur)
                    par->lch = cur->rch;
                else
                    par->rch = cur->rch;
            }
            else
            {
                root = cur->rch;
            }
        }
        // 2 childs are available
        else if ((cur->lch != NULL) && (cur->rch != NULL))
        {
            // min of left sub tree
            cur1 = cur->lch;
            bak = cur1;
            while (cur1->rch != NULL)
            {
                bak = cur1;
                cur1 = cur1->rch;
            }
            cur->data = cur1->data;
            // left sub tree does not have Right
            if (bak == cur1)
                cur->lch = cur1->lch;
            // greater node has lch
            else if (cur1->lch != NULL)
                bak->rch = cur1->lch;
            else
                bak->rch = NULL;
        }
    }
}