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

            image[i][j].rgbtRed = round(rgb_avg);
            image[i][j].rgbtGreen = round(rgb_avg);
            image[i][j].rgbtBlue = round(rgb_avg);
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

            double sepiaRed = .393 * (double) r + .769 * (double) g + .189 * (double) b;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            double sepiaGreen = .349 * (double) r + .686 * (double) g + .168 * (double) b;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            double sepiaBlue = .272 * (double) r + .534 * (double) g + .131 * (double) b;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
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
        for (int j = 0; j < width; j++)
        {
            buffer[j].rgbtRed = image[i][j].rgbtRed;
            buffer[j].rgbtGreen = image[i][j].rgbtGreen;
            buffer[j].rgbtBlue = image[i][j].rgbtBlue;
        }
        for (int j = 0; j < width; j++)
        {                                 // The -1 is to account for 0 indexing
            image[i][j].rgbtRed = buffer[width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = buffer[width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = buffer[width - j - 1].rgbtBlue;
        }
    }
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // If pixel is on the top
            if (i == 0)
            {
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mm = image[i][j];
                RGBTRIPLE mr = image[i][j + 1];
                RGBTRIPLE bl = image[i + 1][j - 1];
                RGBTRIPLE bm = image[i + 1][j];
                RGBTRIPLE br = image[i + 1][j + 1];

                double r_avg = (double) (ml.rgbtRed + mm.rgbtRed + mr.rgbtRed + bl.rgbtRed + bm.rgbtRed + br.rgbtRed) / 6.0;
                double g_avg = (double) (ml.rgbtGreen + mm.rgbtGreen + mr.rgbtGreen + bl.rgbtGreen + bm.rgbtGreen + br.rgbtGreen) / 6.0;
                double b_avg = (double) (ml.rgbtBlue + mm.rgbtBlue + mr.rgbtBlue + bl.rgbtBlue + bm.rgbtBlue + br.rgbtBlue) / 6.0;

                image[i][j].rgbtRed = round(r_avg);
                image[i][j].rgbtGreen = round(g_avg);
                image[i][j].rgbtBlue = round(b_avg);
            }
            // If pixel is on the bottom
            else if (i == height)
            {
                RGBTRIPLE tl = image[i - 1][j - 1];
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE tr = image[i - 1][j + 1];
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mm = image[i][j];
                RGBTRIPLE mr = image[i][j + 1];

                double r_avg = (double) (tl.rgbtRed + tm.rgbtRed + tr.rgbtRed + ml.rgbtRed + mm.rgbtRed + mr.rgbtRed) / 6.0;
                double g_avg = (double) (tl.rgbtGreen + tm.rgbtGreen + tr.rgbtGreen + ml.rgbtGreen + mm.rgbtGreen + mr.rgbtGreen) / 6.0;
                double b_avg = (double) (tl.rgbtBlue + tm.rgbtBlue + tr.rgbtBlue + ml.rgbtBlue + mm.rgbtBlue + mr.rgbtBlue) / 6.0;

                image[i][j].rgbtRed = round(r_avg);
                image[i][j].rgbtGreen = round(g_avg);
                image[i][j].rgbtBlue = round(b_avg);
            }
            // If pixel is on the left wall
            else if (j == 0)
            {
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE tr = image[i - 1][j + 1];
                RGBTRIPLE mm = image[i][j];
                RGBTRIPLE mr = image[i][j + 1];
                RGBTRIPLE bm = image[i + 1][j];
                RGBTRIPLE br = image[i + 1][j + 1];

                double r_avg = (double) (tm.rgbtRed +tr.rgbtRed + mm.rgbtRed + mr.rgbtRed + bm.rgbtRed + br.rgbtRed) / 6.0;
                double g_avg = (double) (tm.rgbtGreen +tr.rgbtGreen + mm.rgbtGreen + mr.rgbtGreen + bm.rgbtGreen + br.rgbtGreen) / 6.0;
                double b_avg = (double) (tm.rgbtBlue +tr.rgbtBlue + mm.rgbtBlue + mr.rgbtBlue + bm.rgbtBlue + br.rgbtBlue) / 6.0;

                image[i][j].rgbtRed = round(r_avg);
                image[i][j].rgbtGreen = round(g_avg);
                image[i][j].rgbtBlue = round(b_avg);
            }
            // If pixel is on the right wall
            else if (j == width - 1)
            {
                RGBTRIPLE tl = image[i - 1][j - 1];
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mm = image[i][j];
                RGBTRIPLE bl = image[i + 1][j - 1];
                RGBTRIPLE bm = image[i + 1][j];

                double r_avg = (double) (tl.rgbtRed + tm.rgbtRed + ml.rgbtRed + mm.rgbtRed + bl.rgbtRed + bm.rgbtRed) / 6.0;
                double g_avg = (double) (tl.rgbtGreen + tm.rgbtGreen + ml.rgbtGreen + mm.rgbtGreen + bl.rgbtGreen + bm.rgbtGreen) / 6.0;
                double b_avg = (double) (tl.rgbtBlue + tm.rgbtBlue + ml.rgbtBlue + mm.rgbtBlue + bl.rgbtBlue + bm.rgbtBlue) / 6.0;

                image[i][j].rgbtRed = round(r_avg);
                image[i][j].rgbtGreen = round(g_avg);
                image[i][j].rgbtBlue = round(b_avg);
            }
            // Anywhere else
            else
            {
                RGBTRIPLE tl = image[i - 1][j - 1];
                RGBTRIPLE tm = image[i - 1][j];
                RGBTRIPLE tr = image[i - 1][j + 1];
                RGBTRIPLE ml = image[i][j - 1];
                RGBTRIPLE mm = image[i][j];
                RGBTRIPLE mr = image[i][j + 1];
                RGBTRIPLE bl = image[i + 1][j - 1];
                RGBTRIPLE bm = image[i + 1][j];
                RGBTRIPLE br = image[i + 1][j + 1];

                double r_avg = (double) (tl.rgbtRed + tm.rgbtRed + tr.rgbtRed + ml.rgbtRed + mm.rgbtRed + mr.rgbtRed + bl.rgbtRed + bm.rgbtRed + br.rgbtRed) / 9.0;
                double g_avg = (double) (tl.rgbtGreen + tm.rgbtGreen + tr.rgbtGreen + ml.rgbtGreen + mm.rgbtGreen + mr.rgbtGreen + bl.rgbtGreen + bm.rgbtGreen + br.rgbtGreen) / 9.0;
                double b_avg = (double) (tl.rgbtBlue + tm.rgbtBlue + tr.rgbtBlue + ml.rgbtBlue + mm.rgbtBlue + mr.rgbtBlue + bl.rgbtBlue + bm.rgbtBlue + br.rgbtBlue) / 9.0;


                image[i][j].rgbtRed = round(r_avg);
                image[i][j].rgbtGreen = round(g_avg);
                image[i][j].rgbtBlue = round(b_avg);
            }
        }
    }
    return;
}
