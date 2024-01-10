#include  <stdio.h>
#include <cs50.h>

int main(void)
{
    //creates name variable.
    string name;

    //asks for users name.
    name = get_string("Let's get acquainted, Whats your name?: ");

    //greets user by name.
    printf("\nHello, %s.\n\n It's a pleasure to meet you!", name);
}