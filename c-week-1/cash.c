/**
 * Author: Gaurav Poudel
 */
#include <cs50.h>
#include <stdio.h>
int get_positive_change(void);

int main(void)
{
    // ask for change owed
    int change = get_positive_change();

    int quaters = change / 25;
    int quater_remainder = change % 25;

    int dimes = quater_remainder / 10;
    int dime_remainder = quater_remainder % 10;

    int nickle = dime_remainder / 5;
    int nickle_remainder = dime_remainder % 5;

    int pennies = nickle_remainder;

    int sum = quaters + dimes + nickle + pennies;
    printf("%i\n", sum);
}

int get_positive_change(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    return change;
}
