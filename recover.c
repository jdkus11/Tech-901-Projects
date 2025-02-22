#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    // Accept a single command-line argument
    if(argc != 2)
    {
        printf("Usage: ./recover FILE");
        return 1;
    }

    // Open the memory card
    FILE* card = fopen(argv[1], "r");  //Address to the file
    if(card == NULL)
    {
        printf("Could not open file: %s.\n", argv[1]);
        return 1;
    }

    //While there's still data left to read from the memory card
    const int block_size = 512;
    uint8_t buffer[block_size];
    int file_number = 000;
    char file_name[8];  //enough space for "###.jpg\0"
    FILE* jpg = NULL;   //temporary output file

    while(fread(&buffer, block_size, 1, card) == 1)     //
    {
        //Check to see if it's a JPEG
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(jpg != NULL)
            {
                fclose(jpg);   //Close the file you were working on
                file_number++;
            }
            sprintf(file_name, "%03i.jpg", file_number);
            jpg = fopen(file_name, "w");
        }
        if(jpg != NULL)
        {
        fwrite(buffer, block_size, 1, jpg);
        }

    }
    fclose(jpg);
    fclose(card);

}
