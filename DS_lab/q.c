// WAF to implemet queue operations using stack

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int data)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Queue is full\n");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else if(rear==MAX-1)
    {
        rear=0;
    }   /
    else
    {
        rear++;
    }
    queue[rear]=data;
}

int dequeue()
{
    int data;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if(front==rear)
    {
        data=queue[front];
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        data=queue[front];
        front=0;
    }
    else
    {
        data=queue[front];
        front++;
    }
    return data;
}

void traverse()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front<=rear)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
    else
    {
        for(i=front;i<MAX;i++)
        {
            printf("%d ",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}

int isEmpty()
{
    if(front==-1 && rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int choice,data;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.IsEmpty\n5.IsFull\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                data=dequeue();
                if(data!=-1)
                {
                    printf("Dequeued element is %d\n",data);
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                if(isEmpty())
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                if(isFull())
                {
                    printf("Queue is full\n");
                }
                else
                {
                    printf("Queue is not full\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}