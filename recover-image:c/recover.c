#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // prompt for 2 arguments
    if (argc != 2)
    {
        printf("usage: ./recover IMAGE\n");

        //echo-able output
        return 1;
    }

    //open file
    FILE *input_file = fopen(argv[1], "r");

    // checks for tangible file
    if (input_file == NULL)
    {
        printf("Could not open file");

        //echo-able output
        return 2;
    }

    // store 512 bytes of memory in an array
    unsigned char buffer[512];


    // image recover counter
    int image_count = 0;

    //assign pointer value
    FILE *output_file = NULL;


    // request memory for filename
    char *filename = malloc(8 * sizeof(char));

    //read function on bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //checks if JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (image_count > 0)
            {
                fclose(output_file);
            }

            //write names of files
            sprintf(filename, "%03i.jpg", image_count);

            // open output_file for writing
            output_file = fopen(filename, "w");

            //increment counter
            image_count++;

        }

        //checks to see if ouput was tangible input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    //frees memory used
    free(filename);
    fclose(output_file);
    fclose(input_file);

    //echo-able output
    return 0;


}