// I could be playing camp buddy instead im doing this shit

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *LC; // LC-> elem is lesser than data
    struct node *RC; // RC-> elem is greater than data
} *BST;

// operations

void initBST(BST *B);                       // initializes bst.                                                     IMPLEMENTED
void insert(BST *B, int elem);              // inserts element into bst.                                            IMPLEMENTED
void deleteRoot(BST *B);                    // deletes root element and replaces it with minRight.                  IMPLEMENTED
void deleteElem(BST *B, int elem);          // finds element and calls deleteroot, passing the found element.       IMPLEMENTED
int isMember(BST B, int elem);              // finds element, returns value of the element if found, -1 if not.     NOT IMPLEMENTED


// display operations

void dPreOrder(BST B);                      // displays preorder.                                                   IMPLEMENTED
void dInOrder(BST B);                       // displays inorder.                                                    IMPLEMENTED
void dPostOrder(BST B);                     // displays postorder.                                                  IMPLEMENTED
void dDesc(BST B);                          // displays descending                                                  IMPLEMENTED
void dPreOrderDetailed(BST B, int d, int parent);  // displays detailed preorder, -1 is the parent of root          IMPLEMENTED


// utility functions

void swapElem(int *A, int *B);              // swaps two numbers.                                                   IMPLEMENTED
BST minSuccessor(BST *B, int elem);         // finds highest value to the left of root.                             NOT IMPLEMENTED
BST maxSuccessor(BST *B, int elem);         // finds lowest value to the right of root.                             NOT IMPLEMENTED

int main()
{

    BST BT;

    initBST(&BT);

    insert(&BT, 10);
    insert(&BT, 17);
    insert(&BT, 21);
    insert(&BT, 13);
    insert(&BT, 7);
    insert(&BT, 9);
    insert(&BT, 4);
    insert(&BT, 6);
    insert(&BT, 5);
    insert(&BT, 2);

    dPostOrder(BT);

    int i;
    int deleteArray[10] = {7, 4, 21, 10, 2, 13, 9, 6, 17, 5};

    for (i = 0; i < (sizeof(deleteArray)/4); i++)
    {
        deleteElem(&BT, deleteArray[i]);

        printf("\n\n");

        dPostOrder(BT);
    }

    deleteElem(&BT, deleteArray[i]);
}

// operations

void initBST(BST *B)
{
    *B = NULL;
}

void insert(BST *B, int elem)
{

    BST *trav = B;

    while (*trav != NULL && elem != (*trav)->data)
    {
        trav = (elem > (*trav)->data) ? &(*trav)->RC : &(*trav)->LC;
    }

    if (*trav == NULL)
    {
        BST temp = malloc(sizeof(struct node));
        if (temp != NULL)
        {
            temp->LC = NULL;
            temp->RC = NULL;
            temp->data = elem;
            *trav = temp;
        }
    }
}

void deleteRoot(BST *B)
{
    BST *trav, temp;
    if (*B != NULL)
    {
        if ((*B)->RC != NULL)
        {
            trav = &(*B)->RC;
            while ((*trav)->LC != NULL){ trav = &(*trav)->LC; }
            temp = *trav;
            swapElem(&(*B)->data, &temp->data);
            *trav = (*trav)->RC;
        } else {
            temp = *B;
            *B = (*B)->LC;
        }
        free(temp);
    }
    else{
        printf("\n\nbst is empty lol");
    }
}

void deleteElem(BST *B, int elem)
{
    BST *trav = B;
    while (*trav != NULL && elem != (*trav)->data){
        trav = (elem > (*trav)->data) ? &(*trav)->RC : &(*trav)->LC;
    }
    if (*trav != NULL){
        deleteRoot(trav);
    }
    else{
        printf("\n\nyour elem dont exist boi");
    }
}

// display

void dInOrder(BST B)
{

    if (B != NULL)
    {
        dInOrder(B->LC);

        printf("%d ", B->data);

        dInOrder(B->RC);
    }
}

void dPostOrder(BST B)
{

    if (B != NULL)
    {
        dPostOrder(B->LC);

        dPostOrder(B->RC);

        printf("%d ", B->data);
    }
}

void dPreOrder(BST B)
{

    if (B != NULL)
    {

        printf("%d ", B->data);

        dPreOrder(B->LC);

        dPreOrder(B->RC);

    }
}

void dDesc(BST B){
    if(B != NULL){
        dDesc(B->RC);
        printf("%d ", B->data);
        dDesc(B->LC);
    }
}

void dPreOrderDetailed(BST B, int d, int parent){
    if(B != NULL){
        int i;
        for(i = d; i < d+1; i++){
            printf("\n");
        }
        printf("%d (depth: %d | parent: %d)", B->data, d, parent);
        dPreOrderDetailed(B->LC, d+1, B->data);
        dPreOrderDetailed(B->RC, d+1, B->data);
    }
}

// utility

void swapElem(int *A, int *B)
{
    int c = *A;
    *A = *B;
    *B = c;
}
