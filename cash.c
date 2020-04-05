#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //get a postive float as input for　change owned
    float n;
    do
    {
        n = get_float("Cash Owed: ");
    }
    while (n < 0);
    //round the Cents(float) to Integer
    int cents = round(n * 100);
    //counting coins
    int counts = (cents / 25) + ((cents % 25) / 10) + (((cents % 25) % 10) / 5) + (((cents % 25) % 10) % 5);
    printf("%i\n", counts);
}
