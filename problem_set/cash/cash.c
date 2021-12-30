#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // declare variables
    float dollars;
    int cents;
    int coin_num = 0;

    // ask the user how many dollars he/she wants
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // convert dollars to cents
    cents = round(dollars * 100);

    // count the number of quarters
    int quarter_num = cents / 25;
    coin_num += quarter_num;
    cents -= quarter_num * 25;

    // count the number of dimes
    int dime_num = cents / 10;
    coin_num += dime_num;
    cents -= dime_num * 10;

    // count the number of nickels
    int nickel_num = cents / 5;
    coin_num += nickel_num;
    cents -= nickel_num * 5;

    // count the number of pennies
    int penny_num = cents / 1;
    coin_num += penny_num;
    cents -= penny_num * 1;

    // show the result
    printf("%i\n", coin_num);
}
