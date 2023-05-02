#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct nodeType{
    struct nodetype *prev;
    int info;
    struct nodeType *next;
}node;
/*function prototypes*/
void createEmptyList(node **head,node **tail);
void traverseInOrder(node *head);
void traverseInReverseOrder(node *tail);
node *search(node *head,int item);
void insertAtBeginning(node **head,node **tail,int item);
void insertAtEnd(node **head,node **tail,int item);
void insertAfterElement(node *head,node **tail,int item,int after);
void insertBeforeElement( node **head, int item, int before ); 
void deleteFromBeginning (node **head, node **tail);
void deleteFromEnd( node **head, node **tail );
void deleteBeforeElement( node **head, int before );
void deleteAfterElement (node *head, node **tail, int after );
void deleteList( node **head, node **tail );


void main()
{
    int choice,element,after,before;
    node *head,*tail;
    createEmptyList(&head,&tail);
    while(1)
    {
        printf("option available\n");
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert after a given element\n");
        printf("4.Insert before a given element \n");
        printf("5. Traverse in order\n");
        printf("6. Traverse in Reverse order\n");
        printf("7. Delete from beginning\n");
        printf(" 8. Delete from end\n");
        printf("9. Delete after a given element \n");
        printf("10. Delete before a given element \n");
        printf("11.Exit \n");
        printf("Enter your choice (1-11):");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:printf("\nEnter element:");
                 scanf("%d",&element);
                 insertAtBeginning(&head,&tail,element);
                 break;
          case 2: printf("\nEnter element:");
                  scanf("d", &element );
                  insertAtEnd(&head, &tail, element);
                  break;

           case 3:printf("\nEnter element:");
                  scanf("d", &element ); 
                  printf("\nEnter element after which to insert:");
                  scanf("%d", &after );
                  insertAfterElement( head, &tail, element, after);
                  break;
            case 4 :printf("\nEnter element :");
                    scanf("%d",&element);
                    printf("\nEnter element before which to insert :");
                    scanf("%d", &before);
                    insertBeforeElement(&head, element, before );
                    break;
            case 5:if(head == NULL) 
                      printf("\nlist is empty...");
                   else
                      traverseInorder( head ); 
                      printf("\n\nPress any key to continue...");
                      getch();
                      break;
            case 6: if(head == NULL)
                      printf("\nlist is empty....");
                    else
                    traverseInReverseOrder( tail );
                    printf("\n\nPress any key to continue....");
                    getch(); 
                    break;
            case 7: deleteFromBeginning(&head, &tail);
                    break; 
            case 8: deleteFromEnd ( &head, &tail );
                    break; 
            case 9: printf("\nEnter element after which to delete : ");
                    scanf("%d", &after);
                    deleteAfterElement(head, &tail, after );
                    break;
            case 10: printf("\nEnter element before which to delete :");
                     scanf("%d", &before );
                     deleteBeforeElement(&head, before );
                     break;
            case 11: deletelist(&head, &tail ) ;
                     exit(1);

        }
    }
}
    /*end of main function */
void createEmptyList( node **head, node **tail ){
        *head=*tail=NULL;
}
void traverseInOrder( node *head){
    while(head !=NULL)
    {
        printf("%d ", head->info); 
        head =head->next;
    }
}

void traverseInReverseOrder( node *tail)
{ 
    while (tail != NULL)
    {
      printf("%d", tail->info );
      tail =tail->prev;
    }
}

node *search(node *head, int item) {
  while(head != NULL) 
  { 
    if (head->info== item)
       return head; 
    head= head->next;
  }
  return NULL;
}

void insertAtBeginning(node **head, node **tail, int item) {
    node *ptr; 
    ptr =(node *)malloc(sizeof(node));
    ptr->info= item;
    if(*head== NULL) 
    { 
        ptr->next=ptr->prev=NULL;
        *head=*tail= ptr;
    } else {
     ptr->prev= NULL; 
     ptr->next=*head;
     (*head)->prev = ptr; 
      *head =ptr;
    }
}
void insertAtEnd( node **head, node **tail, int item) {
   node *ptr; 
   ptr= (node *)malloc(sizeof (node));
   ptr->info =item; 
   if(*head ==NULL) {
     ptr->next = ptr->prev= NULL;
     *head=*tail=ptr;
    } else {
     ptr->next = NULL; 
     ptr->prev =*tail;
     (*tail)->next = ptr;
      *tail =ptr;
    }
}
void insertAfterElement(node *head, node **tail, int item, int after){
   node *ptr, *loc;
   ptr = head;
   loc =search (ptr, after ); 
   if (loc== NULL)
     return;
   ptr = (node *)malloc(sizeof (node));
   ptr->info = item; 
   if (loc->next ==NULL){
     ptr->next =NULL;
     ptr->next=ptr;
     ptr->prev=*tail;
     *tail=ptr;
   }else{
    ptr->prev=loc;
    ptr->next= loc->next;
    (loc->next)->prev=ptr;
    loc->next =ptr;
   }
}
void insertBeforeElement( node **head, int item, int before){
   node *ptr, *loc;
   ptr=* head; 
   loc =search (ptr, before );
   if (loc== NULL)
    return;
   ptr=(node *)malloc(sizeof (node));
   ptr->info= item;
   if(loc->prev = NULL){
    ptr->prev= NULL;
    loc->prev =ptr; 
    ptr->next = *head;
    *head =ptr; 
    }  else {
       ptr->prev = loc->prev;
       ptr->next =loc;
       (loc->prev)->next=ptr;
       loc->prev=ptr;
    }
}

void deleteFromBeginning(node **head, node **tail) {
    node *ptr; 
    if (*head== NULL)
      return; 
     ptr= *head;
    if(*head == *tail ) /*one element only */
       *head=*tail = NULL;
    else {
      (ptr->next)->prev = NULL; 
      *head= ptr->next;
    }
    free(ptr);
}
void deleteFromEnd( node **head, node **tail ) {
   node *ptr; 
   if(*head == NULL)
     return;
   ptr=*tail;
   if(*head ==*tail ) /*one element only */
      *head=*tail = NULL; 
   else{
     (ptr->prev)->next = NULL;
      *tail=ptr->prev;
   }
   free(ptr);
}
void deleteAfterElement( node *head, node **tail, int after) {
     node *ptr, *loc; 
     ptr = head;
     loc= search (ptr, after ); 
     if (loc= NULL)
        return;
    else if ((loc->next)->next == NULL ) {
        ptr =loc->next;
        loc->next = NULL; 
        *tail = loc;
        free(ptr); 
    }
    else{
       ptr=loc->next; 
       loc->next = ptr->next;
       (ptr->next)->prev = loc;
        free(ptr);
    }
}
void deleteBeforeElement( node **head, int before ) {
    node *ptr, *loc;
    ptr = *head;
    loc =search( ptr, before );
    if ( loc= NULL)
       return;
    else if( (loc->prev)->prev == NULL){
       ptr=loc->prev; 
       loc->prev =NULL;
       *head =loc;
       free(ptr);
    }else{
         ptr= loc->prev;
         loc->prev= ptr->prev;
         (ptr->prev)->next = loc;
         free(ptr);
    }
}
void deleteList( node **head, node **tail ){
   node *ptr;
   while ( *head != NULL) 
   { 
    ptr =*head;
    *head= (*head)->next;
     free(ptr);
   }
   *tail=NULL;
}