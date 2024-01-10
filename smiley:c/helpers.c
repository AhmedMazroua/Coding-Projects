
#include "helpers.h"
// index of comments
// 1). loop through pixel row
// 2). loop through pixel column
// 3). finds black pixels
// 4). changes red saturation
// 5). changes green saturation
// 6). changes blue saturation

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // 1). loops through row of pixels
    for (int row = 0; row < width; row++)
    {
        // 2). loops through column of pixels
        for (int column = 0; column < height; column++)
        {
            // 3). accesses rgb of only black pixels
            if (image[column] [row].rgbtRed == 0 &&
                image[column][row].rgbtGreen == 0 &&
                image[column] [row].rgbtBlue == 0)
            {
                // 4). inputs amount of red
                image[column][row].rgbtRed = 75;
                // 5). inputs amount of green
                image[column][row].rgbtGreen = 40;
                // 6). inputs amount of blue
                image[column][row].rgbtBlue = 255;

            }
        }
    }
}