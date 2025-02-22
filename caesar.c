#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char rotate(char input, int key);   //Function for rotating all letters
bool only_digits(string key);   //Function to check that arguments are all numeric

int main(int argc, string argv[])
{
    //Tell user to provide a key if they didn't give one
    if(argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: %s, key\n", argv[0]);
        return 1;
    }
    //Convert key into an int

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");

    //Rotate each letter in the text
    for(int i = 0, n = strlen(plaintext); i < n; i++)
    {
        plaintext[i] = rotate(plaintext[i], key);
    }
    printf("ciphertext: %s\n", plaintext);

    return 0;
}

bool only_digits(string key)
{
    bool statement = true;
    for(int i = 0, n = strlen(key); i < n; i++)
    {
        if(isdigit(key[i]) == 0 || key[i] < 0)
        {
            statement = false;
            break;
        }
    }
    return statement;
}

char rotate(char input, int key)
{
    if(isupper(input) != 0)
    {
        input = ((input - 'A') + key) % 26 + 'A';
    }
    else if(islower(input) != 0)
    {
        input = ((input - 'a') + key) % 26 + 'a';
    }
    return input;
}
