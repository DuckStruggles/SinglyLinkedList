#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

  struct sll{
     int val;
     struct sll *next;
  };

struct sll *start, *node;

void createList(struct sll *);
void display(struct sll *);
void insertBegin(struct sll *);
void insertEnd(struct sll *);
void deleteBegin(struct sll *);
void deleteEnd(struct sll *);
void count(struct sll *);
void sortList(struct sll *);
void reverseList(struct sll *);

void main()
{
    int option;
   
    printf("\n MAIN MENU\n1-Create list\n2-Display List\n3-Insert at begining\n4-Insert at end\n5-Delete from beginning\n6-Delete from end\n7-Count number of nodes\n8-Sort Linked List\n9-Reverse Linked List\n10-EXIT\n\n");
    
    while(option !=6)
    {
      printf("Enter option: ");
      scanf("%d", &option);
      switch(option)
      {
         case 1:
         createList(node);
         break;
         
         case 2:
         display(start);
         break;
         
         case 3:
         insertBegin(start);
         break;
         
         case 4:
         insertEnd(start);
         break;
         
         case 5:
         deleteBegin(start);
         break; 
         
         case 6:
         deleteEnd(start);
         
         case 7:
         count(start);
         
         case 8:
         sortList(start);
         
         case 9:
         reverseList(start);
      }
   }  
}

void createList(struct sll *node)
{
   int ch=1;
   struct sll *new;
   while(ch)
   {
      new=(struct sll *)malloc(sizeof(struct sll));
      printf("Enter value of new node (Enter -1 to stop): ");
      scanf("%d",&new->val);
      
      if(new->val==-1)
        break;
        
      new->next=NULL;
      if(node==NULL)
      {
        node=new;
        start=node;
      }  
        
      else
        node->next=new;
      
      node=new;
   }
}
  
void display(struct sll *node)
{
   if(node==NULL)
   {
     printf("List is empty\n");
     return;
   }
   
   while(node!= NULL)
   {
      printf("%d\t",node->val);
      node=node->next;
   }
   printf("\n");
}

void insertBegin(struct sll *node)
{
   struct sll *new;

   new=(struct sll*)malloc(sizeof(struct sll));
   
   printf("Enter value to insert: ");
   scanf("%d",&new->val);
   new->next=node;
   start=new;
}

void insertEnd(struct sll *node)
{
   struct sll *new;
   new=(struct sll*)malloc(sizeof(struct sll));
   
   if(new==NULL)
   {
      printf("Memory not allocated\n");
      exit(1);
   }
   
   printf("Enter value of new node: ");
   scanf("%d",&new->val);
   new->next=NULL;
   
   if(start==NULL)
   {
      start=new;
   }
   
   else
   {   
     while(node->next!=NULL)
     {
        node=node->next;
     }
   
   node->next=new;
   }
}

void deleteBegin(struct sll *node)
{
    struct sll *temp;
    temp=node;
    node=node->next;
    start=node;
    free(temp);
}

void deleteEnd(struct sll *node)
{
   struct sll *prev, *temp;
   while(node->next!=NULL)
   {
      prev=node;
      node=node->next;
   }
   
   temp=node;
   free(temp);
   prev->next=NULL;
}

void count(struct sll *node)
{
   int count=0;
   while(node!=NULL)
   {
     count++;
     node=node->next;
   }  
   
   printf("Number of nodes in list: %d\n",count);
}

void sortList(struct sll *node)
{
   struct sll *i, *j;
   int temp;
   
   for(i=node; i->next!=NULL; i=i->next)
   {
      for(j=i->next; j!=NULL; j=j->next)
      {
         if(i->val > j->val)
         {
            temp=i->val;
            i->val = j->val;
            j->val = temp;
         }
      }
   }         
}

void reverseList(struct sll *node)
{
   struct sll *prev=NULL, *next=NULL;
   
   while(node!=NULL)
   {
      next=node->next;
      node->next=prev;
      prev=node;
      node=next;
   }
   start=prev;
}
   
  
       
