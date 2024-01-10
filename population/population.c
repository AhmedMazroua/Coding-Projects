#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startPop;
    do
    {
        startPop = get_int("What's the starting population?; ");
    }
    while (startPop < 9);
    // TODO: Prompt for end size
    int endPop;
    do
    {
        endPop = get_int("\nWhats the ending population?: ");
    }
    while (endPop < startPop);

    // TODO: Calculate number of years until we reach threshold
    int yearNum = 0;

    while (startPop < endPop)
    {
        startPop = startPop + (startPop / 3) - (startPop / 4);

        yearNum++;

    }


    // TODO: Print number of years
    printf("\nYears: %i", yearNum);
}
