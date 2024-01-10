#include <cs50.h>
#include <stdio.h>

int main(void)
{
//initializes prompt for height//
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //prints out grid variables
    //creates row
    for (int i = 0; i < height; i++)
    {
        //creates the collumn
        for (int j = 0; j < height; j++)
        {   // forumla for print conditional
            if (i + j < height - 1)
            {
                //prints spaces on grid
                printf(" ");
            }

            else
            {

                printf("#");

            }
        }
        //creates new line
        printf("\n");
    }
}