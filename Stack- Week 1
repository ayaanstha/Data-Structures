#include <stdio.h>
#define MAX 3
int s[10], TOP = -1, i, item,ch;
void Push();
int pop();
void Display();
void main(){
while(1){
printf("\n 1 PUSH\n\ 2 POP\n 3 DISPLAY\n 4 EXIT");
printf("\n Enter your choice \n");
scanf("%d", &ch);
switch(ch)
{
case 1:
        Push();
        break;
case 2:
        item = pop();
        if(item != -1){
            printf("Popper element = %d\n", item);
        }
        break;
case 3:
        Display();
        break;
case 4:
        exit(0);
}
}
getch();
}
void Push()
{
if(TOP == MAX-1){
printf("STACK OVERFLOW \n");
return;
}
printf("Enter element to be pushed \n");
scanf("%d", &item);
TOP = TOP+1;
s[TOP] = item;
}
int pop(){
if(TOP == -1){
    return -1;
}
item = s[TOP];
TOP = TOP - 1;
return item;
}
void Display()
{
if(TOP == -1){
    printf("STACK IS EMPTY\n");
    return ;
    }
    printf("STACK CONTENTS\n");
    for(i = TOP; i >= 0; i--){
        printf("%d\n", s[i]);
    }
}
