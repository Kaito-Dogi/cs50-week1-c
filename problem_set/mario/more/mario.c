#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask the user for the height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // print each step
    // i means the step number
    for (int i = 0; i < height; i++)
    {
        // print each block# of the left part
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

        // print blanks which separate left and right parts
        printf("  ");

        // print each block# of the right part
        // j means the block number counting from the left
        for (int j = 0; j < height; j++)
        {
            if (j <= i)
            {
                printf("#");
            }
            else if (j > i)
            {
                break;
            }
        }

        printf("\n");
    }
}
