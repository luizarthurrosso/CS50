#include "helpers.h"
#include "math.h"

int rounding(float res)
{
    int r = res;
    if (res - r >= 0.5)
    {
        res++;
    }
    return res;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = rounding((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE src[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            src[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = src[i][width - j - 1];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE src[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            src[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            if (i == 0)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = rounding((src[i][j].rgbtRed + src[i][j + 1].rgbtRed + src[i + 1][j].rgbtRed + src[i + 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = rounding((src[i][j].rgbtGreen + src[i][j + 1].rgbtGreen + src[i + 1][j].rgbtGreen + src[i + 1][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = rounding((src[i][j].rgbtBlue + src[i][j + 1].rgbtBlue + src[i + 1][j].rgbtBlue + src[i + 1][j + 1].rgbtBlue) / 4.0);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = rounding((src[i][j].rgbtRed + src[i][j - 1].rgbtRed + src[i + 1][j].rgbtRed + src[i + 1][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = rounding((src[i][j].rgbtGreen + src[i][j - 1].rgbtGreen + src[i + 1][j].rgbtGreen + src[i + 1][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = rounding((src[i][j].rgbtBlue + src[i][j - 1].rgbtBlue + src[i + 1][j].rgbtBlue + src[i + 1][j - 1].rgbtBlue) / 4.0);
                }
                else
                {
                    image[i][j].rgbtRed = rounding((src[i][j - 1].rgbtRed + src[i][j].rgbtRed + src[i][j + 1].rgbtRed + src[i + 1][j - 1].rgbtRed + src[i + 1][j].rgbtRed + src[i + 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = rounding((src[i][j - 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j + 1].rgbtGreen + src[i + 1][j - 1].rgbtGreen + src[i + 1][j].rgbtGreen + src[i + 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = rounding((src[i][j - 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j + 1].rgbtBlue + src[i + 1][j - 1].rgbtBlue + src[i + 1][j].rgbtBlue + src[i + 1][j + 1].rgbtBlue) / 6.0);
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = rounding((src[i - 1][j].rgbtRed + src[i - 1][j + 1].rgbtRed + src[i][j].rgbtRed + src[i][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = rounding((src[i - 1][j].rgbtGreen + src[i - 1][j + 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = rounding((src[i - 1][j].rgbtBlue + src[i - 1][j + 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j + 1].rgbtBlue) / 4.0);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = rounding((src[i - 1][j].rgbtRed + src[i - 1][j - 1].rgbtRed + src[i][j].rgbtRed + src[i][j - 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = rounding((src[i - 1][j].rgbtGreen + src[i - 1][j - 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j - 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = rounding((src[i - 1][j].rgbtBlue + src[i - 1][j - 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j - 1].rgbtBlue) / 4.0);
                }
                else
                {
                    image[i][j].rgbtRed = rounding((src[i][j - 1].rgbtRed + src[i][j].rgbtRed + src[i][j + 1].rgbtRed + src[i - 1][j - 1].rgbtRed + src[i - 1][j].rgbtRed + src[i - 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = rounding((src[i][j - 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j + 1].rgbtGreen + src[i - 1][j - 1].rgbtGreen + src[i - 1][j].rgbtGreen + src[i - 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = rounding((src[i][j - 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j + 1].rgbtBlue + src[i - 1][j - 1].rgbtBlue + src[i - 1][j].rgbtBlue + src[i - 1][j + 1].rgbtBlue) / 6.0);
                }
            }
            else if (j == 0)
            {
                image[i][j].rgbtRed = rounding((src[i - 1][j].rgbtRed + src[i - 1][j + 1].rgbtRed + src[i][j].rgbtRed + src[i][j + 1].rgbtRed + src[i + 1][j].rgbtRed + src[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = rounding((src[i - 1][j].rgbtGreen + src[i - 1][j + 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j + 1].rgbtGreen + src[i + 1][j].rgbtGreen + src[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = rounding((src[i - 1][j].rgbtBlue + src[i - 1][j + 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j + 1].rgbtBlue + src[i + 1][j].rgbtBlue + src[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = rounding((src[i - 1][j].rgbtRed + src[i - 1][j - 1].rgbtRed + src[i][j].rgbtRed + src[i][j - 1].rgbtRed + src[i + 1][j].rgbtRed + src[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = rounding((src[i - 1][j].rgbtGreen + src[i - 1][j - 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j - 1].rgbtGreen + src[i + 1][j].rgbtGreen + src[i + 1][j - 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = rounding((src[i - 1][j].rgbtBlue + src[i - 1][j - 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j - 1].rgbtBlue + src[i + 1][j].rgbtBlue + src[i + 1][j - 1].rgbtBlue) / 6.0);
            }
            else if (j != 0 && j != width - 1 && i != 0 && i != height - 1)
            {
            image[i][j].rgbtRed = rounding((src[i - 1][j - 1].rgbtRed + src[i - 1][j].rgbtRed + src[i - 1][j + 1].rgbtRed + src[i][j - 1].rgbtRed + src[i][j].rgbtRed + src[i][j + 1].rgbtRed + src[i + 1][j - 1].rgbtRed + src[i + 1][j].rgbtRed + src[i + 1][j + 1].rgbtRed) / 9.0);

            image[i][j].rgbtGreen = rounding((src[i - 1][j - 1].rgbtGreen + src[i - 1][j].rgbtGreen + src[i - 1][j + 1].rgbtGreen + src[i][j - 1].rgbtGreen + src[i][j].rgbtGreen + src[i][j + 1].rgbtGreen + src[i + 1][j - 1].rgbtGreen + src[i + 1][j].rgbtGreen + src[i + 1][j + 1].rgbtGreen) / 9.0);

            image[i][j].rgbtBlue = rounding((src[i - 1][j - 1].rgbtBlue + src[i - 1][j].rgbtBlue + src[i - 1][j + 1].rgbtBlue + src[i][j - 1].rgbtBlue + src[i][j].rgbtBlue + src[i][j + 1].rgbtBlue + src[i + 1][j - 1].rgbtBlue + src[i + 1][j].rgbtBlue + src[i + 1][j + 1].rgbtBlue) / 9.0);
            }

        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE src[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            src[i][j] = image[i][j];
        }
    }

    float gxRed, gxGreen, gxBlue, gyRed, gyGreen, gyBlue, R, G, B;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                gxRed = src[i][j + 1].rgbtRed * 2 + src[i + 1][j + 1].rgbtRed;
                gyRed = src[i + 1][j].rgbtRed * 2 + src[i + 1][j + 1].rgbtRed;
                gxGreen = src[i][j + 1].rgbtGreen * 2 + src[i + 1][j + 1].rgbtGreen;
                gyGreen = src[i + 1][j].rgbtGreen * 2 + src[i + 1][j + 1].rgbtGreen;
                gxBlue = src[i][j + 1].rgbtBlue * 2 + src[i + 1][j + 1].rgbtBlue;
                gyBlue = src[i + 1][j].rgbtBlue * 2 + src[i + 1][j + 1].rgbtBlue;
            }
            else if (i == 0 && j == width - 1)
            {
                gxRed = src[i][j - 1].rgbtRed * -2 + src[i + 1][j - 1].rgbtRed * -1;
                gyRed = src[i + 1][j].rgbtRed * 2 + src[i + 1][j - 1].rgbtRed;
                gxGreen = src[i][j - 1].rgbtGreen * -2 + src[i + 1][j - 1].rgbtGreen * -1;
                gyGreen = src[i + 1][j].rgbtGreen * 2 + src[i + 1][j - 1].rgbtGreen;
                gxBlue = src[i][j - 1].rgbtBlue * -2 + src[i + 1][j - 1].rgbtBlue * -1;
                gyBlue = src[i + 1][j].rgbtBlue * 2 + src[i + 1][j - 1].rgbtBlue;
            }
            else if (i == height - 1 && j == 0)
            {
                gxRed = src[i - 1][j + 1].rgbtRed + src[i][j + 1].rgbtRed * 2;
                gyRed = src[i - 1][j].rgbtRed * -2 + src[i - 1][j + 1].rgbtRed * -1;
                gxGreen = src[i - 1][j + 1].rgbtGreen + src[i][j + 1].rgbtGreen * 2;
                gyGreen = src[i - 1][j].rgbtGreen * -2 + src[i - 1][j + 1].rgbtGreen * -1;
                gxBlue = src[i - 1][j + 1].rgbtBlue + src[i][j + 1].rgbtBlue * 2;
                gyBlue = src[i - 1][j].rgbtBlue * -2 + src[i - 1][j + 1].rgbtBlue * -1;
            }
            else if (i == height - 1 && j == width - 1)
            {
                gxRed = src[i][j - 1].rgbtRed * -2 + src[i - 1][j - 1].rgbtRed * -1;
                gyRed = src[i - 1][j].rgbtRed * -2 + src[i - 1][j - 1].rgbtRed * -1;
                gxGreen = src[i][j - 1].rgbtGreen * -2 + src[i - 1][j - 1].rgbtGreen * -1;
                gyGreen = src[i - 1][j].rgbtGreen * -2 + src[i - 1][j - 1].rgbtGreen * -1;
                gxBlue = src[i][j - 1].rgbtBlue * -2 + src[i - 1][j - 1].rgbtBlue * -1;
                gyBlue = src[i - 1][j].rgbtBlue * -2 + src[i - 1][j - 1].rgbtBlue * -1;
            }
            else if (i == 0)
            {
                gxRed = src[i][j - 1].rgbtRed * -2  + src[i][j + 1].rgbtRed * 2  + src[i + 1][j - 1].rgbtRed * -1  + src[i + 1][j + 1].rgbtRed;
                gyRed = src[i + 1][j - 1].rgbtRed + src[i + 1][j].rgbtRed * 2 + src[i + 1][j + 1].rgbtRed;
                gxBlue = src[i][j - 1].rgbtBlue * -2  + src[i][j + 1].rgbtBlue * 2  + src[i + 1][j - 1].rgbtBlue * -1  + src[i + 1][j + 1].rgbtBlue;
                gyBlue = src[i + 1][j - 1].rgbtBlue + src[i + 1][j].rgbtBlue * 2 + src[i + 1][j + 1].rgbtBlue;
                gxGreen = src[i][j - 1].rgbtGreen * -2  + src[i][j + 1].rgbtGreen * 2  + src[i + 1][j - 1].rgbtGreen * -1  + src[i + 1][j + 1].rgbtGreen;
                gyGreen = src[i + 1][j - 1].rgbtGreen + src[i + 1][j].rgbtGreen * 2 + src[i + 1][j + 1].rgbtGreen;
            }
            else if (i == height - 1)
            {
                gxRed = src[i - 1][j - 1].rgbtRed * -1  + src[i - 1][j + 1].rgbtRed + src[i][j - 1].rgbtRed * -2  + src[i][j + 1].rgbtRed * 2;
                gyRed = src[i - 1][j - 1].rgbtRed * -1 + src[i - 1][j].rgbtRed * -2 + src[i - 1][j + 1].rgbtRed * -1;
                gxGreen = src[i - 1][j - 1].rgbtGreen * -1  + src[i - 1][j + 1].rgbtGreen + src[i][j - 1].rgbtGreen * -2  + src[i][j + 1].rgbtGreen * 2;
                gyGreen = src[i - 1][j - 1].rgbtGreen * -1 + src[i - 1][j].rgbtGreen * -2 + src[i - 1][j + 1].rgbtGreen * -1;
                gxBlue = src[i - 1][j - 1].rgbtBlue * -1  + src[i - 1][j + 1].rgbtBlue + src[i][j - 1].rgbtBlue * -2  + src[i][j + 1].rgbtBlue * 2;
                gyBlue = src[i - 1][j - 1].rgbtBlue * -1 + src[i - 1][j].rgbtBlue * -2 + src[i - 1][j + 1].rgbtBlue * -1;
            }
            else if (j == 0)
            {
                gxRed = src[i - 1][j + 1].rgbtRed + src[i][j + 1].rgbtRed * 2  + src[i + 1][j + 1].rgbtRed;
                gyRed = src[i - 1][j].rgbtRed * -2 + src[i + 1][j].rgbtRed * 2 + src[i - 1][j + 1].rgbtRed * -1 + src[i + 1][j + 1].rgbtRed;
                gxGreen = src[i - 1][j + 1].rgbtGreen + src[i][j + 1].rgbtGreen * 2  + src[i + 1][j + 1].rgbtGreen;
                gyGreen = src[i - 1][j].rgbtGreen * -2 + src[i + 1][j].rgbtGreen * 2 + src[i - 1][j + 1].rgbtGreen * -1 + src[i + 1][j + 1].rgbtGreen;
                gxBlue = src[i - 1][j + 1].rgbtBlue + src[i][j + 1].rgbtBlue * 2  + src[i + 1][j + 1].rgbtBlue;
                gyBlue = src[i - 1][j].rgbtBlue * -2 + src[i + 1][j].rgbtBlue * 2 + src[i - 1][j + 1].rgbtBlue * -1 + src[i + 1][j + 1].rgbtBlue;
            }
            else if (j == width - 1)
            {
                gxRed = src[i - 1][j - 1].rgbtRed * -1 + src[i][j - 1].rgbtRed * -2  + src[i + 1][j - 1].rgbtRed * -1;
                gyRed = src[i - 1][j].rgbtRed * -2 + src[i + 1][j].rgbtRed * 2 + src[i - 1][j - 1].rgbtRed * -1 + src[i + 1][j - 1].rgbtRed;
                gxGreen = src[i - 1][j - 1].rgbtGreen * -1 + src[i][j - 1].rgbtGreen * -2  + src[i + 1][j - 1].rgbtGreen * -1;
                gyGreen = src[i - 1][j].rgbtGreen * -2 + src[i + 1][j].rgbtGreen * 2 + src[i - 1][j - 1].rgbtGreen * -1 + src[i + 1][j - 1].rgbtGreen;
                gxBlue = src[i - 1][j - 1].rgbtBlue * -1 + src[i][j - 1].rgbtBlue * -2  + src[i + 1][j - 1].rgbtBlue * -1;
                gyBlue = src[i - 1][j].rgbtBlue * -2 + src[i + 1][j].rgbtBlue * 2 + src[i - 1][j - 1].rgbtBlue * -1 + src[i + 1][j - 1].rgbtBlue;
            }
            else
            {
                gxRed = (src[i - 1][j - 1].rgbtRed * -1) + src[i - 1][j + 1].rgbtRed + (src[i][j - 1].rgbtRed * -2) + (src[i][j + 1].rgbtRed * 2) + (src[i + 1][j - 1].rgbtRed * -1) + src[i + 1][j + 1].rgbtRed;
                gyRed = (src[i - 1][j - 1].rgbtRed * -1) + (src[i - 1][j].rgbtRed * -2) + (src[i - 1][j + 1].rgbtRed * -1) + src[i + 1][j - 1].rgbtRed + (src[i + 1][j].rgbtRed * 2) + src[i + 1][j + 1].rgbtRed;
                gxGreen = (src[i - 1][j - 1].rgbtGreen * -1) + src[i - 1][j + 1].rgbtGreen + (src[i][j - 1].rgbtGreen * -2) + (src[i][j + 1].rgbtGreen * 2) + (src[i + 1][j - 1].rgbtGreen * -1) + src[i + 1][j + 1].rgbtGreen;
                gyGreen = (src[i - 1][j - 1].rgbtGreen * -1) + (src[i - 1][j].rgbtGreen * -2) + (src[i - 1][j + 1].rgbtGreen * -1) + src[i + 1][j - 1].rgbtGreen + (src[i + 1][j].rgbtGreen * 2) + src[i + 1][j + 1].rgbtGreen;
                gxBlue = (src[i - 1][j - 1].rgbtBlue * -1) + src[i - 1][j + 1].rgbtBlue + (src[i][j - 1].rgbtBlue * -2) + (src[i][j + 1].rgbtBlue * 2) + (src[i + 1][j - 1].rgbtBlue * -1) + src[i + 1][j + 1].rgbtBlue;
                gyBlue = (src[i - 1][j - 1].rgbtBlue * -1) + (src[i - 1][j].rgbtBlue * -2) + (src[i - 1][j + 1].rgbtBlue * -1) + src[i + 1][j - 1].rgbtBlue + (src[i + 1][j].rgbtBlue * 2) + src[i + 1][j + 1].rgbtBlue;
            }
            R = sqrt(pow(gxRed, 2) + pow(gyRed, 2));
            G = sqrt(pow(gxGreen, 2) + pow(gyGreen, 2));
            B = sqrt(pow(gxBlue, 2) + pow(gyBlue, 2));

            if (R > 255)
            {
                R = 255;
            }
            if (G > 255)
            {
                G = 255;
            }
            if (B > 255)
            {
                B = 255;
            }

            image[i][j].rgbtRed = rounding(R);
            image[i][j].rgbtGreen = rounding(G);
            image[i][j].rgbtBlue = rounding(B);
        }
    }
    return;
}
