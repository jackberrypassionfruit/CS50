#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            double rgb_avg = (double) (r + g + b) / 3.0;

            image[i][j].rgbtRed = (int) rgb_avg;
            image[i][j].rgbtGreen = (int) rgb_avg;
            image[i][j].rgbtBlue = (int) rgb_avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int sepiaRed = .393 * r + .769 * g + .189 * b;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = .349 * r + .686 * g + .168 * b;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = .272 * r + .534 * g + .131 * b;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            buffer[j].rgbtRed = image[i][width - j].rgbtRed;
            buffer[j].rgbtGreen = image[i][width - j].rgbtGreen;
            buffer[j].rgbtBlue = image[i][width - j].rgbtBlue;
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = buffer[j].rgbtRed;
            image[i][j].rgbtGreen = buffer[j].rgbtGreen;
            image[i][j].rgbtBlue = buffer[j].rgbtBlue;
        }
    }
    return;
}

// Blur image

/* Idea that I'm too tired to implement:
    copy data from image into a new RGBTRIPLE called buffer
    row by row, column by column, check if pixel is on a wall
    and then change the pixels in image to the "blurred" ones from the buffer accordingly
    The weird part is that you use different edges based on where the pixel is
    And the ones that you exclude aren't themelves exclusive
    So it's weird
    But I'll  just write a bunch of ifs and it'll be fine
    I think the only helper function that I'll really need is one to change all 3 pixel values at once
    I can do that as long as buffer is global (which it is) and image is global (which I THINK it is because it's from a pointer)

*/

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*buffer)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // If pixel is on the top
            if (i == 0)
            {
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mr = image[i][j + 1];
                RGBTRIPLE bl = image[i + 1][j - 1];
                RGBTRIPLE bm = image[i + 1][j];
                RGBTRIPLE br = image[i + 1][j + 1];

                int r_avg = (ml.rgbtRed + mr.rgbtRed + bl.rgbtRed + bm.rgbtRed + br.rgbtRed) / 5;
                int g_avg = (ml.rgbtGreen + mr.rgbtGreen + bl.rgbtGreen + bm.rgbtGreen + br.rgbtGreen) / 5;
                int b_avg = (ml.rgbtBlue + mr.rgbtBlue + bl.rgbtBlue + bm.rgbtBlue + br.rgbtBlue) / 5;


                image[i][j].rgbtRed = r_avg;
                image[i][j].rgbtGreen = g_avg;
                image[i][j].rgbtBlue = b_avg;

            }
            // If pixel is on the bottom
            else if (i == height)
            {
                RGBTRIPLE tl = image[i - 1][j - 1];
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE tr = image[i - 1][j + 1];
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mr = image[i][j + 1];

                int r_avg = (tl.rgbtRed +tm.rgbtRed + tr.rgbtRed + ml.rgbtRed + mr.rgbtRed) / 5;
                int g_avg = (tl.rgbtGreen +tm.rgbtGreen + tr.rgbtGreen + ml.rgbtGreen + mr.rgbtGreen) / 5;
                int b_avg = (tl.rgbtBlue +tm.rgbtBlue + tr.rgbtBlue + ml.rgbtBlue + mr.rgbtBlue) / 5;

                image[i][j].rgbtRed = r_avg;
                image[i][j].rgbtGreen = g_avg;
                image[i][j].rgbtBlue = b_avg;
            }
            // If pixel is on the left wall
            else if (j == 0)
            {
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE tr = image[i - 1][j + 1];
                RGBTRIPLE mr = image[i][j + 1];
                RGBTRIPLE bm = image[i + 1][j];
                RGBTRIPLE br = image[i + 1][j + 1];

                int r_avg = (tm.rgbtRed +tr.rgbtRed + mr.rgbtRed + bm.rgbtRed + br.rgbtRed) / 5;
                int g_avg = (tm.rgbtGreen +tr.rgbtGreen + mr.rgbtGreen + bm.rgbtGreen + br.rgbtGreen) / 5;
                int b_avg = (tm.rgbtBlue +tr.rgbtBlue + mr.rgbtBlue + bm.rgbtBlue + br.rgbtBlue) / 5;

                image[i][j].rgbtRed = r_avg;
                image[i][j].rgbtGreen = g_avg;
                image[i][j].rgbtBlue = b_avg;
            }
            // If pixel is on the right wall
            else if (j == width)
            {
                RGBTRIPLE tl = image[i - 1][j - 1];
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE bl = image[i + 1][j - 1];
                RGBTRIPLE bm = image[i + 1][j];

                int r_avg = (tl.rgbtRed +tm.rgbtRed + ml.rgbtRed + bl.rgbtRed + bm.rgbtRed) / 5;
                int g_avg = (tl.rgbtGreen +tm.rgbtGreen + ml.rgbtGreen + bl.rgbtGreen + bm.rgbtGreen) / 5;
                int b_avg = (tl.rgbtBlue +tm.rgbtBlue + ml.rgbtBlue + bl.rgbtBlue + bm.rgbtBlue) / 5;

                image[i][j].rgbtRed = r_avg;
                image[i][j].rgbtGreen = g_avg;
                image[i][j].rgbtBlue = b_avg;
            }
            // Anywhere else
            else
            {
                RGBTRIPLE tl = image[i - 1][j - 1];
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE tr = image[i - 1][j + 1];
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mr = image[i][j + 1];
                RGBTRIPLE bl = image[i + 1][j - 1];
                RGBTRIPLE bm = image[i + 1][j];
                RGBTRIPLE br = image[i + 1][j + 1];

                int r_avg = (tl.rgbtRed + tm.rgbtRed + tr.rgbtRed + ml.rgbtRed + mr.rgbtRed + bl.rgbtRed + bm.rgbtRed + br.rgbtRed) / 8;
                int g_avg = (tl.rgbtGreen + tm.rgbtGreen + tr.rgbtGreen + ml.rgbtGreen + mr.rgbtGreen + bl.rgbtGreen + bm.rgbtGreen + br.rgbtGreen) / 8;
                int b_avg = (tl.rgbtBlue + tm.rgbtBlue + tr.rgbtBlue + ml.rgbtBlue + mr.rgbtBlue + bl.rgbtBlue + bm.rgbtRed + br.rgbtBlue) / 8;


                image[i][j].rgbtRed = r_avg;
                image[i][j].rgbtGreen = g_avg;
                image[i][j].rgbtBlue = b_avg;
            }
        }
    }
    return;
}