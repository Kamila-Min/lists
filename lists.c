#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <string.h>
#include <malloc.h>

typedef struct list
{
  int elem;
  struct list *next;
}List;

void print_list (List*);

List* insert_end (List *head, int y);

List* insert_middle_after (List *head, int x, int y);

List *delete_last_elem (List* head);

List *delete_elem (List* head, int x);

void list_destroy (List *head);

void list_in_file (List *head);

int main()
{
	List *head = NULL, *current, *prev;
	 
    int q = 0;

    int k = 0;

    while (k != 1)
    {
        printf ("Please, choose one of this actions and enter the appropriate number:\n");
        printf ("1. Creating the list\n");
        printf ("2. Inserting a first link\n");
        printf ("3. Inserting a link in the end of list\n");
        printf ("4. Inserting a link before or after the link with the entered value\n");
        printf ("5. Deleting the first link\n");
        printf ("6. Deleting the last link\n");
        printf ("7. Deleting the link with entered value\n");
        printf ("8. Entering the list into file\n");
        printf ("9. Printing the list\n");
        printf ("10. Deleting the list\n");

        scanf ("%d", &q);
        
        switch (q)
        {
            case 1:
             {
                printf ("Creating the list:\n");
 
	            int i = 0;

                printf ("Write the sequence of links\n");

                for (i = 0; i < 10; i++)
	            { 
                  current = (List*) malloc (sizeof(List)); //теперь для current выделили память 
		          
                  if (head == NULL)
                    head = current;
		          else prev->next = current;
                           
                  scanf("%d", &current->elem);
		          
                  current->next = NULL;
		          
                  prev = current;
	            }
                  print_list (head); 

                  printf ("\n");               
             }

             break;

            case 2:
            {
                printf ("Inserting a one link:\n");

                printf ("Enter the value of link\n");

                int v = 0;
                scanf ("%d", &v);

                List *temp;

                temp = (List*) malloc(sizeof(list));
      
                temp->elem = v; 
    
                temp->next = head; 

                head = temp;

                printf ("The link with value %d is inserted\n", v);
            }
            break;

            case 3:
            {
                printf ("Inserting a link in the end of list:\n");

                printf ("Enter the new node's value\n");

                int y = 0;

                scanf ("%d", &y);

                printf ("Inserting the node - %d\n", y);

                insert_end (head, y);
                printf ("\n");
            }
            break;

            case 4:
            {
                printf ("Inserting a link after the link with the entered value\n");

                printf ("Enter the link's value, after which the new link must be inserted\n");

                int y = 0;

                scanf ("%d", &y);

                printf ("Enter the new link's value\n");

                int x = 0;

                scanf ("%d", &x);

                insert_middle_after (head, x, y);
                printf ("\n");
            } 
            break;

            case 5:
            {
                printf ("Deleting the first link\n");

                if (head == 0)
                {
                  printf ("ERROR, the list is empty\n");
                  return 0;
                }

                  List *p, *current;

                  p = (List*) malloc(sizeof(list));

                  p = head;

                  head = head->next;

                  free (p);

                printf ("\n");
            }   
            break;

            case 6:
            {
                printf ("Deleting the last link\n");

                if (head == 0)
                {
                  printf ("ERROR, the list is empty\n");
                  return 0;
                }
       
                  List *current, *prev, *p;

                  p = (List*) malloc(sizeof(list));

                  current = head;
                  prev->next = current;

                  while (current != NULL)
	              {
	                if (current->next == NULL)
                    {
                      prev->next = NULL;
                      p = current;
                      free (p);
                    }
                      prev = current;
                      current = current->next;
                  }
            }
            break;

            case 7:
            {
                printf ("Deleting the link with entered value\n");

                printf ("Enter the value of link\n");

                int x = 0;
                scanf ("%d", &x);

                if (head == 0)
                {
                  printf ("ERROR, the list is empty\n");
                  return 0;
                }
       
                  List *current, *prev, *p;
    
                  current = head;

                  while (current != NULL)
	              {      
                    if (current->elem == x)
                    {
                      p = current->next;
                      prev->next = p;
                      free (current);
                    }
                      current = current->next;
	              }
                printf ("\n");
            }
            break;

            case 8:
            {
                printf ("Entering the list into file:\n");

                list_in_file (head);

                printf ("\n");

            }
            break;

            case 9:
            {
                printf ("Printing the list:\n");

                print_list (head);

                printf ("\n");
            }
            break;

            case 10: 
            {
                printf ("Deleting the list:\n");

                list_destroy (head);

                printf ("\n");
            }
            break; 

        }

        printf ("If you want to continue, enter 0, else - enter 1\n");

        scanf ("%d", &k);
    }

    return 0;
}
      
void print_list (List *head)
{
	List *current;

    printf ("%d\n", head->elem);

	current = head;
	
    while (current != NULL)
	{
	  printf("%d   ",current->elem);
	  current = current->next;
    }
	return;
}

List* insert_end (List *head, int y)
{
    List *current, *p;

    p = (List*) malloc(sizeof(List));

    p->elem = y;

	current = head;

    if (head == NULL)
     {
        head->next = p;
        p->next = NULL; 
        return head;  
	 }

    while (current != NULL)
	{
	   if (current->next == NULL)
       {
           current->next = p;
           p->next = NULL;
       }
       current = current->next;
       
    }

	return head;
}

List* insert_middle_after (List *head, int x, int y)
{
    List *current, *temp, *p;

    temp = (List*) malloc(sizeof(List));

    temp->elem = x;
 
    if (head == NULL)
     {
        head->next = temp;
        temp->next = NULL;
        return head;
     }      

    current = head;

    while (current != NULL)
	{ 
      if (current->elem == y)
       {
           p = current->next;
           current->next = temp;
           temp->next = p;
       }
        current = current->next;
	}

    return head;
}

List *delete_last_elem (List* head)
{
    if (head == 0)
     {
        printf ("ERROR, the list is empty\n");
        return 0;
     }
       
    List *current, *prev;

    current = head;

    while (current != NULL)
	{
	   if (current->next == NULL)
       {
           prev->next = NULL;
           free (current);
       }
       current = current->next;       
    }

    printf ("HI\n");

    return head;
}

List *delete_elem (List* head, int x)
{
    if (head == 0)
     {
        printf ("ERROR, the list is empty\n");
        return 0;
     }
       
    List *current, *prev, *p;
    
    current = head;

    while (current != NULL)
	{      
      if (current->elem == x)
       {
           p = current->next;
           prev->next = p;
           free (current);
       }
       current = current->next;
	}

    return head;
}

void list_destroy (List *head)
{
    if (head == 0)
     {
        printf ("ERROR, the list is empty\n");
        return;
     }
    List *p, *current;

    current = head;
    
    while (current == NULL)
    {
        p = current;
        free (p);
        current = current->next;
    }

    head = NULL;
}

void list_in_file (List *head)
{
    if (head == 0)
     {
        printf ("ERROR, the list is empty\n");
        return;
     }

    List *current; 

    current = head; 

    FILE *f;

    f = fopen ("file5.txt", "w");

    fclose(f);

    return;
} 
