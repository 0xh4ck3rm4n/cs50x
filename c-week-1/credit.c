/**
 * Author: Gaurav Poudel
 */
#include <cs50.h>
#include <stdio.h>

int get_luhn_sum(long temp);
long get_card_number(void);

int main(void)
{
    // Random Card : 774487528265367
    long card_number = get_card_number();
    long temp_for_length = card_number;
    long temp_for_two = card_number;
    int length = 0;
    int first_two, first_one;

    while (temp_for_length != 0)
    {
        temp_for_length = temp_for_length / 10;
        length++;
    }

    while (temp_for_two >= 100)
    {
        temp_for_two = temp_for_two / 10;
    }
    first_two = temp_for_two;
    first_one = first_two / 10;

    if (get_luhn_sum(card_number) % 10 == 0)
    {
        if (length == 15 && (first_two == 34 || first_two == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && first_two >= 51 && first_two <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && first_one == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    /*

    AMEX → length == 15 and first_two == 34 || first_two == 37

    MASTERCARD → length == 16 and first_two in 51..55

    VISA → length == 13 || length == 16 and first_one == 4


    */
}

long get_card_number(void)
{
    long card_number;

    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);
    return card_number;
}

int get_luhn_sum(long temp)
{
    int sum_of_leftover = 0;
    int sum_of_double_digit = 0;
    int card_sum = 0;
    int counter = 0;
    int second_to_last_digit, left_over_digits;

    while (temp != 0)
    {
        counter++;
        // doubling every other second-to-last digits
        if (counter % 2 == 0)
        {
            second_to_last_digit = temp % 10;
            int doubled = second_to_last_digit * 2;
            // in case of double digits when multiplied
            if (doubled >= 10)
            {
                sum_of_double_digit += (doubled / 10) + (doubled % 10);
            }
            // in case of single digit
            else
            {
                sum_of_double_digit += doubled;
            }
        }
        // all of the left over digits
        else
        {
            left_over_digits = temp % 10;
            sum_of_leftover = sum_of_leftover + left_over_digits;
        }
        temp = temp / 10;
    }

    card_sum = sum_of_double_digit + sum_of_leftover;
    return card_sum;
}
