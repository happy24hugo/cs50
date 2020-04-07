#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//program is accepting command-line argument
int main(int argc, string argv[])
{
    //Counting Command-Line Arguments: if program is accepting no more than one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }
    
    //Accessing and validating the Key: check if program is accepting only integer as the key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit((char)argv[1][i]))
        {
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1; 
        }
    }
    
    //Converting and saving command-line arguments into an integer as the key
    int k = atoi(argv [1]);
    
    //Making sure command-line argument is non-negative integer
    if (k >= 0)
    {
        //Getting plaintext as input
        string p = get_string("plaintext: ");
        
        //Printing ciphertext as output
        printf("ciphertext: ");
        for (int i = 0; i < strlen(p); i++)
        {
            //Considering three conditions: uppercase letter, lowercase letter, and otherwise
            if ((int) p[i] > 64 && (int) p[i] < 91)
            {
                printf("%c", ((int) p[i] - 65 + k) % 26 + 65);
            }
            else if ((int) p[i] > 96 && (int) p[i] < 123)
            {
                printf("%c", ((int) p[i] - 97 + k) % 26 + 97);
            }
            else
            {
                printf("%c", p[i]);
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("\n");
}
