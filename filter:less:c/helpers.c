#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // 2x forloops retrieve pixel 2d layout
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //initiates a greyscale value and equalizes all rgb values by use of mean
            int colorless = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // sets each rgb value in each pixel to this average
            image[i][j].rgbtRed = colorless;
            image[i][j].rgbtGreen = colorless;
            image[i][j].rgbtBlue = colorless;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //retrieve pixels 2d layout
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //initiates place holder val for rgb vals R, G, and B
            int originalRed =  image[i][j].rgbtRed;
            int originalGreen =  image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // applies sepia formula to each rgb triple
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // sets a cap of 255 and assigns the original pixels the sepia vals
            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // initiates a rgbtriple val
    RGBTRIPLE tmp;

    //gets pixel layout
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //stores image layout in temporary value
            tmp = image[i][j];

            //swaps pixel mapping and assigns tmp to original image
            image[i][j] = image[i][width -  j - 1];
            image[i][width -  j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //initiates triple val
    RGBTRIPLE cpy[height][width];

    // map pixel layout and asigns image to copy value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cpy[i][j] = image[i][j];
        }
    }

    //creates place holder values and a counter
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;

            float count = 0.00;

            //retrieve surrounding pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int posX = i + x;
                    int posY = j + y;

                    //conditional boolean
                    if (posX < 0 || posX > (height - 1) || posY < 0 || posY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[posX][posY].rgbtRed;
                    totalGreen += image[posX][posY].rgbtGreen;
                    totalBlue += image[posX][posY].rgbtBlue;

                    count++;

                }

                cpy[i][j].rgbtRed = round(totalRed / count);
                cpy[i][j].rgbtGreen = round(totalGreen / count);
                cpy[i][j].rgbtBlue = round(totalBlue / count);

            }
        }
    }
    // reasigns image rgb's to formulated values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = cpy[i][j].rgbtRed;
            image[i][j].rgbtGreen =  cpy[i][j].rgbtGreen;
            image[i][j].rgbtBlue =  cpy[i][j].rgbtBlue;
        }
    }
    return;
}
