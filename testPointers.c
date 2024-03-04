#include<stdio.h>

//void func(int *);
//void swap(int *,int *);

/*
int a = 5,b = 10;
void main()
{
    int x = 20, *ptr = &x;
    printf("Address of x = %u\n",&x);
    printf("value at content of ptr = %d\n",*ptr);
    printf("address of ptr = %u\n",ptr);
    func(ptr);
    printf("address of ptr = %u\n",ptr);
}
void func(int *a)
{
   // printf("*a = %d\n",*a);
    printf("a = %u\n",a);
    printf("Address of b = %u\n",&b);
    a = &b;
}

int main()
{
    int i,j;
    int arr[10] = {3,2,4,1,5,9,8,10,7,6};

    for(i=0;i<10;i++)
        for(j=0;j<10-i-1;j++)
            if(*(arr+j)>*(arr+j+1))
                swap(&arr[j],&arr[j+1]); //same as swap(arr+j,arr+j+1);
    for(i=0;i<10;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
void swap(int *pre,int *post)
{
    int temp;
    temp = *pre, *pre = *post, *post = temp;
}
*/
void main()
{
    int x = 5;
    int a[] = {1,2,3,4,5};
    fun(x);
    int *ptr = &a;
    int i, *p;
    int arr[3][4] = {{10,11,12,13},{20,21,22,23},{30,31,32,33}};
    p = arr;
    for(i=0;i<12;i++)
        printf("%d ",*(p+i));
    printf("\n");
    printf("content of ptr=%d\tcontent of a=%u\t",ptr,a);
}
void fun(int num)
{
    printf("Fun called\n");
}
