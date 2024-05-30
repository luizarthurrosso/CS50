#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void strToBi(string msg);

int main(void)
{
    string msg = get_string("message: ");
    strToBi(msg);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void strToBi(string msg)
{
    char c;
    int bits[8];

    for (int n = 0; n < strlen(msg); n++)
    {
        c = msg[n];
        for (int i = 7; i > 0; i --)
        {
            if ((c % 2) == 0)
            {
                bits[i] = 0;
                c /= 2;
            }
            else
            {
                bits[i] = 1;
                c /= 2;
            }
        }
        for (int j = 0; j < 8; j++)
        {
            print_bulb(bits[j]);
        }
        printf("\n");
    }
}