#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

const int N = 26;

/*
 * Author: Gaurav Poudel
 */

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        return 1;
    }

    string plaintext = get_string("Plaintext: ");
    int len = strlen(plaintext);
    char ciphertext[len];

    for (int i = 0; i < len; i++)
    {
        //  non-alphabetical characters should be outputted unchanged.

        // Your program must preserve case: capitalized letters must remain capitalized letters;
        // lowercase letters must remain lowercase letters
        if (isalpha(plaintext[i]))
        {
            bool is_upper = isupper(plaintext[i]);
            int index = toupper(plaintext[i]) - 'A';
            char encrypted = argv[1][index];
            if (is_upper)
            {
                ciphertext[i] = toupper(encrypted);
            }
            else
            {
                ciphertext[i] = tolower(encrypted);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';

    printf("ciphertext: %s\n", ciphertext);
}

bool is_valid_key(string key)
{
    /*
        If the key is invalid (as by not containing 26 characters, containing any character that is
       not an alphabetic character, or not containing each letter exactly once), your program should
       print an error message of your choice (with printf) and return from main a value of 1
       immediately.
    */
    if (strlen(key) != N)
    {
        printf("Error: Please enter atleast 26 character.\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Error: Must be alphabets.\n");
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Error: Each alphabet must be unique.\n");
                return false;
            }
        }
    }
    return true;
}
