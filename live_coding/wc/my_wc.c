#include <stdio.h>

int nlines = 0;

static void wc(FILE *in, char *filename){
    char buf[4096];
    int nl = 0;

    size_t nread;
    while((nread = fread(buf, 1, sizeof(buf), in)) > 0)
        for(size_t i = 0; i < nread; i++)
            if(buf[i] == '\n')
                nl++;

    if(filename)
        printf("%d %s\n", nl, filename);
    else
        printf("%d \n", nl);

    nlines += nl;

}

int main(int argc, char **argv){
    wc(stdin, "foo");
    printf("%d\n", nlines);
    return 0;
}
