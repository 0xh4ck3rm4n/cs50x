/**
 * Author: Gaurav Poudel
 */
#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    int height = get_height();

    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        for(int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height <= 0);
    return height;
}
