#include<stdio.h>
#include<stdlib.h>
int size = 0;  //keeps track of the number of tasks in the list.
struct node
{
    char task[100];//task description.
    int completed; // 0 for incomplete, 1 for complete.
    struct node *next;
} *First = NULL, *Last = NULL;

struct node* create();
void add_a_task(); //insert a task.
void mark_complete();
void view_task();//display all tasks.
void delete_task();//delete a task.

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n--TO-DO LIST--");//menu for the to-do list.
        printf("\n1.Add a task\n2.Mark a task as complete\n3.View all tasks\n4.Delete a task\n5.Exit\n");
        printf("Enter your choice::");
        scanf("%d", &choice);
        switch(choice)  //switch case for the menu options.
        {
            case 1:
                add_a_task();
                break;
            case 2:
                mark_complete();
                break;
            case 3:
                view_task();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                printf("Thank you for using the To-Do List!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.");
        }
    }
 return 0;
}

struct node* create() //function to create a new task node.
{
    struct node *new_node ;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the task description: ");
    getchar(); // consume the newline character left by previous input.
    fgets(new_node->task, sizeof(new_node->task), stdin);
    new_node->completed = 0 ;
    new_node->next = NULL;
    return new_node;
}

void add_a_task() //function to add a new task to the list.
{
    struct node *new_node = create();
    if(First == NULL)  // check if the list is empty.
    {
        First = Last = new_node;
    }
    else
    {
        Last->next = new_node;
        Last = new_node;
    }
    size++; // increment the size of the list.
    printf("Task added successfully!\n");
}

void view_task() //function to display all tasks.
{
    struct node *temp;
    int count = 1;
    if(First == NULL) //check if the list is empty.
    {
        printf("No tasks available.\n");
        return;
    }
    else
    {
        temp=First;
        while(temp != NULL)
        {
            printf("%d. %s ", count, temp->task); //display the task description.
            if(temp->completed)
                printf(" [Completed]\n");
            else
                printf(" [Incomplete]\n");
            temp = temp->next;
            count++;
        }
    }
}


void delete_task() //function to delete a task from the list.
{
    struct node *temp , *del ,*after;
    int  pos , i;
    if(First == NULL) //check if the list is empty
{
    printf("No tasks available to delete.\n");
}
else if(First == Last)  //check if there is only one task in the list.
{
    printf("Enter the position of the task to delete: ");
    scanf("%d", &pos);

    if(pos != 1)  //check if the position is valid.
    {
        printf("Invalid position! Please try again.\n");
        return;
    }
    free(First);
    First = Last = NULL;
    size--;
    printf("Task deleted successfully!\n");
    return;
}
else
{
printf("Enter the position of the task to delete: ");
scanf("%d", &pos);

temp = First;

if(pos < 1 || pos > size) //check if the position is valid.
{
    printf("Invalid position! Please try again.\n");
    return;
}

if(pos == 1)  //check if the task to delete is the first task in the list.
{
    temp = First->next;
    free(First);
    First = temp;
    printf("Task deleted successfully!\n");
    size--;
    return;
}
 
if(pos == size) //check if the task to delete is the last task in the list.
{
    while(temp->next != Last)
    {
        temp = temp->next;
    }
    free(Last);
    Last = temp;
    Last->next = NULL;
    size--;
    printf("Task deleted successfully!\n");
    return;
}



for(i = 1; i < pos-1; i++) //traverse to the node just before the one to be deleted.
{
    temp = temp->next;
}

del= temp->next;
after = del->next;
temp->next = after; 
free(del);
printf("Task deleted successfully!\n");
size--;
}
}

void mark_complete() //function to mark a task as complete.
{
    struct node *temp;
    int pos , i ;
    if(First == NULL)
    {
        printf("No tasks available to mark as complete.\n"); // Check if the list is empty
        return;
    }
    else
    {
        printf("The tasks available are:\n");
        temp = First;
        for(i = 1; i <= size; i++) // Display the tasks with their positions.
        {
            printf("%d. %s ", i , temp->task);
            temp = temp->next;
        }

        printf("Enter the position of the task to mark as complete: ");  
        scanf("%d", &pos);

        if(pos < 1 || pos > size) // Check if the position is valid.
        {
            printf("Invalid position! Please try again.\n");
            return;
        }

        temp = First;
        for(i = 1; i < pos; i++)
        {
            temp = temp->next;
        } 
       temp->completed = 1;
       printf("Task marked as complete successfully!\n"); // Mark the task as complete.

    }
}
