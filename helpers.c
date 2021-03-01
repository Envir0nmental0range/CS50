#include "helpers.h"
#include <stdio.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            avg = round((image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed)/3);
            image[x][y].rgbtBlue = avg;
            image[x][y].rgbtGreen = avg;
            image[x][y].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            sepiaRed = round(0.393 * image[x][y].rgbtRed + 0.769 * image[x][y].rgbtGreen + 0.189 * image[x][y].rgbtBlue);
            sepiaGreen = round(0.349 * image[x][y].rgbtRed + 0.686 * image[x][y].rgbtGreen + 0.168 * image[x][y].rgbtBlue);
            sepiaBlue = round(0.272 * image[x][y].rgbtRed + 0.534 * image[x][y].rgbtGreen + 0.131 * image[x][y].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
             if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
             if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[x][y].rgbtBlue = sepiaBlue;
            image[x][y].rgbtGreen = sepiaGreen;
            image[x][y].rgbtRed = sepiaRed;
        }
    }#include "helpers.h"
#include <stdio.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            avg = round((0.5 + image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed)/3);
            image[x][y].rgbtBlue = avg;
            image[x][y].rgbtGreen = avg;
            image[x][y].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            sepiaRed = round(0.5 + 0.393 * image[x][y].rgbtRed + 0.769 * image[x][y].rgbtGreen + 0.189 * image[x][y].rgbtBlue);
            sepiaGreen = round(0.5 + 0.349 * image[x][y].rgbtRed + 0.686 * image[x][y].rgbtGreen + 0.168 * image[x][y].rgbtBlue);
            sepiaBlue = round(0.5 + 0.272 * image[x][y].rgbtRed + 0.534 * image[x][y].rgbtGreen + 0.131 * image[x][y].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
             if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
             if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[x][y].rgbtBlue = sepiaBlue;
            image[x][y].rgbtGreen = sepiaGreen;
            image[x][y].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            copy[x][y].rgbtBlue = image[x][width - y - 1].rgbtBlue;
            copy[x][y].rgbtGreen = image[x][width - y - 1].rgbtGreen;
            copy[x][y].rgbtRed = image[x][width - y- 1].rgbtRed;
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtBlue = copy[x][y].rgbtBlue;
            image[x][y].rgbtGreen = copy[x][y].rgbtGreen;
            image[x][y].rgbtRed = copy[x][y].rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int blue;
    int red;
    int green;
    int colour;
    int w = width;
    int h = height;
    //Set each of the four corners to correct blurred value

    //Corner [0][]
    colour = round(0.5 + (image[0][0].rgbtBlue + image[1][0].rgbtBlue + image[0][1].rgbtBlue + image[1][1].rgbtBlue)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[0][0].rgbtBlue = colour;

    colour = round(0.5 + (image[0][0].rgbtGreen + image[1][0].rgbtGreen + image[0][1].rgbtGreen + image[1][1].rgbtGreen)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[0][0].rgbtGreen = colour;

    colour = round(0.5 + (image[0][0].rgbtRed + image[1][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[0][0].rgbtRed = colour;

    //corner[0][width - 1]
    colour = round(0.5 + (image[0][w - 1].rgbtBlue + image[0][w - 2].rgbtBlue + image[1][w - 1].rgbtBlue + image[1][w - 2].rgbtBlue)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[0][w - 1].rgbtBlue = colour;

    colour = round(0.5 + (image[0][w - 1].rgbtGreen + image[0][w - 2].rgbtGreen + image[1][w - 1].rgbtGreen + image[1][w - 2].rgbtGreen)/4);
    if (colour > 255)
    {
        colour = 255;
    }
        copy[0][w - 1].rgbtGreen = colour;

    colour = round(0.5 + (image[0][w - 1].rgbtRed + image[0][w - 2].rgbtRed + image[1][w - 1].rgbtRed + image[1][w - 2].rgbtRed)/4);
    if (colour > 255)
    {
        colour = 255;
    }
        copy[0][w - 1].rgbtRed = colour;

    //corner [height - 1][0]
    colour = round(0.5 + (image[h - 1][0].rgbtBlue + image[h - 2][0].rgbtBlue + image[h - 1][1].rgbtBlue + image[h - 2][1].rgbtBlue)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[h - 1][0].rgbtBlue = colour;

    colour = round(0.5 + (image[h - 1][0].rgbtGreen + image[h - 2][0].rgbtGreen + image[h - 1][1].rgbtGreen + image[h - 2][1].rgbtGreen)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[h - 1][0].rgbtGreen = colour;

    colour = round(0.5 + (image[h - 1][0].rgbtRed + image[h - 2][0].rgbtRed + image[h - 1][1].rgbtRed + image[h - 2][1].rgbtRed)/4);
    if (colour > 255)
    {
        colour = 255;
    }

    copy[h - 1][0].rgbtRed = colour;

   //corner [height - 1][width - 1]
    colour = round(0.5 + (image[h - 1][w - 1].rgbtBlue + image[h - 2][w - 1].rgbtBlue + image[h - 1][w - 2].rgbtBlue + image[h - 2][w - 2].rgbtBlue)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[h - 1][w - 1].rgbtBlue = colour;

    colour = round(0.5 + (image[h - 1][w - 1].rgbtGreen + image[h - 2][w - 1].rgbtGreen + image[h - 1][w - 2].rgbtGreen + image[h - 2][w - 2].rgbtGreen)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[h - 1][w - 1].rgbtGreen = colour;

    colour = round(0.5 + (image[h - 1][w - 1].rgbtRed + image[h - 2][w - 1].rgbtRed + image[h - 1][w - 2].rgbtRed + image[h - 2][w - 2].rgbtRed)/4);
    if (colour > 255)
    {
        colour = 255;
    }
    copy[h - 1][w - 1].rgbtRed = colour;

    //Set row 0 and row w - 1 to blurred value excluding corners
    for (int x = 1; x <= height - 2; x++)
    {
        colour = round(0.5 + (image[x - 1][0].rgbtBlue + image[x - 1][1].rgbtBlue + image[x][0].rgbtBlue + image[x][1].rgbtBlue + image[x + 1][0].rgbtBlue + image[x + 1][1].rgbtBlue)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[x][0].rgbtBlue = colour;

        colour = round(0.5 + (image[x - 1][0].rgbtGreen + image[x - 1][1].rgbtGreen + image[x][0].rgbtGreen + image[x][1].rgbtGreen + image[x + 1][0].rgbtGreen + image[x + 1][1].rgbtGreen)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[x][0].rgbtGreen = colour;

        colour = round(0.5 + (image[x - 1][0].rgbtRed + image[x - 1][1].rgbtRed + image[x][0].rgbtRed + image[x][1].rgbtRed + image[x + 1][0].rgbtRed + image[x + 1][1].rgbtRed)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[x][0].rgbtRed = colour;

        colour = round(0.5 + (image[x - 1][w - 2].rgbtBlue + image[x - 1][w - 1].rgbtBlue + image[x][w - 2].rgbtBlue + image[x][w - 1].rgbtBlue + image[x + 1][w - 2].rgbtBlue + image[x + 1][w - 1].rgbtBlue)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[x][w - 1].rgbtBlue = colour;

        colour = round(0.5 + (image[x - 1][w - 2].rgbtGreen + image[x - 1][w - 1].rgbtGreen + image[x][w - 2].rgbtGreen + image[x][w - 1].rgbtGreen + image[x + 1][w - 2].rgbtGreen + image[x + 1][w - 1].rgbtGreen)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[x][w - 1].rgbtGreen = colour;

        colour = round(0.5 + (image[x - 1][w - 2].rgbtRed + image[x - 1][w - 1].rgbtRed + image[x][w - 2].rgbtRed + image[x][w - 1].rgbtRed + image[x + 1][w - 2].rgbtRed + image[x + 1][w - 1].rgbtRed)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[x][w - 1].rgbtRed = colour;
    }

    //Set column 0 and column h - 1 to blurred value excluding corners
    for (int y = 1; y <= width - 2; y++)
    {
        colour = round(0.5 + (image[0][y - 1].rgbtBlue + image[0][y].rgbtBlue + image[0][y + 1].rgbtBlue + image[1][y - 1].rgbtBlue + image[1][y].rgbtBlue + image[1][y + 1].rgbtBlue)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[0][y].rgbtBlue = colour;

        colour = round(0.5 + (image[0][y - 1].rgbtGreen + image[0][y].rgbtGreen + image[0][y + 1].rgbtGreen + image[1][y - 1].rgbtGreen + image[1][y].rgbtGreen + image[1][y + 1].rgbtGreen)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[0][y].rgbtGreen = colour;

        colour = round(0.5 + (image[0][y - 1].rgbtRed + image[0][y].rgbtRed + image[0][y + 1].rgbtRed + image[1][y - 1].rgbtRed + image[1][y].rgbtRed + image[1][y + 1].rgbtRed)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[0][y].rgbtRed = colour;

        colour = round(0.5 + (image[h - 1][y - 1].rgbtBlue + image[h - 1][y].rgbtBlue + image[h - 1][y + 1].rgbtBlue + image[h - 2][y - 1].rgbtBlue + image[h - 2][y].rgbtBlue + image[h - 2][y + 1].rgbtBlue)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[h - 1][y].rgbtBlue = colour;

        colour = round(0.5 + (image[h - 1][y - 1].rgbtGreen + image[h - 1][y].rgbtGreen + image[h - 1][y + 1].rgbtGreen + image[h - 2][y - 1].rgbtGreen + image[h - 2][y].rgbtGreen + image[h - 2][y + 1].rgbtGreen)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[h - 1][y].rgbtGreen = colour;

        colour = round(0.5 + (image[h - 1][y - 1].rgbtRed + image[h - 1][y].rgbtRed + image[h - 1][y + 1].rgbtRed + image[h - 2][y - 1].rgbtRed + image[h - 2][y].rgbtRed + image[h - 2][y + 1].rgbtRed)/6);
        if (colour > 255)
        {
            colour = 255;
        }
        copy[h - 1][y].rgbtRed = colour;
    }
    //Loop through all inner pixels and replace
    for (int x = 1; x <= height - 2; x++)
    {
        for (int y = 1; y <= width - 2; y++)
        {
            colour = round(0.5 + (image[x - 1][y - 1].rgbtBlue + image[x - 1][y].rgbtBlue + image[x - 1][y + 1].rgbtBlue + image[x][y - 1].rgbtBlue + image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue + image[x + 1][y - 1].rgbtBlue + image[x + 1][y].rgbtBlue + image[x + 1][y + 1].rgbtBlue)/9);
            if (colour > 255)
            {
                colour = 255;
            }
            copy[x][y].rgbtBlue = colour;

            colour = round(0.5 + (image[x - 1][y - 1].rgbtGreen + image[x - 1][y].rgbtGreen + image[x - 1][y + 1].rgbtGreen + image[x][y - 1].rgbtGreen + image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen + image[x + 1][y - 1].rgbtGreen + image[x + 1][y].rgbtGreen + image[x + 1][y + 1].rgbtGreen)/9);
            if (colour > 255)
            {
                colour = 255;
            }
            copy[x][y].rgbtGreen = colour;

            colour = round(0.5 + (image[x - 1][y - 1].rgbtRed + image[x - 1][y].rgbtRed + image[x - 1][y + 1].rgbtRed + image[x][y - 1].rgbtRed + image[x][y].rgbtRed + image[x][y + 1].rgbtRed + image[x + 1][y - 1].rgbtRed + image[x + 1][y].rgbtRed + image[x + 1][y + 1].rgbtRed)/9);
            if (colour > 255)
            {
                colour = 255;
            }

            copy[x][y].rgbtRed = colour;
        }
    }
    //Set image values to those now stored in copy
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtBlue = copy[x][y].rgbtBlue;
            image[x][y].rgbtGreen = copy[x][y].rgbtGreen;
            image[x][y].rgbtRed = copy[x][y].rgbtRed;
        }
    }
    return;
}

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            copy[x][y].rgbtBlue = image[x][width - y - 1].rgbtBlue;
            copy[x][y].rgbtGreen = image[x][width - y - 1].rgbtGreen;
            copy[x][y].rgbtRed = image[x][width - y- 1].rgbtRed;
        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtBlue = copy[x][y].rgbtBlue;
            image[x][y].rgbtGreen = copy[x][y].rgbtGreen;
            image[x][y].rgbtRed = copy[x][y].rgbtRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int w = width;
    int h = height;
    //Set each of the four corners to correct blurred value
    copy[0][0].rgbtBlue = round((image[0][0].rgbtBlue + image[1][0].rgbtBlue + image[0][1].rgbtBlue + image[1][1].rgbtBlue)/4);
    copy[0][0].rgbtGreen = round((image[0][0].rgbtGreen + image[1][0].rgbtGreen + image[0][1].rgbtGreen + image[1][1].rgbtGreen)/4);
    copy[0][0].rgbtRed = round((image[0][0].rgbtRed + image[1][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed)/4);

    copy[0][w - 1].rgbtBlue = round((image[0][w - 1].rgbtBlue + image[0][w - 2].rgbtBlue + image[1][w - 1].rgbtBlue + image[1][w - 2].rgbtBlue)/4);
    copy[0][w - 1].rgbtGreen = round((image[0][w - 1].rgbtGreen + image[0][w - 2].rgbtGreen + image[1][w - 1].rgbtGreen + image[1][w - 2].rgbtGreen)/4);
    copy[0][w - 1].rgbtRed = round((image[0][w - 1].rgbtRed + image[0][w - 2].rgbtRed + image[1][w - 1].rgbtRed + image[1][w - 2].rgbtRed)/4);

    copy[h - 1][0].rgbtBlue = round((image[h - 1][0].rgbtBlue + image[h - 2][0].rgbtBlue + image[h - 1][1].rgbtBlue + image[h - 2][1].rgbtBlue)/4);
    copy[h - 1][0].rgbtGreen = round((image[h - 1][0].rgbtGreen + image[h - 2][0].rgbtGreen + image[h - 1][1].rgbtGreen + image[h - 2][1].rgbtGreen)/4);
    copy[h - 1][0].rgbtRed = round((image[h - 1][0].rgbtRed + image[h - 2][0].rgbtRed + image[h - 1][1].rgbtRed + image[h - 2][1].rgbtRed)/4);

    copy[h - 1][w - 1].rgbtBlue = round((image[h - 1][w - 1].rgbtBlue + image[h - 2][w - 1].rgbtBlue + image[h - 1][w - 2].rgbtBlue + image[h - 2][w - 2].rgbtBlue)/4);
    copy[h - 1][w - 1].rgbtGreen = round((image[h - 1][w - 1].rgbtGreen + image[h - 2][w - 1].rgbtGreen + image[h - 1][w - 2].rgbtGreen + image[h - 2][w - 2].rgbtGreen)/4);
    copy[h - 1][w - 1].rgbtRed = round((image[h - 1][w - 1].rgbtRed + image[h - 2][w - 1].rgbtRed + image[h - 1][w - 2].rgbtRed + image[h - 2][w - 2].rgbtRed)/4);

    //Set row 0 and row w - 1 to blurred value excluding corners
    for (int x = 1; x <= height - 2; x++)
    {
        copy[x][0].rgbtBlue = round((image[x - 1][0].rgbtBlue + image[x - 1][1].rgbtBlue + image[x][0].rgbtBlue + image[x][1].rgbtBlue + image[x + 1][0].rgbtBlue + image[x + 1][1].rgbtBlue)/6);
        copy[x][0].rgbtGreen = round((image[x - 1][0].rgbtGreen + image[x - 1][1].rgbtGreen + image[x][0].rgbtGreen + image[x][1].rgbtGreen + image[x + 1][0].rgbtGreen + image[x + 1][1].rgbtGreen)/6);
        copy[x][0].rgbtRed = round((image[x - 1][0].rgbtRed + image[x - 1][1].rgbtRed + image[x][0].rgbtRed + image[x][1].rgbtRed + image[x + 1][0].rgbtRed + image[x + 1][1].rgbtRed)/6);

        copy[x][w - 1].rgbtBlue = round((image[x - 1][w - 2].rgbtBlue + image[x - 1][w - 1].rgbtBlue + image[x][w - 2].rgbtBlue + image[x][w - 1].rgbtBlue + image[x + 1][w - 2].rgbtBlue + image[x + 1][w - 1].rgbtBlue)/6);
        copy[x][w - 1].rgbtGreen = round((image[x - 1][w - 2].rgbtGreen + image[x - 1][w - 1].rgbtGreen + image[x][w - 2].rgbtGreen + image[x][w - 1].rgbtGreen + image[x + 1][w - 2].rgbtGreen + image[x + 1][w - 1].rgbtGreen)/6);
        copy[x][w - 1].rgbtRed = round((image[x - 1][w - 2].rgbtRed + image[x - 1][w - 1].rgbtRed + image[x][w - 2].rgbtRed + image[x][w - 1].rgbtRed + image[x + 1][w - 2].rgbtRed + image[x + 1][w - 1].rgbtRed)/6);
    }

    //Set column 0 and column h - 1 to blurred value excluding corners
    for (int y = 1; y <= width - 2; y++)
    {
        copy[0][y].rgbtBlue = round((image[0][y - 1].rgbtBlue + image[0][y].rgbtBlue + image[0][y + 1].rgbtBlue + image[1][y - 1].rgbtBlue + image[1][y].rgbtBlue + image[1][y + 1].rgbtBlue)/6);
        copy[0][y].rgbtGreen = round((image[0][y - 1].rgbtGreen + image[0][y].rgbtGreen + image[0][y + 1].rgbtGreen + image[1][y - 1].rgbtGreen + image[1][y].rgbtGreen + image[1][y + 1].rgbtGreen)/6);
        copy[0][y].rgbtRed = round((image[0][y - 1].rgbtRed + image[0][y].rgbtRed + image[0][y + 1].rgbtRed + image[1][y - 1].rgbtRed + image[1][y].rgbtRed + image[1][y + 1].rgbtRed)/6);

        copy[h - 1][y].rgbtBlue = round((image[h - 1][y - 1].rgbtBlue + image[h - 1][y].rgbtBlue + image[h - 1][y + 1].rgbtBlue + image[h - 2][y - 1].rgbtBlue + image[h - 2][y].rgbtBlue + image[h - 2][y + 1].rgbtBlue)/6);
        copy[h - 1][y].rgbtGreen = round((image[h - 1][y - 1].rgbtGreen + image[h - 1][y].rgbtGreen + image[h - 1][y + 1].rgbtGreen + image[h - 2][y - 1].rgbtGreen + image[h - 2][y].rgbtGreen + image[h - 2][y + 1].rgbtGreen)/6);
        copy[h - 1][y].rgbtRed = round((image[h - 1][y - 1].rgbtRed + image[h - 1][y].rgbtRed + image[h - 1][y + 1].rgbtRed + image[h - 2][y - 1].rgbtRed + image[h - 2][y].rgbtRed + image[h - 2][y + 1].rgbtRed)/6);
    }

    //Loop through all inner pixels and replace
    for (int x = 1; x <= height - 2; x++)
    {
        for (int y = 1; y <= width - 2; y++)
        {
            copy[x][y].rgbtBlue = round((image[x - 1][y - 1].rgbtBlue + image[x - 1][y].rgbtBlue + image[x - 1][y + 1].rgbtBlue + image[x][y - 1].rgbtBlue + image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue + image[x + 1][y - 1].rgbtBlue + image[x + 1][y].rgbtBlue + image[x + 1][y + 1].rgbtBlue)/9);
            copy[x][y].rgbtGreen = round((image[x - 1][y - 1].rgbtGreen + image[x - 1][y].rgbtGreen + image[x - 1][y + 1].rgbtGreen + image[x][y - 1].rgbtGreen + image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen + image[x + 1][y - 1].rgbtGreen + image[x + 1][y].rgbtGreen + image[x + 1][y + 1].rgbtGreen)/9);
            copy[x][y].rgbtRed = round((image[x - 1][y - 1].rgbtRed + image[x - 1][y].rgbtRed + image[x - 1][y + 1].rgbtRed + image[x][y - 1].rgbtRed + image[x][y].rgbtRed + image[x][y + 1].rgbtRed + image[x + 1][y - 1].rgbtRed + image[x + 1][y].rgbtRed + image[x + 1][y + 1].rgbtRed)/9);
        }
    }
    //Set image values to those now stored in copy
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y].rgbtBlue = copy[x][y].rgbtBlue;
            image[x][y].rgbtGreen = copy[x][y].rgbtGreen;
            image[x][y].rgbtRed = copy[x][y].rgbtRed;
        }
    }
    return;
}
