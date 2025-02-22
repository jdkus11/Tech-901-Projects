#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int compute_index(int letters, int words, int sentences);


int main(void)
{
    //Prompt the user for some text
    string text = get_string("Text: ");

    //Count number of words, letters, and sentences in text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //Compute the reading level
    int cl_index = compute_index(letters, words, sentences);

    //Print out the reading level
    if(cl_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(cl_index >= 1 && cl_index <= 16)
    {
        printf("Grade %i\n", cl_index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int sum = 0; //Start the count for number of letters
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i]) != 0)   //Checking to make sure that we only count letters
        {
            sum ++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 1;    //Start the count for words, start at one to account for last word not having a space after it
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == 32)
        {
            sum++;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int sum = 0;    //Start count for sentences
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sum++;
        }
    }
    return sum;
}

int compute_index(int letters, int words, int sentences)    //Computes Coleman-Liau Index
{
    double index1 = 0.0588 * (((float)letters / (float)words) * 100) - 0.296 * (((float)sentences / (float)words) * 100) - 15.8;
    int index2 = round(index1);
    return index2;
}
