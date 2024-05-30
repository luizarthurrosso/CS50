#include <cs50.h>
#include <stdio.h>

int size(long n)
{
    int c = 0;

    while (n != 0)
    {
        n /= 10;
        c++;
    }
    return c;
}

int checkcard(long n)
{
    long sumx2 = n / 10;
    int totsumx2 = 0;
    long sumn = n;
    int totsumn = 0;
    int total;

    while (sumx2 > 0)
    {
        if ((sumx2 % 10) * 2 >= 10)
        {
            totsumx2 += (((sumx2 % 10) * 2) / 10) + (((sumx2 % 10) * 2) % 10);
        }
        else
        {
            totsumx2 += (sumx2 % 10) * 2;
        }
        sumx2 /= 100;
    }
    while (sumn > 0)
    {
        totsumn += (sumn % 10);
        sumn /= 100;
    }
    total = totsumn + totsumx2;
    return (total % 10);
}

void class(long n)
{
    if (checkcard(n) != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        while (n > 100)
        {
            n /= 10;
        }
        if (n == 34 || n == 37)
        {
            printf("AMEX\n");
            return;
        }
        else if (n > 50 && n < 56)
        {
            printf("MASTERCARD\n");
            return;
        }
        else if (n / 10 == 4)
        {
            printf("VISA\n");
            return;
        }
        else
        {
            printf("INVALID\n");
            return;
        }
    }
}

int main(void)
{
    long nmr = get_long("número do cartão: ");
    if (size(nmr) != 13 && size(nmr) != 15 && size(nmr) != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        class(nmr);
    }
}