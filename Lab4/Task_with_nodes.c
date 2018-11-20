#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node
{
    int value;
    struct node *next_node;
}elem;

void adding_new_item_end(elem *head, int val_vstavky)
{
    elem *current = head;
    while (current->next_node != NULL)
    {
        current = current->next_node;
    }
    current->next_node = malloc(sizeof(elem));
    current->next_node->value = val_vstavky;
    current->next_node->next_node = NULL;
}
void print_elements(elem *head)
{
    elem *current = head;
    while (current->next_node != NULL)
    {
        printf("%d ", current->value);
        current = current->next_node;
    }
}
int delete_the_first_element(elem **head)
{
    elem *next_to_head = NULL;
    if (head == NULL)
    {
        return -1;
    }
    next_to_head = (*head)->next_node;
    free(*head);
    *head = next_to_head;
    return 1;
}
int delete_the_element_i(elem **head, int index)
{
    elem *current = *head;
    elem *temp = NULL;
    if (index == 0)
    {
        delete_the_first_element(head);
        return 0;
    }
    for (int i = 0; i< index-1; i++)
    {
        if (current->next_node == NULL)
        {
            return -1;
        }
        current = current->next_node;
    }
    temp = current->next_node;
    current->next_node = temp->next_node;
    free(temp);
    return 1;
}
int main()
{
    int n,k;
    srand(time(NULL));

    //inicializing the head of the list
    elem *head = NULL;
    // make space for head
    head = malloc(sizeof(elem));
    if (head == NULL)
    {
        return 1;
    }
    head->value = rand()%10;

    printf("Enter number of elements in the list: ");
    scanf("%i",&n);

    for (int i = 0; i<n;i++)
    {
        int r = rand()%10;
        adding_new_item_end(head, r);
    }
    print_elements(head);
    printf("\n");
    printf("Enter element k to be deleted: ");
    scanf("%i", &k);
    if (k > n)
    {
        printf("Wrong index");
        return 0;
    }

    delete_the_element_i(&head, k-1);
    print_elements(head);
}