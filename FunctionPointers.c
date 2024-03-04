#include<stdio.h>

int (*fp)();    // Declaration for pointer to a function
int (*ad)(int,int); //Function pointer Declaration
int func();
int addition(int,int);
void func1(int, void (*fp)(int));

float add(float, float);
float sub(float, float);
float mul(float, float);
float div(float, float);

float (*f[])(float, float) = {add, sub, mul, div};

void main()
{
    int a = 5, b = 1, result, operator_choice;
    float num1, num2, res;

    printf("Address of func: %u",func);
    fp = func;      //Assigning function address to fp function pointer
    func();
    ad = addition;     //Assigning function pointer
    result = (*ad)(a,b);
    printf("\nSum: %d\n",result);

    // to send a function's address as an argument to other function
    func1(4, fp);

    while(1)
    {   // to understand the use of array of function pointers
        printf("\nEnter the floating numbers to be operated on:\n");
        scanf("%f%f",&num1,&num2);
        printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Division\nEnter your choice:\t");
        scanf("%d",&operator_choice);
        res = (*f[operator_choice-1])(num1,num2);
        printf("Result is %.2f\n",res);
    }
    return 0;
}
int func()
{
    printf("\nInside func with address: %u\n",fp);
    return 0;
}
void func1(int a,void (*fpp)(int))
{
    printf("\nAddress of passed function: %u\n",fpp);
    printf("Passed Variable : %d\n",a);
}
int addition(int x, int y)
{
    return (x+y);
}
float add(float a,float b)
{
    return a+b;
}
float sub(float a,float b)
{
    return a-b;
}
float mul(float a,float b)
{
    return a*b;
}
float div(float a,float b)
{
    return a/b;
}
