#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dynamicMemoryAllocate();
void mallocCalled();
void callocCalled();
void reallocCalled();
void dynamicArrays();
void dynamicArrays1();
void dynamicArrays2();

int main()
{
    printf("dynamicMemoryAllocate---------------------------------\n");
    dynamicMemoryAllocate();
    printf("dynamicArrays-----------------------------------------\n");
    dynamicArrays();
    dynamicArrays1();
    dynamicArrays2();

    return 0;
}
void dynamicMemoryAllocate()
{
    mallocCalled(); //allocated memory contains garbage without initialisation
    callocCalled(); //allocated memory initialised with 0
    reallocCalled();
}
void mallocCalled()
{
    int *employeeID, size, i;
    printf("Enter the number of employees:\t");
    scanf("%d",&size);
    employeeID = (int *)malloc(size*sizeof(int));
    if(employeeID == NULL)
    {
        printf("Memory not available");
        exit(1);
    }
    printf("Enter the employee IDs serially: \n");
    for(i=0;i<size;i++)
        scanf("%d",employeeID+i);
    printf("Dynamically allocated space is filled with: \n");
    for(i=0;i<size;i++)
        printf("%d\t",*(employeeID+i));
    printf("\n");
    free(employeeID);
}
void callocCalled()
{
    char *name;
    int size, i;
    printf("Enter the size of name char:\t");
    scanf("%d",&size);
    name = (char *)calloc(size,sizeof(char));
    if(name == NULL)
    {
        printf("Memory not available");
        exit(1);    //exiting program with error is shown by 1
    }
    strcpy(name,"Harsh");      //char array cannot be entered like int,float,etc
    printf("Dynamically allocated memory for name is shown:\n");
    for(i=0;i<size;i++)
        printf("%c\t",*(name+i));
    printf("\n");
    free(name);
}
void reallocCalled()
{
    float *fptr;
    char ch;
    int size, i, newSize;
    printf("Enter the size: ");
    scanf("%d",&size);
    fptr = (float *)calloc(size,sizeof(float));
    if(fptr == NULL)
    {
        printf("Memory not available\n");
        exit(1);
    }
    printf("Enter the floating elements:\n");
    for(i=0;i<size;i++)
        scanf("%f",fptr+i);
    printf("Dynamically allocated memory for float:\n");
    for(i=0;i<size;i++)
        printf("%.2f\t",*(fptr+i));
    printf("\nDo you want to increase memory allocated?(y/n) ");
    scanf(" %c",&ch);
    if(ch == 'y')
    {
        printf("Enter the new size: ");
        scanf("%d",&newSize);
        fptr = (float *)realloc(fptr,newSize*sizeof(float));
        if(fptr == NULL)
        {
            printf("Memory not available\n");
            exit(1);
        }
        if((newSize-size)>0)
        {
            printf("Enter the new floating elements:\n");
            for(i=(size);i<newSize;i++)
                scanf("%f",fptr+i);
            printf("Dynamically allocated memory for float:\n");
            for(i=0;i<newSize;i++)
                printf("%.2f\t",*(fptr+i));
            printf("\n");
            free(fptr);
        }
        else
        {
            printf("Dynamically allocated memory for float:\n");
            for(i=0;i<newSize;i++)
                printf("%.2f\t",*(fptr+i));
            printf("\n");
            free(fptr);
        }

    }
    else if(ch == 'n')
    {
        printf("OK\n");
        free(fptr);
    }
    else
        exit(0);
}
/*Dynamic Array using pointer to a 1-D array*/
void dynamicArrays()
{
    int (*arr)[4];
    int row,i,j;
    printf("Enter the number of rows: ");
    scanf("%d",&row);
    arr = (int (*)[4])calloc(row*4,sizeof(int));
    if(arr == NULL)
    {
        printf("Memory not available\n");
        exit(1);
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Dynamic matrix is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
}
/*Dynamic Array using array of pointers*/
void dynamicArrays1()
{
    int *ap[4];
    int cols,i,j;
    printf("Enter the number of cols for each 1-D array: ");
    scanf("%d",&cols);
    for(i=0;i<4;i++)
        ap[i] = (int *)malloc(cols*sizeof(int));
    for(i=0;i<4;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("ar[%d][%d]: ",i,j);
            scanf("%d",&ap[i][j]);
        }
    }
    printf("Dynamic matrix is: \n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d\t",ap[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<4;i++)
        free(ap[i]);
}
/* Dynamic Array memory allocation using pointer of pointers */
void dynamicArrays2()
{
    int **a;
    int row, col, i, j;
    printf("Enter the rows and cols respectively: \n");
    scanf("%d%d",&row,&col);
    a = (int **)malloc(row*sizeof(int *));
    for(i=0;i<col;i++)
        a[i]=(int *)malloc(col*sizeof(int));
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++)
        free(a[i]);
    free(a);
}
