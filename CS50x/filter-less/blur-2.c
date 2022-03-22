void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgrgb[3] = {0,0,0}, n = 0;

            int a[3][3] = {
                {i-1, i-1, i-1},
                {i, i, i},
                {i+1, i+1,i+1}
                },

                b[3][3] = {
                {j-1, j, j+1},
                {j-1, j, j+1},
                {j-1, j, j+1}
                };

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (a[x][y] >= 0 && a[x][y] >= 0)
                    {
                        avgrgb[0] += image[a[x][y]][b[x][y]].rgbtRed;
                        avgrgb[1] += image[a[x][y]][b[x][y]].rgbtGreen;
                        avgrgb[2] += image[a[x][y]][b[x][y]].rgbtBlue;
                        n++;
                    }
                }
            }
            
            avgrgb[0] /= n;
            avgrgb[1] /= n;
            avgrgb[2] /= n;

            image[i][j].rgbtRed = avgrgb[0];
            image[i][j].rgbtGreen = avgrgb[1];
            image[i][j].rgbtBlue = avgrgb[2];
        }
    }
    return;
}