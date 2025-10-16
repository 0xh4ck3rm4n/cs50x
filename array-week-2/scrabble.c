#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int get_score(string text);

/**
 * Author: Gaurav Poudel
 */

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = get_score(player1);
    int score2 = get_score(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string text)
{

    int total = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (toupper(text[i]) >= 'A' && toupper(text[i]) <= 'Z')
        {
            int num = toupper(text[i]) - 64;
            total += POINTS[num - 1];
        }
        else
        {
            total += 0;
        }
    }

    return total;
}
