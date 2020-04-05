#include <stdio.h>
#include <stdlib.h>

char file_name[8];
FILE *jpg;
FILE *recoveryFile;
int file_number = 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Requires exactly one filename to recover.\n");
        return 1;
    }

    recoveryFile = fopen(argv[1], "r");

    if (recoveryFile == NULL)
    {
        printf("Error: the file specified will not open.\n");
        return 1;
    }

    unsigned char buffer[512];

    while (fread(buffer, 1, 512, recoveryFile) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpg == NULL)
            {
                sprintf(file_name, "%03i.jpg", file_number);
                jpg = fopen(file_name, "w");
                fwrite(buffer, 1, 512, jpg);
                fclose(jpg);
            }
            else
            {
                jpg = fopen(file_name, "r");
                fclose(jpg);
                file_number++;
                sprintf(file_name, "%03i.jpg", file_number);
                jpg = fopen(file_name, "w");
                fwrite(buffer, 1, 512, jpg);
                fclose(jpg);
            }
        }
        else
        {
            if (jpg != NULL)
            {
                jpg = fopen(file_name, "a");
                fwrite(buffer, 1, 512, jpg);
                fclose(jpg);
            }
        }
    }
}
