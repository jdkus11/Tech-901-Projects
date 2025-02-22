#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while(change < 1);

    int quarters = change / 25;
    change = change - (25 * quarters);

    int dimes = change / 10;
    change = change - (10 * dimes);

    int nickels = change / 5;
    change = change - (5* nickels);

    int pennies = change / 1;

    int coins = quarters + dimes + nickels + pennies;
    printf("%i \n", coins);
}
