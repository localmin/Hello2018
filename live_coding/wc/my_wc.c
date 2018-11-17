#include <stdio.h>

int nlines = 0;

static void wc(FILE *in){
    char buf[4096];

    size_t nread;
    while((nread = fread(buf, 1, sizeof(buf), stdin)) > 0)
        for(size_t i = 0; i < nread; i++)
            if(buf[i] == '\n')
                nlines++;
}

int main(int argc, char **argv){
    wc(stdin);
    printf("%d\n", nlines);
    return 0;
}
