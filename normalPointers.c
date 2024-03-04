#include<stdio.h>

int x, y = 5, z = 2;
int age = 28;
float salary = 9000.0;

void assignAddtoPointers();
void deref();
void arithmeticPointer();
void pointerToPointer();
void pointerToOneDArray();
void pointerToWholeArray();
void pointerTo2DArray();
char *functionReturningPointer();
void passing1DArraytoFunc(char []);
void passing2DArraytoFunc(int (*)[3]);
void arrayOfPointers();
void accessingArrayViaArrayPointer();
void voidPointers();

int main()
{
    char array[5] = {'h','a','r','s','h'};
    int n;
    char *pointer = NULL;
    printf("Value of age = %d, address of age = %u\n",age,&age);
    printf("Value of sal = %.2f, address of sal = %u\n",salary,&salary);

    x = z+++(++y);
    printf("x = %d %d+%d\n",x,z,y);

    printf("\nassignAddtoPointers-----------------------------------------------\n");
    assignAddtoPointers();
    printf("\nderef-------------------------------------------------------------\n");
    deref();
    printf("\narithmeticPointer-------------------------------------------------\n");
    arithmeticPointer();
    printf("\npointerToPointer--------------------------------------------------\n");
    pointerToPointer();
    printf("\npointerToOneDArray------------------------------------------------\n");
    pointerToOneDArray();
    printf("\npointerToWholeArray-----------------------------------------------\n");
    pointerToWholeArray();
    printf("\npointerTo2DArray--------------------------------------------------\n");
    pointerTo2DArray();
    printf("\nfunctionReturningPointer------------------------------------------\n");
    printf("Enter the character no. to display: ");
    scanf("%d",&n);
    pointer = functionReturningPointer(array,n);
    printf("Fetched char: %c\n",*pointer);
    printf("\npassing1DArraytoFunc----------------------------------------------\n");
    passing1DArraytoFunc(array);
    printf("Size of the char array[5] in main = %d\n",sizeof(array));
    printf("\narrayOfPointers---------------------------------------------------\n");
    arrayOfPointers();
    printf("\naccessingArrayViaArrayPointer-------------------------------------\n");
    accessingArrayViaArrayPointer();
    printf("\nvoidPointer-------------------------------------------------------\n");
    voidPointers();

    return 0;
}
void assignAddtoPointers()
{
    int roll = 18, *iptr = &roll, *fptr;
    fptr = &age;    //Assigning same variable address to different pointer variables
    printf("Value of roll = %d, size of pointer = %d\n",roll,sizeof(iptr));
    printf("Address of iptr = %u\n",iptr);
    printf("Address of fptr = %u\n",fptr);
}
void deref()
{
    char a = 'x', *p1;
    int b = 1, *p2;
    float c = 0.1, *p3;
    double d = 18.3, *p4;
    printf("Size of p1 = %d, Size of (*p1) = %d\n",sizeof(p1),sizeof(*p1));
    printf("Size of p2 = %d, Size of (*p2) = %d\n",sizeof(p2),sizeof(*p2));
    printf("Size of p3 = %d, Size of (*p3) = %d\n",sizeof(p3),sizeof(*p3));
    printf("Size of p4 = %d, Size of (*p4) = %d\n",sizeof(p4),sizeof(*p4));
}
void arithmeticPointer()
{
    char ch = 'x', *p = &ch;
    int a = 5, *p1 = &a;
    double b = 2.2, *p2 = &b;
    printf("Address of ch %c = %u, Incremented Address = %u\n",*p,p,(p+3));
    printf("Address of a %d = %u, Incremented Address = %u\n",*p1,p1,(p1+1));
    printf("Address of b = %u, Incremented Address = %u\n",p2,(p2+1));
    printf("Adding 5 to a = %d\n",*p1+5);
}
void pointerToPointer()
{
    char ch = 'z';
    char *pa = &ch;
    char **ppa = &pa;
    printf("ch = %c\npa = %u\nppa = %u\n",ch,pa,ppa);
    printf("Value at pa=%c\nValue at ppa=%c",*pa,**ppa);
}
void pointerToOneDArray()
{
    int arr[5];
    int index, *pa;
    pa = arr;

    printf("Enter the 5 elements in the array  : \n");
    for(index = 0;index < 5;index++)
        scanf("%d",pa+index);
    printf("Value of array with address is : \n");
    for(index = 0;index < 5;index++)
    {
        printf("arr[%d]=%d, Address=%u\n",index,arr[index],(arr+index));
    }
}
void pointerToWholeArray()
{
    int *p, (*ptr)[5];
    int arr[5] = {1,2,3,4,5};
    p = arr;
    ptr = arr;
    printf("p = %u , ptr = %u\n",p,ptr);
    p++;
    ptr++;
    printf("After incrementing both pointers once\n");
    printf("p = %u , ptr = %u\n",p,ptr);
    printf("Value at p = %d,%d\n",*p,*arr);
    printf("size of (*p) = %d, size of (*ptr) = %d\n",sizeof(*p),sizeof(*ptr));
    printf("size of p = %d, size of ptr = %d\n",sizeof(p),sizeof(ptr));
}
void pointerTo2DArray()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row,col;
    for(row=0;row<3;row++)
    {
        printf("Address of %dth 1-D array = %u\n",row,(arr+row));
        for(col=0;col<3;col++)
        {
            printf(" %d ",*(*(arr+row)+col));
        }
        printf("\n");
    }
    passing2DArraytoFunc(arr);
}
char *functionReturningPointer(char *p,int n)
{
    p = p+n;
    return p;
}
void passing1DArraytoFunc(char a[])
{
    char ar[5] = {'s','o','f','i','a'};
    char *ptr;
    ptr = ar;
    printf("size of ptr inside local loop = %d\n",sizeof(ptr));
    printf("size of array defined in the local scope of func = %d\n",sizeof(ar));
    printf("size of array received = %d\n",sizeof(a));
}
void passing2DArraytoFunc(int a[][3])
{
    printf("passing2DArraytoFunc----------\n");
    printf("size of passed array sizeof(a) = %d\tsizeof(*a) = %d\n",sizeof(a),sizeof(*a));
}
void arrayOfPointers()
{
    int *ap[5];
    int a = 11,b = 22,c = 33,d = 44,e = 55,index;
    ap[0] = &a;
    ap[1] = &b;
    ap[2] = &c;
    ap[3] = &d;
    ap[4] = &e;
    for(index = 0;index < 5;index++)
    {
        printf("sizeof(ap) = %d\tsizeof(*ap) = %d\t| ap[%d] = %u\t| *ap[%d] = %d\n",sizeof(ap[index]),sizeof(*ap[index]),index,ap[index],index,*ap[index]);
    }
}
void accessingArrayViaArrayPointer()
{
    int row, col;
/*  int i,j,element;
    printf("Enter rows: ");
    scanf("%d",&row);
    printf("Enter cols: ");
    scanf("%d",&col);

    int arr[row][col];  //Only modern compilers like gcc allow to declare variable anywhere in program, its scope is from the point of declaration to the ending curly brace.

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&element);
            arr[i][j] = element;
        }
    }
 */ int arr[3][4], *parr[3];
    printf("Enter the array elements: \n");
    for(row = 0; row<3; row++)
        for(col = 0; col<4; col++)
            scanf("%d",&arr[row][col]);
    for(row=0;row<3;row++)
        parr[row] = arr[row];
    printf("Entered array is : \n");
    for(row=0;row<3;row++)
    {
        for(col=0;col<4;col++)
            printf("%d\t",parr[row][col]);
        printf("\n");
    }

}
void voidPointers()
{
    int index;
    int arr[4] = {11,22,33,44};
    void *vp;
    vp = arr;
    printf("Array printed using void pointer: \n");
    for(index=0;index<4;index++)
    {
        printf("%d\t",*((int *)vp+index));
    }
}
