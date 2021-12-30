#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare variables and initialize them
    int start_size = 0;
    int end_size = 0;
    int current_size = 0;
    int year_count = 0;

    // ask the start size of Llamas from user
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // ask the end size of Llamas from user
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // initialize the current size of Llamas
    current_size = start_size;

    // calculate year count
    while (current_size < end_size) 
    {
        current_size = current_size + current_size / 3 - current_size / 4;
        year_count++;
    }

    // show result
    printf("Years: %i\n", year_count);
}
