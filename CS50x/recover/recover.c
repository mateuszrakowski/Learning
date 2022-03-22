#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Correct usage: ./recover filename.raw\n");
        return 1;
    }

    char *fileName = argv[1];

    FILE *memoryCard = fopen(fileName, "r");
    if (memoryCard == NULL)
    {
        printf("Can't open file.\n");
        return 1;
    }

    BYTE buffer[512];
    int blockSize = 512;

    int counter = 0;

    char filename[8];

    FILE *img = fopen(filename, "w");

    while (fread(buffer, 1, blockSize, memoryCard) == blockSize)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, blockSize, img);

                counter++;
            }
            else
            {
                fclose(img);

                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, 1, blockSize, img);

                counter++;
            }
        }
        else
        {
            if (counter > 0)
            {
                fwrite(buffer, 1, blockSize, img);
            }
        }
    }

    fclose(img);
    fclose(memoryCard);
}