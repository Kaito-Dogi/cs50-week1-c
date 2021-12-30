#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // ask user for height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // print blocks
    // i means the row number
    for (int i = 0; i < height; i++)
    {
        // j means the block number counting from the left
        for (int j = 0; j < height; j++)
        {
            if (j < height - i - 1)
            {
                printf(" ");
            }
            else if (j >= height - i - 1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}