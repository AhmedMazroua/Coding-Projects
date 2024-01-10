#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
//established text input function
    string text = get_string("Text: ");

//established variables
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float L;
    float S;

    int index;

//for loop
    for (int i = 0; i < strlen(text); i++)
    {
        // gets letter
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }

        // gets word
        if (text[i] == ' ')
        {
            words++;
        }

        //gets sentence

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }


//gets averages
    L = (float)letters / (float)words * 100;
    S = (float)sentences / (float)words * 100;

//formula input
    index = round(0.0588 * L - 0.296 * S - 15.8);


// conditional for printfs
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}
