#include <stdio.h>

// Function to check if a number is even or odd
void check_even_odd(int number) {
    if (number % 2 == 0) {
        printf("%d is an Even number.\n", number);
    } else {
        printf("%d is an Odd number.\n", number);
    }
}

int main() {
    int num;
    
    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);
    
    check_even_odd(num);  // Call the function to check even or odd
    
    return 0;
}

