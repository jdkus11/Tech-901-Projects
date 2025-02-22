#include <cs50.h>
#include <stdio.h>

/*
Purpose of code:
1. Prompt user for number of bricks
2. Prompt user again if number is less than 1
3. Print out a pyramid of bricks
*/

void print_brick(int spaces, int bricks);
int get_height();

int main(void)
{
   int height = get_height();

    for(int i = 1; i <= height; i++)    //Starts at 1 so the spaces are correct, <= height so that it goes up to 4
    {
        print_brick(height - i, i);
    }

}

void print_brick(int spaces, int bricks)
{
    for(int i = 0; i < spaces; i++)     //print the spaces first
    {
        printf(" ");
    }

    for(int i = 0; i < bricks; i++)     //print the bricks second
    {
        printf("#");
    }
    printf("  ");

    for(int i = 0; i < bricks; i++)     //print the bricks again without spaces
    {
        printf("#");
    }

    printf("\n");       //print the new line so we can go to the next row
}

int get_height()
{
    int height;
    do
    {
        height = get_int("Height: ");   //This prompts the user for height of the pyramid
    }
    while(height < 1 || height > 8);  //This ensures that they must give a number that is at least 1
    return height;
}
