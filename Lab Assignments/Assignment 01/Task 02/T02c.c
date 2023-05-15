//Mohammad Shafkat Hasan
//ID: 19101077
//Task02(c)

#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int length, i, has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;
    printf("Enter your new password: ");
    scanf("%s", password);
    length = strlen(password);
    
    // Password Check
    for (i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lower = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            has_upper = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else if (password[i] == '_' || password[i] == ',' || password[i] == '$' || password[i] == '#' || password[i] == '@') {
            has_special = 1;
        }
    }
    if (!has_lower) {
        printf("Lowercase character missing\n");
    }
    if (!has_upper) {
        printf("Uppercase character missing\n");
    }
    if (has_digit==0) {
        printf("Digit missing\n");
    }
    if (has_special==0) {
        printf("Special character missing\n");
    }
    if (has_lower && has_upper && has_digit && has_special) {
        printf("OK\n");
    }
    return 0;
}


