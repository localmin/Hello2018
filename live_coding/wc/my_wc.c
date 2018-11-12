#include <stdio.h>

int main(int argc, char **argv){
    char buf[4096];
    int nlines = 0;

    size_t nread;
    while((nread = fread(buf, 1, sizeof(buf), stdin)) > 0)
        for(size_t i = 0; i < nread; i++)
            if(buf[i] == '\n')
                nlines++;

    printf("%d\n", nlines);
    return 0;
}
