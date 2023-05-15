#include <stdio.h>  
void swap(int *a, int *b); 

int main()  
{  
    int arr[2]= {10, 20};
    //for(int i=0; i<2; i++
    //for(int i=0; i
    printf("Before swapping the values a = %d, b = %d\n",arr[0],arr[1]); 
    swap(&arr[0],&arr[1]);  
    printf("After swapping values a = %d, b = %d\n",arr[0],arr[1]); 
    
}  
void swap (int *a, int *b)  
{  
    int temp;   
    temp = *a;  
    *a=*b;  
    *b=temp;  
    //printf("After swapping values a = %d, b = %d\n",a,b); 
}  
