#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 typedef struct doublyList{
    int data;
    struct doublyList* prev,*next;
}list;

list* create(list* head){
list* temp,*p;int num;
temp=(list*)malloc(sizeof(list));
    printf("\n Enter num = ");
    scanf("%d",&num);
    temp->data=num;
    temp->prev =NULL;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }else{
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
          p->next=temp;
          temp->prev=p; 
    }
    printf("\n 1 node created.");
    return head;
}

list* insertFirst(list* head){
list* temp;
int num;
printf("\n Enter num = ");
scanf("%d",&num);
temp=(list*)malloc(sizeof(list));
temp->data=num;
temp->prev=NULL;
temp->next=NULL;
if(head==NULL){
    head=temp;
}else{
    temp->next=head;
    head->prev=temp;
    head=temp;
}
 printf("\n 1 node inserted at first.");

return head;
}

list* insertAtpos(list* head){
    list* temp,*p,*t;
    int pos,k=0,ctr=0;
    printf("\nEnter position = ");
    scanf("%d",&pos);
    p=head;
   while(p!=NULL){
    ctr++;
    p=p->next;
   }
    if(pos<1 || pos>ctr){
      printf("\n given node posititon not exist");
    }else{
     temp=(list*)malloc(sizeof(list));
     printf("Enter number = ");
     scanf("%d",&temp->data);
     temp->prev=NULL;
     temp->next=NULL;
     if(pos==1){
       temp->next=head;
       head->prev=temp;
       head=temp;
     }else{
        k=2;
        p=head->next; // beacuse first position pe ho chuki hai insert if me condition check hoke
        while(p!=NULL){
         if(pos==k){
           p->prev->next=temp;
           temp->prev=p->prev;
           temp->next=p;
           p->prev=temp;
           break;
         }
         k++;
         p=p->next;
        }
     }
     printf("\n 1 node inserted at %d",pos);
   }
   return head;
}

list* deleteFirst(list* head){
    list* temp,*p;
    int n=-1;
    if(head==NULL){
        printf("\n List is empty");
    }else{
       p=head;
       n=head->data;
       head=head->next;
       free(p);
       if(head!=NULL){
            head->prev=NULL;
       }
       printf("\n%d is deleted",n);
    }
    return head;
}

list* deleteFrompos(list* head){
    list* p;
    int k,ctr=0,pos,n;
    p=head;
    while(p!=NULL){
        ctr++;
        p=p->next;
    }
    printf("\nEnter position num to delete the node = ");
    scanf("%d",&pos);
    if(pos<1 || pos>ctr){
        printf("no position exist at this node");
    }else{
        if(pos==1){
         p=head;
         n=head->data;
         head=head->next;
         free(p);
          printf("\n %d is deleted",n);
        }else{
            k=2; // because for position 1 it is handled above that's why we start with k=2;
            p=head->next;
            while(p!=NULL){
                if(pos==k){
                   n=p->data;
                   p->prev->next=p->next;
                   p->next->prev=p->prev;
                   free(p);
                   printf("\n %d is deleted",n);
                   break;
                }
                k++;
                p=p->next;
            }
        }
    }
    return head;
}
list* deleteEnd(list* head){
   list *p;
   int n;
   if(head==NULL){
    printf("\n List is empty");
   }else{
    if(head->next==NULL){
       p = head;
        n=head->data;
        head=NULL;
        free(p);
        printf("\n %d is deleted",n);
    }else{
       p=head;
       while(p->next!=NULL){
        p=p->next;
       }
       n=p->data;
       p->prev->next=NULL;
       free(p);
       printf("\n %d is deleted",n);
   }
   }
   return head;
}

void display(list* head){
    list* p;
    if(head==NULL){
        printf("\nList is empty");
    }else{
        p=head;
        while(p!=NULL){
            printf("%d->",p->data);
            p=p->next;
        }
    }
}
int count(list* head){
     int ctr=0;
     list* p;
     if(head==NULL){
        printf("\nlist is empty");
     }else{
       p=head;
       while(p!=NULL){
        ctr++;
       p=p->next;
       }
     }
     return ctr;
}

void search(list* head){
    list* p;
    int f=0,num;
   if(head==NULL){
    printf("\n List is empty");
   }else{
    printf("Enter search value = ");
    scanf("%d",&num);
    p=head;
    while(p!=NULL){
        if(num==p->data){
            f=1;
            break;
        }
        p=p->next;
     }
      if(f==1){
    printf("\n Search value found");
    }
      else{
    printf("\n Search value not found");
   }
   }
}

void main(){
   list *head=NULL;
   int n,num,position=0;
   while(1){
    printf("\n 1. create");
    printf("\n 2. insertFirst");
    printf("\n 3. insertAtpos");
    printf("\n 4. deleteFirst");
    printf("\n 5. deleteFrompos");
    printf("\n 6. deleteEnd");
    printf("\n 7. display");
    printf("\n 8. count");
    printf("\n 9. search");
    printf("\n 10. exit");
    printf("\n Enter your choice  = ");
    scanf("%d",&n);
    switch(n){
        case 1:
        head = create(head);
        break;
        case 2:
        head = insertFirst(head);
        break;
        case 3:
        head = insertAtpos(head);
        break;
        case 4:
        head = deleteFirst(head);
        break;
        case 5:
        head = deleteFrompos(head);
        break;
        case 6:
        head = deleteEnd(head);
        break;
        case 7:
        display(head);
        break;
        case 8:
       n = count(head);
       printf("\nnum of node is %d",n);
        break;
        case 9:
        search(head);
        break;
        case 10:
        exit(0);
        default :
        printf("\n Invalid choice number");
    }
    getch();
   } 
}