#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct queueList
{
    int data;
    struct queueList *next;
} list;
list *rear = NULL, *front = NULL;
void insert()
{
    list *temp;
    int num;
    temp = (list *)malloc(sizeof(list));
    printf("Enter num = ");
    scanf("%d", &num);
    temp->data = num;
    temp->next = NULL;
    if (rear == NULL)
    {
        rear = temp;
        if (front == NULL)
        {
            front = rear;
        }
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    printf("\n 1 node inserted");
}

void delete()
{
    list *temp;
    int num = -1;
    if (front == NULL)
    {
        printf("\n queue list is empty");
    }
    else
    {
        temp = front;
        num = temp->data;
        front = front->next;
        free(temp);
    }
    if(front==NULL){
        rear=NULL;
    }
    if (num != -1)
    {
        printf("%d is deleted", num);
    }
}
void display()
{
    list *temp;
    if (front == NULL)
    {
        printf("\n queue list is empty");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void main()
{
    int n;
    while (1)
    {
        printf("\n");
        printf("\n 1.insert");
        printf("\n 2.delete");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n Enter choice number = ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Invalid input");
        }
    }
}