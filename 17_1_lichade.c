#include<stdio.h>
#define Max 15
int main()
{
   int stk[Max];
   int val,top=-1,ch,n;
   char res;
   printf("\nMenu:");
   printf("\n1.Push\n2.Pop\n3.Peek\n4.display\n");
   do{
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
    case 1:
    //push
    if(top==Max-1)
    {
        printf("\nStack is overflow\n");
    }
    else 
    {
        printf("\nEnter the number you want to add in stack:");
        scanf("%d",&n);
        top++;
        stk[top]=n;
        printf("\nNumber %d is pushed into the stack",stk[top]);
        
    }
    break;
    case 2:
    //pop
    if(top==-1)
    {
        printf("\nStack is Underflow");
    }
    else
    {
        printf("\nEnter the number that you want to pop from the stack:");
        scanf("%d",&n);
        val=stk[top];
        top--;
        printf("\n%d is popped",val);
    }
    break;
    case 3:
    //peek
    if(top==-1)
    {
        printf("\nStack is Underflow");
    }
    else
    {
        printf("\nElement at top is %d",stk[top]);
    }
    break;
    case 4:
    //display
    printf("\nElements in the stack are:\n");
    while(top!=-1)
    {
        printf("\nElement at %d is %d",top, stk[top]);
        top--;
    }
    break;
} 
printf("\nDo you want to continue?  ");
scanf(" %c",&res);
   }while(res=='y');
}