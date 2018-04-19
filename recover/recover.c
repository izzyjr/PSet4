#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "bmp.h"

    //open the card.raw file and check for null
    //read in 512 bytes from card.raw until EOF
        //if we find the header pattern of bytes
            //if we have found the first jpg
                //change the boolean value
                //write in the bytes into a separate file
            //else
                // close the previous file
                //write in the bytes into a new file
        //else
            //if we have found the first jpg
                //continue to to write the bytes
    //close all files and free the memory used
    //

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 0;
    }

    FILE *memory = fopen(argv[1], "r");
    if (memory == NULL)
    {
        fprintf(stderr, "Could not open.\n");
        return 0;
    }

    //read in 512 bytes from card.raw until EOF
    BYTE array[512];
    FILE* newJpg;
    bool jpgFound = false;
    int count = 0;

    while(fread(array, 1, 512, memory) != 0x00) {
        if(array[0] == 0xff && array[1] == 0xd8 && array[2] == 0xff && (array[3] & 0xf0) == 0xe0)
        {
            if (!jpgFound)
            {
                jpgFound = true;
                char fileName[8];
                sprintf(fileName, "%03i.jpg", count++);
                newJpg = fopen(fileName, "w");

                if(newJpg == NULL)
                {
                    return 0;
                }


                fwrite(array, 1, 512, newJpg);
            }
            else
            {
                fclose(newJpg);
                char fileName[8];
                sprintf(fileName, "%03i.jpg", count++);
                newJpg = fopen(fileName, "w");

                if(newJpg == NULL)
                {
                    return 0;
                }


                fwrite(array, 1, 512, newJpg);
            }
        }
        else
        {
            if(jpgFound)
            {
                fwrite(array, 1, 512, newJpg);
            }
        }
    }
    fclose(newJpg);
    fclose(memory);


}