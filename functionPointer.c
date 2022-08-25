//function returning pointer
#include<stdio.h>
int *func(int*, int);
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=5;
    int *ptr;
    ptr=func(arr, n);
    printf("Value at address stored in ptr is: %d\n", *ptr);
    return 0;
}

int *func(int *p, int n)
{
    p=p+n;
    return p;
}