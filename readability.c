#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{   
    //get text as input
    string text = get_string("Text: ");
   
    //counting letter, word, and sentence
    float letter = 0;
    float word = 1;
    float sentence = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (((int) text[i] > 64 && (int) text[i] < 91) || ((int) text[i] > 96 && (int) text[i] < 123))
        {
            letter = letter + 1;
        }
       
        if ((int) text[i] == 32 && (int) text[i + 1] != 32)
        {
            word = word + 1;
        }
       
        if ((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63)
        {
            sentence = sentence + 1;
        }
    }
    
    //run Coleman-Liau index
    float l = letter / word * 100;
    float s = sentence / word * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    
    //output index result
    if (index >= 16)
    {
        printf("Grade 16+");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i", index);
    }
    else
    {
        printf("Before Grade 1");
    }
    
    printf("\n");
}
