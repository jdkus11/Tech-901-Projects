#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int compute_score(string word);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int player1 = compute_score(word1); //Computes P1 score based on word given
    int player2 = compute_score(word2); //Computes P2 score based on word given

    //Compares scores to see who wins
    if(player1 > player2)
    {
        printf("Player 1 wins!\n");
    }
    else if(player1 < player2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    //Starts keeping track of score
    int score = 0;
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        if(isalpha(word[i]) != 0)   //Checks to make sure character is a letter
        {
            int letter = toupper(word[i]);  //Converts each character to an uppercase to have one calculation
            int letter_points = POINTS[letter - 'A'];   //Subtracts the ASCII value for A to correspond with index in POINTS
            score += letter_points; //Adds each point value to the score
        }
    }
    return score;   //Returns the score for use in the function above
}
