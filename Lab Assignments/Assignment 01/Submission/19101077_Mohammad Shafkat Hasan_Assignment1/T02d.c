//Mohammad Shafkat Hasan
//ID: 19101077
//Task02(d)

#include <stdio.h>
#include <string.h>



// Function to Check Email address

int is_updated_email(char* email) {
    // Find the index of '@' character in the email address
    char* at_index = strchr(email, '@');
    if (at_index == NULL) {
        // Invalid email address
        return 0;
    }

    // Check if the domain is already updated
    if (strcmp(at_index + 1, "sheba.xyz") == 0) {
        return 1;
    }

    // Check if the domain needs to be updated
    if (strcmp(at_index + 1, "kaaj.com") == 0) {
        // if Replace the old domain with the new one
        //strcpy(at_index + 1, "sheba.xyz"); //return 1;
        return 0;
    }

    // Invalid domain
    return 0;
}

// Main Function

int main() {
    char email[100];
    printf("Enter an email address: ");
    scanf("%s", email);

    if (is_updated_email(email)) {
        printf("The email address is okay\n");
    } else {
        printf("The email address is outated\n");
    }

    return 0;
}


