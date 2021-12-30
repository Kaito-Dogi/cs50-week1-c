#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // credit card number
    long credit_num;

    // value of each digit
    int digit_num = 0;

    // sum of the number of digits
    int digit_sum = 0;

    // ask the user for the credit number
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num < 0);

    // calculate check_sum
    for (long tmp_num = credit_num; tmp_num > 0; digit_num++, tmp_num = (tmp_num - tmp_num % 10) / 10)
    {
        if ((digit_num + 1) % 2 == 0)
        {
            for (int doubled_num = tmp_num % 10 * 2; doubled_num > 0; doubled_num = (doubled_num - doubled_num % 10) / 10)
            {
                digit_sum += doubled_num % 10;
            }
        }
        else
        {
            digit_sum += tmp_num % 10;
        }
    }

    // check if the check_sum is equal to 20
    if (digit_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // calculate the top two digits
    credit_num = (credit_num - credit_num % (long) pow(10, digit_num - 2)) / pow(10, digit_num - 2);

    // check the credit card company
    if ((credit_num == 34 || credit_num == 37) && digit_num == 15)
    {
        printf("AMEX\n");
    }
    else if ((credit_num == 51 || credit_num == 52 || credit_num == 53 || credit_num == 54 || credit_num == 55) && digit_num == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        // calculate the top digit
        credit_num = (credit_num - credit_num % 10) / 10;

        // check the credit card company
        if (credit_num == 4 && (digit_num == 13 || digit_num == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
}
