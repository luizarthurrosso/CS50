#include <cs50.h>
#include <stdio.h>

int func(int n)
{
    int space = n - 1;
    int block = 1;

    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < space; s++)
        {
            printf(" ");
        }

        for (int b = 0; b < block; b++)
        {
            printf("#");
        }

        printf("  ");

        for (int b = 0; b < block; b++)
        {
            printf("#");
        }

        block++;

        space--;

        printf("\n");
    }

    return n;
}

int main(void)
{
    int h;

    do
    {
        h = get_int("altura: ");
    }
    while (h < 1 || h > 8);

    func(h);
}