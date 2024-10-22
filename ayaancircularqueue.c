
#include<stdio.h>
#define size 4
int ch,cq[20],item,i,front=-1,rear=1;
void insert();
int delete();
void display();
void main()
{
    while(1)
    {
    printf("\n1.Insert\n2.Delet\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert();
                break;
        case 2:item=delete();
                if(item!=-1)
                {
                    printf("Deleted element is %d",item);
                }
                break;
        case 3:display();
                break;
        case 4:exit(0);
                break;
    }
    }
}
void insert()
{
    if(front==(rear+1)%size)
    {
        printf("\nCircular queue is full");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%size;
    }
    printf("Enter item to be inserted:");
    scanf("%d",&item);
    cq[rear]=item;
    return;
}
int delete()
{
    if(front==-1)
    {
        printf("Circular queue is empty");
        return(-1);
    }
    item=cq[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
    return(item);
}
void display()
{
    if(front==-1)
    {
        printf("Circular queue is empty");
        return;
    }
    printf("Circular queue contains:\n");
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",cq[i]);
        }
    }
    else
    {
        for(i=front;i<=size-1;i++)
        {
            printf("%d\t",cq[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\t",cq[i]);
        }
    }
    return;
}

