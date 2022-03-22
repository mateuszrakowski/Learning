#include "helpers.h"
#include <math.h>

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position);
int computeGx(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position);
int computeGy(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position);
int compute_square(int gx, int gy);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int pixel_greyscale = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixel_greyscale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = pixel_greyscale;
            image[i][j].rgbtBlue = pixel_greyscale;
            image[i][j].rgbtGreen = pixel_greyscale;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width  - j; j++)
        {
            temp = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = temp;
        }
    }
}

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    int sum = 0;
    float counter = 0;

    for (int k = i - 1; k < (i + 2); k++)
    {
        for (int l = j - 1; l < (j + 2); l++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }

            if (color_position == 0)
            {
                sum += image[k][l].rgbtRed;
            }
            else if (color_position == 1)
            {
                sum += image[k][l].rgbtBlue;
            }
            else
            {
                sum += image[k][l].rgbtGreen;
            }
            counter++;
        }
    }

    return round(sum / counter);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, copy, 0);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, copy, 1);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, copy, 2);
        }
    }
}

int computeGx(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    int sumRed = 0, sumGreen = 0, sumBlue = 0;

    // For every pixel in 3 rows
    for (int k = i - 1; k < (i + 2); k++)
    {
        // For every pixel in 3 columns
        for (int l = j - 1; l < (j + 2); l++)
        {
            // If pixel is out of range of picture, skip turn and iterate to higher value
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }

            if ((k == i - 1 && l == j - 1) || (k == i + 1 && l == j - 1))
            {
                sumRed += image[k][l].rgbtRed * -1;
                sumGreen += image[k][l].rgbtGreen * -1;
                sumBlue += image[k][l].rgbtBlue * -1;
            }
            else if (k == i && l == j - 1)
            {
                sumRed += image[k][l].rgbtRed * -2;
                sumGreen += image[k][l].rgbtGreen * -2;
                sumBlue += image[k][l].rgbtBlue * -2;
            }
            else if (l == j)
            {
                sumRed += image[k][l].rgbtRed * 0;
                sumGreen += image[k][l].rgbtGreen * 0;
                sumBlue += image[k][l].rgbtBlue * 0;
            }
            else if ((k == i - 1 && l == j + 1) || (k == i + 1 && l == j + 1))
            {
                sumRed += image[k][l].rgbtRed * 1;
                sumGreen += image[k][l].rgbtGreen * 1;
                sumBlue += image[k][l].rgbtBlue * 1;
            }
            else if (k == i && l == j + 1)
            {
                sumRed += image[k][l].rgbtRed * 2;
                sumGreen += image[k][l].rgbtGreen * 2;
                sumBlue += image[k][l].rgbtBlue * 2;
            }
        }
    }

    if (color_position == 0)
    {
        return round(sumRed);
    }
    else if (color_position == 1)
    {
        return round(sumGreen);
    }
    else
    {
        return round(sumBlue);
    }
}

int computeGy(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    int sumRed = 0, sumGreen = 0, sumBlue = 0;

    // For every pixel in 3 rows (previous i - 1, pixel's row i and next row i + 1)
    for (int k = i - 1; k < (i + 2); k++)
    {
        // For every pixel in 3 columns for each row (previous j - 1, pixel's row j and next row j + 1)
        for (int l = j - 1; l < (j + 2); l++)
        {
            // If pixel is out of range of picture, skip turn and iterate to higher value
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }

            // [i][j] declares the position of pixel, by using i - 1, i, i + 1 etc. we are moving through rows and columns to calculate 3x3 boxes
            if ((k == i - 1 && l == j - 1) || (k == i - 1 && l == j + 1))
            {
                sumRed += image[k][l].rgbtRed * -1;
                sumGreen += image[k][l].rgbtGreen * -1;
                sumBlue += image[k][l].rgbtBlue * -1;
            }
            else if (k == i - 1 && l == j)
            {
                sumRed += image[k][l].rgbtRed * -2;
                sumGreen += image[k][l].rgbtGreen * -2;
                sumBlue += image[k][l].rgbtBlue * -2;
            }
            else if (k == i)
            {
                sumRed += image[k][l].rgbtRed * 0;
                sumGreen += image[k][l].rgbtGreen * 0;
                sumBlue += image[k][l].rgbtBlue * 0;
            }
            else if ((k == i + 1 && l == j - 1) || (k == i + 1 && l == j + 1))
            {
                sumRed += image[k][l].rgbtRed * 1;
                sumGreen += image[k][l].rgbtGreen * 1;
                sumBlue += image[k][l].rgbtBlue * 1;
            }
            else if (k == i + 1 && l == j)
            {
                sumRed += image[k][l].rgbtRed * 2;
                sumGreen += image[k][l].rgbtGreen * 2;
                sumBlue += image[k][l].rgbtBlue * 2;
            }
        }
    }

    if (color_position == 0)
    {
        return round(sumRed);
    }
    else if (color_position == 1)
    {
        return round(sumGreen);
    }
    else
    {
        return round(sumBlue);
    }
}

int compute_square(int gx, int gy)
{
    int pixelValue = 0;
    pixelValue = round(sqrt(pow(gx, 2) + pow(gy, 2)));

    if (pixelValue > 255)
    {
        pixelValue = 255;
    }

    return pixelValue;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Make copy of image to properly compute the value of pixel in 3x3 boxes
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = compute_square(computeGx(i, j, height, width, copy, 0), computeGy(i, j, height, width, copy, 0));
            image[i][j].rgbtBlue = compute_square(computeGx(i, j, height, width, copy, 2), computeGy(i, j, height, width, copy, 2));
            image[i][j].rgbtGreen = compute_square(computeGx(i, j, height, width, copy, 1), computeGy(i, j, height, width, copy, 1));
        }
    }
}
