//Mohammad Shafkat Hasan
//ID: 19101077
//Task02(b)

#include <stdio.h>
#include <string.h>

// Function to Remove Extra Spaces
void rmv_ex_spaces(char *str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' '))
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

// Main Function
int main()
{
    char str[10000];
    printf("Enter a sentence with extra spaces:\n");
    scanf("%[^\n]s", str);
    
    getchar();
    rmv_ex_spaces(str);
    
    printf("The sentence without extra spaces:\n%s\n", str);
    return 0;
}
