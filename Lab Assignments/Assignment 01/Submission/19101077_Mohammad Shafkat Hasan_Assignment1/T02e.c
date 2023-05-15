//Mohammad Shafkat Hasan
//ID: 19101077
//Task02(e)


#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len;
    int flag = 1; // assume string is a palindrome initially
	
	//Input
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
	
	// Check Palindrome
	
    char *ptr1 = str; // pointer to the first character of the string
    char *ptr2 = str + len - 1; // pointer to the last character of the string

    for (i = 0; i < len / 2; i++) {
        if (*ptr1 != *ptr2) { // if characters don't match, string is not a palindrome
            flag = 0;
            break;
        }
        ptr1++; // move pointer to the next character
        ptr2--; // move pointer to the previous character
    }
	
	// Output
    if (flag) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}



