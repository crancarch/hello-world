#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
int max;
void push(struct Node** head_ref, int new_data)
{

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

/* Counts no. of nodes in linked list */
int getCount(struct Node* head)
{
    int count = 0;  // Initialize count
    struct Node* current = head;   // Initialize current
    max =  current->data;
    while (current != NULL)
    {
        count++;
        if(max < current->data)
        {
            printf("before %d %d\n",max,current->data);
            max=current->data;
            printf("after %d %d\n",max,current->data);
        }
        current = current->next;
    }
    return count;
}

int getMax(struct Node* head)
{
    struct Node* current = head;   // Initialize current
    max =  current->data;
    while (current != NULL)
    {
        if(max < current->data)
        {
            printf("before %d %d\n",max,current->data);
            max=current->data;
            printf("after %d %d\n",max,current->data);
        }
        current = current->next;
    }
    return max;
}

/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Use push() to construct below list
     1->2->1->3->1  */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    /* Check the count function */
    printf("count of nodes is %d and max is %d", getCount(head), getMax(head));
    return 0;
}
