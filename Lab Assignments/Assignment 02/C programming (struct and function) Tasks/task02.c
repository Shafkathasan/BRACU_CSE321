//Mohammad Shafkat Hasan
//ID: 19101077
//C programming (struct and function)
//Task02

#include <stdio.h>

/*Question:
Write a C program to print perfect numbers between given intervals using a function. A perfect 
number is a positive integer equal to the sum of its positive divisors, excluding the number itself.
*/

// Function of perfect numbers
int is_perfect(int n) {
    int i, sum = 0;
    
    // Find divisors and add them up
    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    
    // Check if sum of divisors equals the number itself
    if (sum == n) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int start, end, i;
    
    // Take input for range
    printf("Enter start of range: ");
    scanf("%d", &start);
    printf("Enter end of range: ");
    scanf("%d", &end);
    
    // Print perfect numbers in range
    printf("Perfect numbers in range %d to %d:\n", start, end);
    for (i = start; i <= end; i++) {
        if (is_perfect(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
