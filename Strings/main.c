#include <stdio.h>

// Prototypes
int Length(char *);
char *LowerCase(char *);
char *UpperCase(char *);
char *ToggleCase(char *);

int main(void)
{
    // Initializing a string
    char string[] = "John Smith";

    // Technique to get strings with spaces until the user placed enter
    gets(string);
    printf("New String: %s", string);

    return 0;
}

// Use this function to determine the length of your string
int Length(char *string)
{
    int i;
    for (i = 0; string[i] != '\o'; i++)
        ;
    return i;
}

// Changing a case of your string to lowercase
char *LowerCase(char *string)
{
    for (int i = 0; i < Length(string); i++)
        string[i] = string[i] + 32;
    return string;
}

// Changing a case of your string to uppercase
char *UpperCase(char *string)
{
    for (int i = 0; i < Length(string); i++)
        string[i] = string[i] - 32;

    return string;
}

// Toggling Case of a String
char *ToggleCase(char *string)
{
    for (int i = 0; i < Length(string); i++)
        if (string[i] >= 65 && string[i] <= 90)
            string[i] = string[i] + 32;
        else if (string[i] >= 97 && string[i] <= 122)
            string[i] = string[i] - 32;
    return string;
}

// Finding duplicates in an array using bitwise operations
int Duplicates(char *string)
{
    long int H = 0, x = 0;

    for (int i = 0; string[i] != '\o'; i++)
    {
        x = 1;
        x = x << (string[i] - 97);

        // Masking
        if ((x & H) > 0)
        {
            printf("This string is a duplicate: %c\n", string[i]);
        }
        else
            H = x | H;
        // Merging
    }
}