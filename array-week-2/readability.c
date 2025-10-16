#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_total_letters(string words);
int get_total_words(string text);
int get_total_sentences(string text);

/*
 * Author: Gaurav Poudel
 */
int main(void)
{
    /*
        The Problem : Approx reading level based on text.

        Formula : index = 0.0588 * L - 0.296 * S - 15.8
        [ where, L = average number of letter per 100 words
         and S = average number of sentences per 100 words ]

         Print - Grade 'X', where X is a grade level

         If Grade is 16 or more, print "Grade 16+"

         If Grade is less than 1, print "Before Grade 1"
    */

    string text = get_string("Text: ");

    // Get total number of letters, words, and sentences
    int total_letters = get_total_letters(text);
    int total_words = get_total_words(text);
    int total_sentences = get_total_sentences(text);

    // Use the formulae
    float L = ((float) total_letters / total_words) * 100;
    float S = ((float) total_sentences / total_words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // print out the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int get_total_letters(string words)
{
    int total_letters = 0;
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        if (isalpha(words[i]))
        {
            total_letters++;
        }
    }
    return total_letters;
}

int get_total_words(string text)
{
    int total_words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // space is denoted by 32 in ASCII sheet.
        if (text[i] == 32)
        {
            total_words++;
        }
    }
    return total_words;
}

int get_total_sentences(string text)
{

    int total_sentence = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            total_sentence++;
        }
    }
    return total_sentence;
}
