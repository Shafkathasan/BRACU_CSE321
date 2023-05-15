#include <stdio.h>

// Create the student structure
struct Student {
    char name[50];
    int id;
    float marks;
};

int main() {
    int i, n;
    
    printf("Total students: ");
    scanf("%d",&n);
    // Create the student's structure variable
    // with n Student's records
    struct Student s[n];
    
    printf("\nEnter information of students:");

    // storing information
    for (i = 0; i < n; ++i) {
        s[i].id = i + 1;
        printf("\nFor id number%d,\n", s[i].id);
        printf("Enter first name: ");
        scanf("%s", s[i].name);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\n\nDisplaying Information");

    // displaying information
    for (i = 0; i < n; ++i) {
        printf("\nFor id number: %d\n", i + 1);
        printf("First name: ");
        puts(s[i].name);
        printf("Marks: %.1f", s[i].marks);
        printf("\n");
    }
    return 0;
}
