#include <stdlib.h>
#include <stdio.h>

#define VIRTUAL_MEMORY 4096
#define PHYSICAL_MEMORY 1024
#define BYTES_PER_FRAME 128
#define TRUE 1
#define FALSE 0

int LRUPolicy()
int getAvailableFrame();

typedef struct 
{
	int valid;
	unsigned int fNum;
} Entry

static int CLOCK = 0;
static Entry TABLE[VIRTUAL_MEMORY / BYTES_PER_FRAME];
static int AVAILABLE_FRAMES[PHYSICAL_MEMORY / BYTES_PER_FRAME];
static int LRU[PHYSICAL_MEMORY / BYTES_PER_FRAME];
static int FRAME_TO_PAGES[PHYSICAL_MEMORY / BYTES_PER_FRAME];
static int PAGE_FAULTS = 0;


int main(int argc, char **argv) 
{
    if (argc < 3) 
    {
        return 1;
    }
        FILE *in, *out;
        unsigned long virtualAddress, convertedAddress;
	unsigned int d, p, f, offset;

        if (!(in = fopen(argv[1], "rb"))) 
        {
            return 1;
        }
        if (!(out = fopen(argv[2], "wb"))) 
        {
            return 1;
        }

    int i;
    for (i = 0; i < VIRTUAL_MEMORY / BYTES_PER_FRAME; i++) 
    {
        PAGE_TABLE[i].valid = FALSE;
    }
    for (i = 0; i < PHYSICAL_MEMORY / BYTES_PER_FRAME; i++) 
    {
        AVAILABLE_FRAMES[i] = TRUE;
    }
    for (i = 0; i < PHYSICAL_MEMORY / BYTES_PER_FRAME; i++) 
    {
        LRU[i] = 0;
    }
    for (i = 0; i < PHYSICAL_MEMORY / BYTES_PER_FRAME; i++) 
    {
        FRAME_TO_PAGES[i] = -1;
    }
    AVAILABLE_FRAMES[0] = FALSE;
	d = 7;
        totalPages = 0;
        while (fread(&virtualAddress, sizeof (unsigned long), 1, in) == 1) 
        {
            offset = virtualAddress & 0x7F;
            p = virtualAddress >> d;

            if (TABLE[p].valid) 
            {
                f = TABLE[p].fNum;
                convertedAddress = (f << d) + offset;
                LRU[f] = CLOCK;
            } 
            else 
            {
                int availableFrame;

                availableFrame = getavailableFrame();
                if (availableFrame > 0) 
                {
                    TABLE[p].valid = TRUE;
                    TABLE[p].fNum = (unsigned int) availableFrame;
                    AVAILABLE_FRAMES[availableFrame] = FALSE;
                    f = TABLE[p].fNum;
                    convertedAddress = (f << d) + offset;
                    LRU[f] = CLOCK;
                    FRAME_TO_PAGES[availableFrame] = p;
                } 
                else 
                {
                    int swappedFrame;
                    swappedFrame = LRUPolicy();
                    TABLE[FRAME_TO_PAGES[swappedFrame]].valid = FALSE;
                    TABLE[p].fNum = swappedFrame;
                    TABLE[p].valid = TRUE;
                    f = TABLE[p].fNum;
                    convertedAddress = (f << d) + offset;
                    LRU[f] = CLOCK;
                    FRAME_TO_PAGES[swappedFrame] = p;
                }
                PAGE_FAULTS++;
            }
        }
        fclose(in);
        fclose(out);
    return 0;
}

int LRUPolicy() 
{
    int i, leastRecent;

    leastRecent = 1;

    for (i = 1; i < PHYSICAL_MEMORY / BYTES_PER_PAGE; i++) 
    {
        if (LRU[i] < LRU[leastRecent]) 
        {
            leastRecent = i;
        }
    }
    return leastRecent;
}

int getAvailableFrame() 
{
    int i;

    for (i = 1; i < PHYSICAL_MEMORY / BYTES_PER_PAGE; i++) 
    {
        if (AVAILABLE_FRAMES[i] == TRUE) 
        {
            return i;
        }
    }
    return -1;
}