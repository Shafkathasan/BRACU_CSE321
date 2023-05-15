#include <stdio.h>  
int main()  
{  
    char first_string[50]; // declaration of char array variable  
    char second_string[50]; // declaration of char array variable  
    int i;  // integer variable declaration
    
    // Input 
    printf("Enter the first string\n");  
    scanf("%s",first_string);  
    printf("Enter the second string\n");  
    scanf("%s",second_string);
    
    // run loop till 1st string's null value  
    for(i=0;first_string[i]!='\0';i++);   
      
    // Stings concatenation
    for(int j=0;second_string[j]!='\0';j++)  
    {  
        
        first_string[i]=second_string[j];  
        i++;  
    }  
    //first_string[i]='\0';  add null
    
    printf("\nAfter concatenation, the string would look like: %s\n", first_string);  
	return 0; 
	
} 
