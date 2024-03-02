#include <stdio.h>

// Define the maximum size of the stack
#define MAX_SIZE 5

int stack[MAX_SIZE];

// Initialize top to -1 (empty stack)
int top = -1;


// Function prototypes
void push(int data);
int pop();
void display();
int is_empty();
int is_full();

void msgEmpty();
void msgFull();

int main()
{
    int choice, data;

    while (choice != 5)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Check Status");
        printf("\n5. Exit\n\n");
        printf("--------------------------------");
        printf("\nEnter Your Choice\n");
        // scanf(" %d", &choice);
        // loop until a valid integer is entered
        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter an integer(1-5): ");
            //clear the input buffer
            scanf("%*[^\n]");
            continue;
        }

        switch (choice)
        {
        case 1: //push
            printf("Enter data to push into stack: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2: //pop
            data = pop();
            if (data != -1)
                printf("Poped data: %d\n", data);
            break;
        case 3: //display
            display();
            break;
        case 4: //status
            printf("\n\nStatus:");
            if (is_empty())
            {
                msgEmpty();
            }
            else if (is_full())
            {
                msgFull();
            }
            else
                printf("Stack has Element");
            break;
        case 5: //exit
            printf("Exiting...\n\n");
            return 0;
        default:
            printf("\n\nInvalid Choice....");
            printf("Please enter integer (1-5)");
        }
    }
    return 0;
}

// function to push elements into stack
void push(int data)
{
    if (is_full())
    {
        msgFull();
        return;
    }

    stack[++top] = data;
}

// Function to pop element from the stack
int pop()
{
    if (is_empty())
    {
        msgEmpty();
        return -1;
    }

    return stack[top--];
}

// Function to display elements of the stack
void display()
{
    if (is_empty())
    {
        // printf("Stack is empty\n");
        msgEmpty();
        return;
    }
    printf("Stack elements:\n ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}



// function to check if stack is empty
int is_empty()
{
    return top == -1;
}

// function to check if stack is full
int is_full()
{
    return top == MAX_SIZE - 1;
}


void msgEmpty()
{
    printf("\n\n");
    printf("------------------------");
    printf("\n|   Stack is empty      |\n");
    printf("------------------------");
    printf("\n\n");
}

void msgFull()
{
    printf("\n\n");
    printf("------------------------");
    printf("\n|   Stack is full      |\n");
    printf("------------------------");
    printf("\n\n");
}
