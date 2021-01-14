#include <stdlib.h>
#include <stdio.h>

#define VIRTUAL_MEMORY 4096
#define PHYSICAL_MEMORY 1024
#define BYTES_PER_FRAME 128

static unsigned int TABLE[] = {2, 4, 1, 7, 3, 5, 6, 0};

int main(int argc, char **argv) 
{
    if (argc < 3) 
    {
        return 1;
    }
        FILE *in, *out;
        unsigned long virtualAddress, convertedAddress;
	unsigned int d, p, f, offset;
        int total;

        if (!(in = fopen(argv[1], "rb"))) 
        {
            return 1;
        }

        if (!(out = fopen(argv[2], "wb"))) 
        {
            return 1;
        }

	    d = 7;
        total = 0;
        while (fread(&virtualAddress, sizeof (unsigned long), 1, in) == 1) 
        {
    	    offset = virtualAddress & 0x7F;
    	    p = virtualAddress >> d;
    	    f = TABLE[p];
    	    convertedAddress = (f << d) + offset;
            printf("The Logical Address is %-3lx and Translated Physical Address is %-3lx\n", virtualAddress, convertedAddress);
	        fwrite(&convertedAddress, sizeof (unsigned long), 1, out);
            total++;
        }
        fclose(in);
        fclose(out);
    return 0;
}