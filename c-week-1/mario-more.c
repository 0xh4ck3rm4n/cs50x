/**
 * Author: Gaurav Poudel
 */
#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    int n = get_height();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 1; l <= i; l++)
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
    while ((height <= 0) || (height >= 9));

    return height;
}
