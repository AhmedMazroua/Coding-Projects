#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{


    // gets user input
    string text = get_string("message: ");

    //index through each char.
    for (int i = 0; i < strlen(text); i++)
    {
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

        int deci = text[i];

        int j = 0;

        while (deci > 0)
        {
// turns decimal number to binary
            binary[j] = deci % 2;
            deci = deci / 2;
// increases index by 1 while conditional is true
            j++;
        }
// prints bulbs on if 1 off if 0
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);

        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
