//Mohammad Shafkat Hasan
//ID: 19101077
//C programming (struct and function)
//Task01

#include <stdio.h>

/*
Question:
Suppose you and your friends go to have breakfast in a restaurant. Each of you order Paratha,
Vegetable and Mineral Water. Treat each of the ordered items as structures and each of the
structures will have two properties which are: quantity and unit price. Each property of the
structure will be taken as input from the user. After taking all the inputs calculate what is the
total bill and also, take input from the user how many people are there in total. Lastly calculate
how much each of the person will have to pay and print it (Note: This value will be float).
*/

// Structure of items
struct item {
    int quantity;
    float unit_price;
};

int main() {
    struct item paratha, vegetable, water;
    int num_people;
    float total_bill, bill_per_person;
    
    // Take input for Paratha
    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);
    
    // Take input for Vegetable
    printf("Quantity Of Vegetables: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit Price: ");
    scanf("%f", &vegetable.unit_price);
    
    // Take input for Mineral Water
    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water.quantity);
    printf("Unit Price: ");
    scanf("%f", &water.unit_price);
    
    // Calculate total bill
    total_bill = (paratha.quantity * paratha.unit_price) + (vegetable.quantity * vegetable.unit_price) + (water.quantity * water.unit_price);
    
    // Take input for number of people
    printf("Number of People: ");
    scanf("%d", &num_people);
    
    // Calculate bill per person
    bill_per_person = total_bill / num_people;
    
    // Print result
    printf("Individual people will pay: %.2f tk\n", bill_per_person);
    
    return 0;
}

