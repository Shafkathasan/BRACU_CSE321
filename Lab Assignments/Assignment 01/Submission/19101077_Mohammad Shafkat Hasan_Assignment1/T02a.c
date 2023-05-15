//Mohammad Shafkat Hasan
//ID: 19101077
//Task02(a)

#include <stdio.h>

// Addition(+)
float add(float x, float y)
{
	return x + y;
}

// Subtraction (-)
float sub(float x, float y)
{
    return x - y;
}

// Multiplication (*)
float mul(float x, float y)
{
    return x * y;
}

// Main Function
int main()
{
	float a, b;
	
	//Inputs
	printf("Input first number: ");
	scanf("%f", &a);
	printf("Input second number: ");
	scanf("%f", &b);
	
	if (a > b)
    {
        printf("Subtraction: %.3f\n", sub(a, b));
    }
    else if (a < b)
    {
        printf("Addition: %.3f\n", add(a, b));
    }
    else if (a == b)
    {
        printf("Multiplication: %.3f\n", mul(a, b));
    }
    
    return 0;

}
