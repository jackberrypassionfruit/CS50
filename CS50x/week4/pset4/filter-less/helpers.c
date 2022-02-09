#include "helpers.h"
#include <stdio.h>

RGBTRIPLE buffer;

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

            int rgb_avg = (r + g + b) / 3;

            image[i][j].rgbtRed = rgb_avg;
            image[i][j].rgbtGreen = rgb_avg;
            image[i][j].rgbtBlue = rgb_avg;
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
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    buffer = image;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

        }
    }
    return;
}

void blur_helper(int y, int x, int side)
{
    switch (top)
    {
        // Pixel on Top
        case 0:

        break;
        // Pixel on Right Wall
        case 1:

        break;
        // Pixel on Bottom
        case 2:

        break;
        // Pixel on Left Wall
        case 3:

        break;
        default:
            int tl = image[y - 1][x - 1];
            int tm = image[y - 1][x];
            int tr = image[y - 1][x + 1];
            int ml = image[y][x - 1];
            int mr = image[y][x + 1];
            int bl = image[y + 1][x - 1];
            int bm = image[y + 1][x];
            int br = image[y + 1][x + 1];

            int new_
    }
}